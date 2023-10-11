#include <iostream>
#include <vector>
#include <map>
#include <utility> // ��������� ������ ����������
using namespace std;

//	��� �������� ����� ������� ���������� ������� ��������������� ���������� ��������� ������� ����� ����� ���������� ���������.

// ��� ������� �����
template<typename T>
T Sqr(T value);

// ��� �������
template<typename T>
vector<T> Sqr(const vector<T>& value);

// ��� �������
template<typename First, typename Second>
map<First, Second> Sqr(const map<First, Second>& value);

// ��� ����
template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& value);
/////////////////////////////////////////////////////////////////////////////


//	��� ������� �����
template <typename T> // �������� ����� ��� ���������� ���� T
T Sqr(T x) {
	return x * x; // ��� �����, ����� ������� x ����������� �������� ���������
}

// ��� pair � ������� ����� �������� ������ ������� ����.
template <typename First, typename Second>
pair <First, Second> Sqr(const pair <First, Second>& p) {
	return {Sqr(p.first), Sqr(p.second)};
}

// ��� vector �������� ����� �������� � �������
template <typename T>
vector <T> Sqr(const vector<T>& vec) {
	vector<T> result;

	for (const auto& el : vec) {
		result.push_back(Sqr(el));
	}
	return result;
}

// ��� map � ������� ����� �������� ������ ��������, �� �� �����
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
