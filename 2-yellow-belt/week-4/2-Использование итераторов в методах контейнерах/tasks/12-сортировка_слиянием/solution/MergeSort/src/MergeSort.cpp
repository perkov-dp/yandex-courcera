#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	/* Часть 1. Реализация с разбиением на 2 части
	 * Алгоритм
	 * Классический алгоритм сортировки слиянием выглядит следующим образом:
	 * 1) Если диапазон содержит меньше 2 элементов, выйти из функции.*/
	if (range_end - range_begin < 2) {
		return;
	}
	//	2) Создать вектор, содержащий все элементы текущего диапазона.
	/*
	 * Подсказка
	 * Чтобы создать вектор, содержащий все элементы текущего диапазона (п. 2 алгоритма), необходимо уметь по типу итератора узнавать тип элементов,
	 * на которые он указывает. Если итератор RandomIt принадлежит стандартному контейнеру (вектору, строке, множеству, словарю...),
	 * нижележащий тип можно получить с помощью выражения typename RandomIt::value_type.
	 * Таким образом, гарантируется, что создать вектор в п. 2 можно следующим образом:
	 * vector<typename RandomIt::value_type> elements(range_begin, range_end); */
	vector<typename RandomIt::value_type> v(range_begin, range_end);

	/* 3) Разбить вектор на две равные части. (В этой задаче гарантируется, что длина передаваемого диапазона является степенью двойки,
	 * так что вектор всегда можно разбить на две равные части.) */
	auto it_mid = v.begin() + ((range_end - range_begin) / 2);	//	середина = начало + диапазон / 2

	//	4) Вызвать функцию MergeSort от каждой половины вектора.
	MergeSort(v.begin(), it_mid);
	MergeSort(it_mid, v.end());

	//	5) С помощью алгоритма std::merge слить отсортированные половины, записав полученный отсортированный диапазон вместо исходного.
	merge(v.begin(), it_mid, it_mid, v.end(), range_begin);
}

int main() {
	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
