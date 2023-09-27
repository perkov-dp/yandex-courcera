#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Напишите функцию MoveStrings, которая принимает два вектора строк, source и 
 * destination, и дописывает все строки из первого вектора в конец второго. 
 * После выполнения функции вектор source должен оказаться пустым.

 * Чтобы очистить содержимое вектора, надо вызвать у него метод clear:
 * vector<string> words = {"hey", "hi"};
 * words.clear();
 * // Теперь вектор words пуст

 * Пример
 * vector<string> source = {"a", "b", "c"};
 * vector<string> destination = {"z"};
 * MoveStrings(source, destination);
 * // source должен оказаться пустым
 * // destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
 */

void MoveStrings (vector<string>& source, vector<string>& destination)
{
    for (auto i : source)
    {
        destination.push_back(i);
    }
    source.clear();
}

int main(int argc, char** argv) {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for(auto i : source)
        cout << i << " ";
    cout << endl;
    for(auto i : destination)
        cout << i << " ";
    cout << endl;
    
    return 0;
}

