#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 *  Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить
 *  в конец и уходить оттуда. 
 *  Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за
 *  того, что очередь не продвигается.

 *  Реализуйте обработку следующих операций над очередью:

 *  WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
 *  QUIET i: пометить i-го человека как успокоившегося;
 *  COME k: добавить k спокойных человек в конец очереди;
 *  COME -k: убрать k человек из конца очереди;
 *  WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
 *  Изначально очередь пуста.

 *  Формат ввода
 *  Количество операций Q, затем описания операций.

 *  Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i 
 *  существует в очереди на момент операции.

 *  Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.

 *  Формат вывода
 *  Для каждой операции WORRY_COUNT выведите одно целое число — количество 
 *  беспокоящихся людей в очереди.

 *  Пример

 *  Ввод
 *  8
 *  COME 5
 *  WORRY 1
 *  WORRY 4
 *  COME -2
 *  WORRY_COUNT
 *  COME 3
 *  WORRY 3
 *  WORRY_COUNT

 *  Вывод
 *  1
 *  2
 */

void worry (vector <bool>& queue, const int &worryIndex)
{
    queue[worryIndex] = 1;
}
void quiet (vector <bool>& queue, const int &quietIndex)
{
    queue[quietIndex] = 0;
}
void come (vector <bool>& queue, const int& kolQuietPeople)
{
    queue.resize(queue.size() + kolQuietPeople);
}
int worryCount (const vector <bool>& queue)
{
    int worryCount = 0;
    for (bool i : queue)
    {
        if (i == 1)
        {
            worryCount++;
        }
    }
    
    return worryCount;
}

int main(int argc, char** argv) {
    string command;
    int kolOperations = 0;
    vector <bool> queue;
    
    cout << "Введите ко-во операций, совершаемых с очередью: ";
    cin >> kolOperations;
    
    for (int i = 0; i < kolOperations; i++)
    {
        cout << "Введите команду: ";
        cin >> command;
        if (command == "COME")
        {
            int kolQuietPeople = 0;
            cout << "Введите сколько людей добавить в очередь: ";
            cin >> kolQuietPeople;
            come (queue, kolQuietPeople);
        }
        else if (command == "QUIET")
        {
            int indexQuietPerson = 0;
            cout << "Введите индекс беспокоющегося человека: ";
            cin >> indexQuietPerson;
            quiet (queue, indexQuietPerson);
        }
        else if (command == "WORRY")
        {
            int indexWorryPerson = 0;
            cout << "Введите индекс спокойного человека: ";
            cin >> indexWorryPerson;
            worry (queue, indexWorryPerson);
        }
        else if (command == "WORRY_COUNT")
        {
            cout << worryCount (queue);
        }        
    }

    return 0;
}

