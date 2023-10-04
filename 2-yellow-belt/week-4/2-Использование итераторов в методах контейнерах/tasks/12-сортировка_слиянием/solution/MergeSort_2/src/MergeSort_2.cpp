#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename It> // написали шаблонную функцию
void PrintRange(It range_begin , // поменяли здесь на шаблон итератора
	It range_end) { // и тут
	for (auto it = range_begin; it != range_end; ++it) {
		cout << *it << " ";
	}
}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	/* Часть 2. Реализация с разбиением на 3 части
	 * Реализуйте сортировку слиянием, разбивая диапазон на 3 равные части, а не на 2.
	 * Гарантируется, что длина исходного диапазона является степенью 3.
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

	/* Соответственно, пункты 3–5 алгоритма нужно заменить следующими:
	 * 3) Разбить вектор на 3 равные части. */
	auto it_third_1 = v.begin() + ((range_end - range_begin) / 3);	// 1 треть = начало + диапазон / 3
	auto it_third_2 = it_third_1 + ((range_end - range_begin) / 3);	// 2 треть =  1 треть + диапазон / 3

	//	4) Вызвать функцию MergeSort от каждой части вектора.
	MergeSort(v.begin(), it_third_1);
	MergeSort(it_third_1, it_third_2);
	MergeSort(it_third_2, v.end());

	//	5) Слить первые две трети вектора с помощью алгоритма merge, сохранив результат во временный вектор с помощью back_inserter.
	vector<typename RandomIt::value_type> tmp_v;
	merge(v.begin(), it_third_1, it_third_1, it_third_2, back_inserter(tmp_v));	//	back_inserter() делает push_back ко временному в-ру

	/* 6) Слить временный вектор из предыдущего пункта с последней третью вектора из п. 2,
	 * записав полученный отсортированный диапазон вместо исходного. */
	merge(tmp_v.begin(), tmp_v.end(), it_third_2, v.end(), range_begin);
}

int main() {
	vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
