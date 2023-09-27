#include <cstdlib>
#include <iostream>
#include <exception>
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
        
        if (denominator == 0)
        {
            //  исключение недопустимого аргумента
            throw invalid_argument("The denominator must be greater than zero");
        }
        
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

//  числители и знаменатели умножаются
Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), 
            lhs.Denominator() * rhs.Denominator());
}

//  левая часть умножается на перевернутую правую
Rational operator / (const Rational& lhs, const Rational& rhs) {
    //  если знаменатель левой частиили числитель правой части 
    //  (т.к. дробь переворачивается) = 0 
    if (lhs.Denominator() == 0 || rhs.Numerator() == 0)
    {
        /* исключение ошибки домена (напр. ф-я квадратного корня определена т/для 
         * положительных чсел)
         * Отриц числа квалифицируются как ошибка домена
         */ 
        throw domain_error("Division by zero");
    }
    
    return Rational(lhs * Rational(rhs.Denominator(), rhs.Numerator()));
}

/*
 * 
 */
int main(int argc, char** argv) {
        try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;

    return 0;
}

