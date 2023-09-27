#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printVec(const vector<int>& vec)
{
    for (const auto& i: vec)
    {
        cout << i << ' ';
    }
    cout << endl;
}

//  сравнение чисел по модулю
bool cmpOnModule (const int& first_val, const int& second_val)
{
    return (abs(first_val) < abs(second_val));
}

int main(int argc, char** argv) {
    int kol = 0;
    cin >> kol;
    vector <int> numbers;
    
    for (int i = 0; i < kol; i++)
    {
        int num = 0;
        cin >> num;
        numbers.push_back(num);
    }
    
    //  принимает интервал и ф-я, на основании к-рой б/вып-ся сортировка 
    sort(begin(numbers), end(numbers), cmpOnModule);
    printVec(numbers);

    return 0;
}

