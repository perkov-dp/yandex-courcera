#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Дана строка. Найдите в этой строке второе вхождение буквы f и выведите индекс
 * этого вхождение. Если буква f в данной строке встречается т/один раз, 
 * выведите число -1, а если не встречается, выведите число -2. 
 * Индексы нумеруются с нуля.
 * 
 * Тестовые данные:
 * comfort => -1
 * coffee  => 3
 * car     => -2
 */
int main(int argc, char** argv) {
    string str;
    cin >> str;
    int count = 0;
    int firstOccurence = 0;
    int secondOccurence = 0;
    
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'f')
        {
             count++;
             if (count == 1)
             {
               firstOccurence = i;  
             }
             if (count == 2)
             {
                 secondOccurence = i;
                 break;
             }
        }
    }
    if (count == 1)
        cout << "-1" << endl;
    else if (count == 2)
         cout << secondOccurence << endl;
    else if(count == 0)
        cout << "-2" << endl;
    
    
    return 0;
}

