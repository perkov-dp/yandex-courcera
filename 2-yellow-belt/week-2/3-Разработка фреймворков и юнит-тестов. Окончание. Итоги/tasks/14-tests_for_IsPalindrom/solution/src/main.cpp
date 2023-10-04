#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& str) {
	/*
	 * Пустая строка является палиндромом!!!
	 * Тестовые данные:
	 * madam => true
	 * gentleman => false
	 * X => true
	 */

	/*
	 * 	- считает пустую строку палиндромом;
	 *	- считает строку из одного символа палиндромом;
	 *	- осуществляет обычное сравнение символов на равенство, не игнорируя никакие символы, в том числе пробельные.
	 *
	 *	При разработке тестов подумайте, какие ошибки можно допустить при реализации функции IsPalindrom. Примеры ошибок:
	 *	- игнорируется первый или последний символ;
	 *	- сравнение соответствующих символов завершается не в середине строки, а раньше;
	 *	- игнорируются пробелы
	 */
    for (size_t i = 0; i < str.size() / 2; ++i) {
    	//	сравниваем первый эл-т с последним, второй с предпоследним и т.д.
        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void TestPalindrome() {
	AssertEqual (IsPalindrom("madam"), true, "madam");
	AssertEqual (IsPalindrom("gentleman"), false, "gentleman");
	AssertEqual (IsPalindrom("X"), true, "one symbol string");
	AssertEqual (IsPalindrom(" "), true, "Space symbol");
	AssertEqual (IsPalindrom(""), true, "empty string");
	AssertEqual (IsPalindrom("abba"), true, "abba");
	AssertEqual (IsPalindrom(" abba "), true, " abba ");
	AssertEqual (IsPalindrom(" a b b a "), true, " a b b a ");
	AssertEqual (IsPalindrom(" a b b a"), false, " a b b a");
}

int main() {
	TestRunner runner;
	runner.RunTest(TestPalindrome, "TestPalindrome");
	return 0;
}
