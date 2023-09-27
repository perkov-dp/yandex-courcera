#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Реализуйте класс, поддерживающий набор строк в отсортированном порядке. 
 * Класс должен содержать два публичных метода.
 * 
 * Вывод:
 * first second third
 * first second second third
 */ 

class SortedStrings {
public:
    // добавить строку s в набор
    void AddString(const string& s) 
    {
        strings.push_back(s);
    }
    // получить набор из всех добавленных строк в отсортированном порядке
    vector<string> GetSortedStrings() 
    {
        sort(strings.begin(), strings.end());
        return strings;       
    }
private:
    // приватные поля
    vector <string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}


int main(int argc, char** argv) {
    SortedStrings strings;
  
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
  
    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}

