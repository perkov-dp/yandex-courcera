#include <cstdlib>
#include <exception>
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
        if (denominator == 0)
        {
            //  исключение недопустимого аргумента
            throw invalid_argument("The denominator must be greater than zero");
        }
        
        numer = numerator / gcd (numerator, denominator);
        denumer = denominator / gcd (numerator, denominator);

        //	если знаменатель отрицательный, то числитель становится отрицательным, а знаменатель - положительным
        if (denumer < 0) {
        	denumer *= -1;
            numer *= -1;
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
    	//	если одно из чисел = 0, то их НОД = второму числу
    	//	GCD(0, b) = b
    	//	GCD(a, b) = GCD(b, a)
    	if (b == 0) {
    		return a;
    	}
    	//	GCD(a, b) = GCD(b, a mod b)
    	else {
    		return gcd(b, a % b);
    	}
    }
};

/*  
 * числ. одной дроби умножается на знам. др. дроби
 * то же самое для др. дроби
 * это все складывается => получаем общий числитель
 * знаменатели перемножаются
 */
Rational operator + (const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator()
            + rhs.Numerator() * lhs.Denominator(), 
            lhs.Denominator() * rhs.Denominator());
}

Rational operator - (const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator() 
            - rhs.Numerator() * lhs.Denominator(), 
            lhs.Denominator() * rhs.Denominator());
}

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
    //if (stream.tellg() != -1) {
        stream >> numerator;
        stream.ignore(1);
        stream >> denominator;

        //  создание объекта на основании считанных данных
        rational = Rational(numerator, denominator);
    //}
    return stream;
}

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
        Rational r1, r2, r3;
        char c;
        cin >> r1 >> c >> r2;

        if (c == '+')
        {
            r3 = r1 + r2;
        }
        if (c == '-')
        {
            r3 = r1 - r2;
        }
        if (c == '*')
        {
            r3 = r1 * r2;
        }
        if (c == '/')
        {
            r3 = r1 / r2;
        }

        cout << r3 << endl;
    } catch (invalid_argument&) {
        cout << "Invalid argument";
    } catch (domain_error&) {
        cout << "Division by zero";
    }

    return 0;
}

