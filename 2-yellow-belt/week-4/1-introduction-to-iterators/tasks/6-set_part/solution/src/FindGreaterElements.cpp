#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
using namespace std;

/*
 * Напишите шаблонную функцию FindGreaterElements, принимающую множество elements объектов типа T и ещё один объект border типа T и
 * возвращающую вектор из всех элементов множества, больших border, в возрастающем порядке.
 * template <typename T>
 * vector<T> FindGreaterElements(const set<T>& elements, const T& border);
 */

/*
 * Рещение задачи сводится к поиску первого эл-та в множестве, большему чем border.
 * А т.к. множество уже отстортировано, то нужно вернуть все последующие за ним эл-ты.
 */

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	auto resultIt = find_if(
		elements.begin(), elements.end(),
		[border](T el) {	//	Чтобы сообщить, что переменную следует взять из контекста как раз используются квадратные скобки.
			return el > border;
	    }
	);

	return {resultIt, elements.end()};
}

int main() {
	  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
	    cout << x << " ";
	  }
	  cout << endl;

	  string to_find = "Python";
	  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;

	return 0;
}
