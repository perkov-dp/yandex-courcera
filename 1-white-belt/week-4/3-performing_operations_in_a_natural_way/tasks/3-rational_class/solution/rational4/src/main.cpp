#include <cstdlib>
#include <iostream>
#include <sstream>
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

bool operator == (const Rational& lhs, const Rational& rhs)
{
    return (lhs.Numerator() == rhs.Numerator() 
            && lhs.Denominator() == rhs.Denominator());
}

ostream& operator<<(ostream& stream, const Rational& rational) 
{
    stream << rational.Numerator() << '/' << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) 
{
    int numerator = 0;
    int denominator = 0;
    
    //  Проверка текущего положения ук-ля ввода иначе вылетает
    if (stream.tellg() != -1) {
        stream >> numerator;
        stream.ignore(1);
        stream >> denominator;

        //  создание объекта на основании считанных данных
        rational = Rational(numerator, denominator);
    }
    return stream;
}


/*
 * 
 */
int main(int argc, char** argv) {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;

    return 0;
}

