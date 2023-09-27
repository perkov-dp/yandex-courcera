#include <cstdlib>
#include <locale>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVec(const vector<string>& vec)
{
    for (const auto& i: vec)
    {
        cout << i << ' ';
    }
    cout << endl;
}

/*
 * Сравнение строк
 * Переданные строки переводятся в происной регистр.
 * Затем сравниваются.
 * При этом исходные строки меняться не должны.
 */
bool cmpSymb (const string& first_val, const string& second_val)
{
    string new_first_val = first_val;
    string new_second_val = second_val;

    for (auto& ai: new_first_val) {
        ai = (char) tolower(ai);
    }
    for (auto& bi: new_second_val) {
        bi = (char) tolower(bi);
    }

    return new_first_val < new_second_val;
}

int main(int argc, char** argv) {
    int kol = 0;
    cin >> kol;
    vector <string> strs;
    
    for (int i = 0; i < kol; i++)
    {
        string str;
        cin >> str;
        strs.push_back(str);
    }
    
    //  принимает интервал и ф-я, на основании к-рой б/вып-ся сортировка 
    sort(begin(strs), end(strs), cmpSymb);
    printVec(strs);

    return 0;
}

