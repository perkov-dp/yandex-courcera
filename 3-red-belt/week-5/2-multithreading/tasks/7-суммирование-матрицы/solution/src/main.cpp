#include "test_runner.h"
#include "paginator.h"
#include <vector>
#include <algorithm>
#include <future>
using namespace std;

template <typename ContainerOfVectors>
int64_t SumSingleThread(const ContainerOfVectors& matrix) {
  int64_t sum = 0;
  for (const auto& row : matrix) {
    for (const auto& el : row) {
      sum += el;
    }
  }
  return sum;
}

int64_t CalculateMatrixSum(const vector<vector<int>>& matrix) {
  int64_t sum = 0;
  vector<future<int64_t>> futures;
  constexpr size_t page_size = 2000;
  for (auto page : Paginate(matrix, page_size)) {
    futures.push_back(
      async([&sum, page] {
        return SumSingleThread(page);
      })
    );
  }

  for (auto& future : futures) {
      sum += future.get();
  }

  return sum;
}

void TestCalculateMatrixSum() {
  const vector<vector<int>> matrix = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  ASSERT_EQUAL(CalculateMatrixSum(matrix), 136);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestCalculateMatrixSum);
}
