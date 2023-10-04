#include <iostream>
#include <vector>
#include <algorithm> // подключаем модуль с алгоритмами
using namespace std;

/*
 * Напишите функцию PrintVectorPart, принимающую вектор целых чисел numbers,
 * выполняющую поиск первого отрицательного числа в нём и выводящую в стандартный вывод все числа,
 * расположенные левее найденного, в обратном порядке.
 * Если вектор не содержит отрицательных чисел, выведите все числа в обратном порядке.
 */

void PrintVectorPart(const vector<int>& numbers) {
	auto result = find_if(
		begin(numbers), end(numbers),
		[](const int num) { // лямбда-функция по языкам
			return num < 0;
		}
	);

	//	вывод итераторов в обратном порядке
	while (result != begin(numbers)) { // нельзя делать --it от it = begin
		--result;
		cout << *result << " ";
	}
}

int main() {
	PrintVectorPart({6, 1, 8, -5, 4});
	cout << endl;
	PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
	cout << endl;
	PrintVectorPart({6, 1, 8, 5, 4});
	cout << endl;

	return 0;
}
