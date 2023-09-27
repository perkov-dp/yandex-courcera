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

    //  НОД
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

//  числители и знаменатели умножаются
Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), 
            lhs.Denominator() * rhs.Denominator());
}

//  левая часть умножается на перевернутую правую
Rational operator / (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs * Rational(rhs.Denominator(), rhs.Numerator()));
}

bool operator == (const Rational& lhs, const Rational& rhs)
{
    return (lhs.Numerator() == rhs.Numerator() 
            && lhs.Denominator() == rhs.Denominator());
}

/*
 * 
 */
int main(int argc, char** argv) {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;

    return 0;
}

