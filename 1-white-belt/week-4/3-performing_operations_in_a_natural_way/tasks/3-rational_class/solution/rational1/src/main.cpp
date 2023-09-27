#include <cstdlib>
#include <iostream>
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
        
        /*
         * Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь 
         * отрицательный числитель и положительный знаменатель.
         */
        if (numer / denumer < 0)
        {
            numer -= (2 * numer); //    или numer *= -1
        }
        /*
         * Если дробь p/q положительная, то объект Rational(p, q) должен иметь 
         * положительные числитель и знаменатель 
         * (обратите внимание на случай Rational(-2, -3)
         */
        else if (numer / denumer > 0)
        {
            if (numer < 0 && denumer < 0)
            {
                numer += (2 * numer);
                denumer += (2 * denumer);
            }
        }
        /*
         * Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
         */
        else if (numer == 0)
        {
            denumer = 1;
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return numer;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return denumer;
    }

private:
    // Числитель и знаменатель
    int numer;
    int denumer;

    int gcd (int a, int b)
    {
    	while (a > 0 && b > 0)
    	{
    	    if (a > b)
    	    {
    	        a = a % b;
    	    }
    	    else
    	    {
    	        b = b % a;
    	    }
    	}
    
    	return a + b;
    }
};

int main() {
    {        
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
