#include <iostream>
#include <vector>

using namespace std;

#include <limits> // подключаем для получения информации о типе

int main() {
	unsigned n;	//	Гарантируется, что N не превышает миллиона (10^6)
	cin >> n;
	vector<int> temperatures(n);	//	−10^8 до 10^8

	int64_t sum = 0;	//	Сумма температур может достигать 10^14 (temperatures = 10^8 * n = 10^6)
	for (auto& temperature : temperatures) {
		cin >> temperature;
		sum += temperature;
	}
	//	приводим temperatures.size() к знаковому типу int.
	//	Результат вычисления средней температуры приведется к int64_t, т.к. sum имеет тип int64_t.
	//	Но резульат будет int, поэтому нужно привести к типу int результат всего выражения
	int average = static_cast<int>(sum / static_cast<int>(temperatures.size()));

	vector<int> result_indices;
	for (size_t i = 0; i < temperatures.size(); ++i) {
		if (temperatures[i] > average) {
			result_indices.push_back(i);
		}
	}

	cout << result_indices.size() << endl;
	for (int& result_index : result_indices) {
		cout << result_index << " ";
	}
	cout << endl;

	return 0;
}
