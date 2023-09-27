#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*  
 * Задача: вычислить корни квадратного ур-я.
 * Рассматривается случай, когда a = 0
 * И еще важно чтобы тип был с плавающей точкой
 * Тестировалось на след. данных:
 * 2 5 2  => -0.5 -2
 * 2 4 2  => -1
 * 2 1 2  =>
 * 0 4 10 => -2.5
 * Подсказка: Для вычисления квадратного корня используйте функцию sqrt из библиотеки cmath. 
 * Чтобы подключить библиотеку, в начале программы напишите #include <cmath>
 */
int main(int argc, char** argv) {
    float A = 0, B = 0, C = 0;
    float descr = 0;
    float x1 = 0, x2 = 0;
    cin >> A >> B >> C;
    
    if (A)
    {
        descr = B*B - 4*A*C;
        if (descr == 0)
        {
            cout << "X = " << -B/(2*A);
        }
        else if (descr < 0)
        {
            cout << "корней нет" << endl;
        }
        else 
        {
            x1 = -B/(2*A) + sqrt(descr)/(2*A);
            x2 = -B/(2*A) - sqrt(descr)/(2*A);
            cout << "X1 = " << x1 << " X2 = " << x2 << endl;
        }        
    }
    else
    {
        x1 = -C/B;
        cout << "x = " << x1 << endl;
    }

    

    return 0;
}

