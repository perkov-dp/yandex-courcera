#include <cstdlib>
#include <string>
#include <iostream>
#include <exception>
using namespace std;

void EnsureEqual(const string& left, const string& right)
{
    if (left != right)
    {
        //  исключение с текстом ошибки
        throw runtime_error(left + " != " + right);
    }
}

int main(int argc, char** argv) {
    //  вып-ся опасный кусок кода
    try 
    {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    }
    //  ксли было исключение, оно здесь обрабатывается
    catch (runtime_error& e) 
    {
      //  what() извлекает текст ошибки
      cout << e.what() << endl;
    }

    return 0;
}

