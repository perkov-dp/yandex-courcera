#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

/*
 * Реализуйте функцию void Reverse(vector<int>& v), 
 * которая переставляет элементы вектора в обратном порядке.

 * Пример
 * vector<int> numbers = {1, 5, 3, 4, 2};
 * Reverse(numbers);
 * // numbers должен оказаться равен {2, 4, 3, 5, 1}
 */

void Swap(int& x, int& y) 
{
    int tmp = x;
    x = y;
    y = tmp;
}


void Reverse(vector<int>& v)
{
    vector <int> tmpVec = v;
    for (int i = 0; i < tmpVec.size(); i++)
        swap (v[i], tmpVec[tmpVec.size() - i - 1]);
}

int main(int argc, char** argv) {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (auto i: numbers)
        cout << i << " ";
    
    return 0;
}

