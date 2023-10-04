#include <cstdlib>
#include <iostream>
#include <exception>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Rational {
public:
    //  Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
    Rational() {
        numer = 0;
        denumer = 1;
    }

    //  При конструировании объека класса Rational с параметрами p и q должно
    //  выполняться сокращение дроби p/q
    //  (здесь вам может пригодиться решение задачи «Наибольший общий делитель»).
    Rational(int numerator, int denominator) {
        numer = numerator / gcd (numerator, denominator);
        denumer = denominator / gcd (numerator, denominator);

        if (denominator == 0) {
            //  исключение недопустимого аргумента
            throw invalid_argument("The denominator must be greater than zero");
        }

        /*
         * Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь
         * отрицательный числитель и положительный знаменатель.
         */
        if (numer / denumer < 0) {
            numer -= (2 * numer); //    или numer *= -1
        }
        /*
         * Если дробь p/q положительная, то объект Rational(p, q) должен иметь
         * положительные числитель и знаменатель
         * (обратите внимание на случай Rational(-2, -3)
         */
        else if ((numer / denumer > 0) && (numer < 0 && denumer < 0)) {
            numer += (2 * numer);
            denumer += (2 * denumer);
        }
        /*
         * Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
         */
        else if (numer == 0) {
            denumer = 1;
        }
    }

    int Numerator() const {
        return numer;
    }

    int Denominator() const {
        return denumer;
    }

private:
    // Числитель и знаменатель
    int numer;
    int denumer;

    int gcd (int a, int b) {
    	while (a > 0 && b > 0) {
    	    if (a > b) {
    	        a = a % b;
    	    } else {
    	        b = b % a;
    	    }
    	}

    	return a + b;
    }
};

bool operator == (const Rational& lhs, const Rational& rhs)
{
    return (lhs.Numerator() == rhs.Numerator()
            && lhs.Denominator() == rhs.Denominator());
}

//  числители и знаменатели умножаются
Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(),
            lhs.Denominator() * rhs.Denominator());
}

//  левая часть умножается на перевернутую правую
Rational operator / (const Rational& lhs, const Rational& rhs) {
    //  если знаменатель левой части или числитель правой части
    //  (т.к. дробь переворачивается) = 0
    if (lhs.Denominator() == 0 || rhs.Numerator() == 0) {
        /* исключение ошибки домена (напр. ф-я квадратного корня определена т/для
         * положительных чсел)
         * Отриц числа квалифицируются как ошибка домена */
        throw domain_error("Division by zero");
    }

    return Rational(lhs * Rational(rhs.Denominator(), rhs.Numerator()));
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

void Test() {
    {
    	//	несокращаемая дробь -> 3/10
        const Rational r(3, 10);
        AssertEqual(r.Numerator(), 3, "3/10");
        AssertEqual(r.Denominator(), 10, "3/10");
    }

    {
    	//	сокращаемая дробь -> 2/3
        const Rational r(8, 12);
        AssertEqual(r.Numerator(), 2, "8/12");
        AssertEqual(r.Denominator(), 3, "8/12");
    }

    {
    	//	сокращаемая дробь с отрицательным числителем -> -2/3
        const Rational r(-4, 6);
        AssertEqual(r.Numerator(), -2, "-4/6");
        AssertEqual(r.Denominator(), 3, "-4/6");
    }

    {
    	//	сокращаемая дробь с отрицательным знаменателем -> по заданию знак переносится в числитель -> -2/3
        const Rational r(4, -6);
        AssertEqual(r.Numerator(), -2, "4/-6");
        AssertEqual(r.Denominator(), 3, "4/-6");
    }

    {
    	//	числитель 0 -> по заданию знаменатель 1 -> 0/1
        const Rational r(0, 15);
        AssertEqual(r.Numerator(), 0, "0/15");
        AssertEqual(r.Denominator(), 1, "0/15");
    }

    {
    	//	конструктор по умолчанию создает дробь с числителем 0 и знаменателем 1 -> 0/1
        const Rational defaultConstructed;
        AssertEqual(defaultConstructed.Numerator(), 0, "0/1");
        AssertEqual(defaultConstructed.Denominator(), 1, "0/1");
    }
}

int main() {
	TestRunner runner;
	runner.RunTest(Test, "TestRational");

	return 0;
}
