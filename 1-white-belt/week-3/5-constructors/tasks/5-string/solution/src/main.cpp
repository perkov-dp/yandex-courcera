#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Реализуйте класс ReversibleString, хранящий строку и 
 * поддерживающий методы Reverse для переворота строки и ToString для получения строки.
 * Вывод
 * evil
 * live
 * "" 
 */

class ReversibleString
{
public:
    ReversibleString(){};   //  конструктор по умолчанию 
    ReversibleString(const string& new_string) //  параметризованный конструктор
    {
        str = new_string;
    };
    string ToString() const //  константный метод получения строки
    {
        return str;
    };
    void Reverse()  //  метод переворота строки
    {
        reverse (str.begin(), str.end());   //  м/и так begin(data), end(data)
    };
    
private:
    string str;
};

int main(int argc, char** argv) {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}

