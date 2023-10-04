#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>	//	для решения квадратного ур-я

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

int SolveQuadradicEquation(double a, double b, double c) {
	// ... тут решение гарантированного квадратного уравнения
	double D = (b * b) - (4 * a * c);
	int root_count = 0;

	if (c == 0 || D > 0) {
		root_count = 2;
	} else if (D == 0) {
		root_count = 1;
	}
	else if ((a == 0 && c == 0) || (b == 0 && c == 0) || (D < 0)) {
		root_count = 0;
	}

	return root_count;
}
int SolveLinearEquation(double b, double c) {
	// b * x + c = 0
	if (b != 0) { // тут не забыли проверить деление на 0
		return 1;
	}
	return 0;
}

int GetDistinctRealRootCount(double a, double b, double c) {
	// Вы можете вставлять сюда различные реализации функции,
	// чтобы проверить, что ваши тесты пропускают корректный код
	// и ловят некорректный
	int realRootCount = 0;

	if (a != 0) { // точно знаем, что уравнение квадратное
		realRootCount = SolveQuadradicEquation(a, b, c);
	} else { // просто решаем линейное
		realRootCount = SolveLinearEquation(b, c);
	}
	return realRootCount;
}

void TestLinear() {
	AssertEqual (GetDistinctRealRootCount(0, 1, 2), 1, "Linear 1 root b != 0");
	AssertEqual (GetDistinctRealRootCount(0, 0, 2), 0, "Linear 0 root b == 0");
}

void TestQuadradic() {
	AssertEqual (GetDistinctRealRootCount(1, 2, 1), 1, "Quadradic 1 root D == 0");
	AssertEqual (GetDistinctRealRootCount(1, 2, 5), 1, "Quadradic 2 root D > 0");
	AssertEqual (GetDistinctRealRootCount(1, 2, 0), 1, "Quadradic 2 root c == 0");
	AssertEqual (GetDistinctRealRootCount(0, 2, 0), 1, "Quadradic 0 root a == 0 && c == 0");
	AssertEqual (GetDistinctRealRootCount(5, 0, 0), 1, "Quadradic 0 root b == 0 && c == 0");
	AssertEqual (GetDistinctRealRootCount(1, 1, 5), 1, "Quadradic 0 root D < 0");
}

int main() {
	TestRunner runner;
	// добавьте сюда свои тесты
	runner.RunTest(TestLinear, "TestLinear");
	runner.RunTest(TestLinear, "TestQuadradic");
	return 0;
}
