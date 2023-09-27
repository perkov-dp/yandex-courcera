#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Задача: вычислить целую часть от деления А на В.
 * Задаются целые числа от 0 до 1000000
 * Делить на 0 нельзя!
 * Тестировалось на след. данных:
 * 10 2 => 5
 * 3 5 => 0
 * 11 0 => Impossible
 */
int main(int argc, char** argv) {
    int a = 0, b = 0;
    cin >> a >> b;
    if (b == 0 || a < 0 || b < 0 || a > 1000000 || b > 1000000)
        cout << "Impossible" << endl;
    else
        cout << a/b << endl;
    
    return 0;
}

