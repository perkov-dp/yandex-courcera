#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

/*
 * Реализуйте функцию vector<int> Reversed(const vector<int>& v), 
 * возвращающую копию вектора v, в которой числа переставлены в обратном порядке.

 * Пример:
 * Вектор v		Результат функции
 * 1, 5, 3, 4, 2	2, 4, 3, 5, 1
 */

/* Решение преподавателя
 * vector<int> Reversed(const vector<int>& input)
 * {
       vector<int> result;
       for (int i = input.size() - 1; i >= 0; --i) {
           result.push_back(input[i]);
       }
       return result;
 * }
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

vector<int> Reversed(const vector<int>& v)
{
    vector <int> revVec = v;
    Reverse(revVec);
    
    return revVec;
}

int main(int argc, char** argv) {
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> revNumbers;
    revNumbers = Reversed(numbers);
    for (auto i: revNumbers)
        cout << i << " ";
   
    return 0;
}

