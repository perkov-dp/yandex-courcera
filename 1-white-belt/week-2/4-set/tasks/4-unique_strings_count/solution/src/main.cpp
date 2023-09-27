#include <set>
#include <string>
#include <iostream>
using namespace std;

/*
Дан набор строк. Найдите количество уникальных строк в этом наборе.

Формат ввода
Сначала вводится количество строк N, затем — сами N строк, разделённые пробелом. Все строки состоят лишь из латинских букв, цифр и символов подчёркивания.

Формат вывода
Выведите единственное целое число — количество уникальных строк в данном наборе.

Пример
Ввод
6
first
second
first
third
second
second

Вывод
3
*/

int main()
{
	/*
	В множествах гарантируется уникальность элементов. 
	То есть повторно никакой элемент не может быть добавлен в множество.
	*/
	set <string> set_str;
	int kol_req = 0;
	cin >> kol_req;

	for (int i = 0; i < kol_req; i++)
	{
		string request;
		cin >> request;

		set_str.insert(request);
	}

	cout << set_str.size();

	return 0;
}

