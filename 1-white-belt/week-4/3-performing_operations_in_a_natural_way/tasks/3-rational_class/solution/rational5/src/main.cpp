#include <cstdlib>
#include <set>
#include <map>
#include <iostream>
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

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}


/*
 * 
 */
int main(int argc, char** argv) {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;

    return 0;
}

