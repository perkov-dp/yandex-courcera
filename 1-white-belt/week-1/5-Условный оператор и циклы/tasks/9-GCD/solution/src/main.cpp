#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * На ввод подаются 2 натуральных числа. Выведите их НОД.
 * Тестовые данные:
 * 25 27 => 1
 * 12 16 => 4
 * 13 13 => 13
 */
int main(int argc, char** argv) {
    int a = 0, b = 0;
    cin >> a >> b;
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }else{
            b = b % a;
        }
    }
    cout << a + b << endl;
    
    return 0;
}

