#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#include "Query.h"

int main() {
	vector<Query> operations;
	Query q;


	//	считываем изначальное выр-е, состоящее из целого числа
	int init_number = 0;
	cin >> init_number;

	//	1) считали все и записали
	{
		//	считываем кол-во операций
		size_t operations_count = 0;
		cin >> operations_count;

		//	считываем операции
		for (size_t i = 0; i < operations_count; i++) {
			cin >> q;
			operations.push_back(q);
		}
	}

	//	2) составляем строку - арифметическое дерево
	{
		/*
		 * Для примера (((8) * 3) - 6) / 1 порядок вывода такой:
		 * 1) 8
		 * 2) (...)<пробел>*<пробел>3 -> (8) * 3
		 * 3) (...)<пробел>-<пробел>6 -> ((8) * 3) - 6
		 * 4) (...)<пробел>/<пробел>1 -> (((8) * 3) - 6) / 1
		 */
		deque<string> d;
		d.push_back(to_string(init_number));

		for (const auto& op : operations) {
			d.push_front("(");
			d.push_back(")");
			d.push_back(" ");
			d.push_back(op.operation);
			d.push_back(" ");
			d.push_back(op.number);
		}

		for (const auto& deque : d) {
			cout << deque;
		}
	}

	return 0;
}
