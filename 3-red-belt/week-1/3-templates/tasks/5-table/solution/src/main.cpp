#include "test_runner.h"

using namespace std;

// Реализуйте здесь шаблонный класс Table
template<typename T>
class Table {
  public:
    Table(size_t rows, size_t columns) {
      Resize(rows, columns);
    };

    vector<T>& operator[] (size_t indx) {
      return _data[indx];
    }

    vector<T>& operator[] (size_t indx) const {
      return _data[indx];
    }

    void Resize(size_t rows, size_t columns) {
      _data.resize(rows);
      for (auto& item : _data) {
        item.resize(columns);
      }
    }

    pair<size_t, size_t> Size() const {
      return {_data.size(), (_data.empty() ? 0 : _data[0].size())};
    }
  private:
    vector<vector<T>> _data;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
