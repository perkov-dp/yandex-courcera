#include <iostream>
#include <vector>
#include <map>
#include <utility> // добавл€ем нужную библиотеку
using namespace std;

//	ƒл€ успешной сдачи решени€ необходимо сделать предварительное объ€вление шаблонных функций перед всеми шаблонными функци€ми.

// ƒл€ простых типов
template<typename T>
T Sqr(T value);

// ƒл€ вектора
template<typename T>
vector<T> Sqr(const vector<T>& value);

// ƒл€ словар€
template<typename First, typename Second>
map<First, Second> Sqr(const map<First, Second>& value);

// ƒл€ пары
template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& value);
/////////////////////////////////////////////////////////////////////////////


//	дл€ простых типов
template <typename T> // ключевое слово дл€ объ€влени€ типа T
T Sqr(T x) {
	return x * x; // нам нужно, чтобы элемент x поддерживал операцию умножени€
}

// дл€ pair в квадрат нужно возвести каждый элемент пары.
template <typename First, typename Second>
pair <First, Second> Sqr(const pair <First, Second>& p) {
	return {Sqr(p.first), Sqr(p.second)};
}

// дл€ vector элементы нужно возвести в квадрат
template <typename T>
vector <T> Sqr(const vector<T>& vec) {
	vector<T> result;

	for (const auto& el : vec) {
		result.push_back(Sqr(el));
	}
	return result;
}

// дл€ map в квадрат нужно возвести только значени€, но не ключи
template <typename First, typename Second>
map <First, Second> Sqr(const map<First, Second>& m) {
	map<First, Second> result;

	for (const auto& el : m) {
		result[el.first] = Sqr(el.second);
	}
	return result;
}


int main() {
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

	return 0;
}
