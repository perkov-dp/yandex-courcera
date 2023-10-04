#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

/*
 * Дано целое положительное число N, не превышающее 9.
 * Выведите все перестановки чисел от 1 до N в обратном лексикографическом порядке (см. пример).

 * Пример
 * Ввод
 * 3

 * Вывод
 * 3 2 1
 * 3 1 2
 * 2 3 1
 * 2 1 3
 * 1 3 2
 * 1 2 3

 * Подсказка
 * Библиотека <algorithm> содержит готовые функции, позволяющие решить эту задачу.
 */
//	оператор вывода для vector
template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;	//	вывод запятой только после первого эл-та
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

//	оператор вывода для set
template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;	//	вывод запятой только после первого эл-та
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

//	оператор вывода для map
template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;	//	вывод запятой только после первого эл-та
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<typename T>
void Permutation(T N) {
	vector<T> perm;
	for (T i = 1; i <= N; i++) {
		perm.push_back(i);
	}

	//	сортирую элементы в обратном лексикографическом порядке
	sort(begin(perm), end(perm), greater<T>());

	/* преобразует диапазон в предыдущую (лексикографически) перестановку,
	 * если она существует и возвразает true,
	 * иначе возвращает false и преобразует диапазон диапазон в последнюю (наибольшую) перестановку */
	do {
		cout << perm << endl;
	}
	while (prev_permutation(begin(perm), end(perm)));
}

int main() {
	Permutation(3);
	return 0;
}
