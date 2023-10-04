#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
	//	отсортируем в-р дл€ того, чтобы из него м/было удалить идущие ѕќƒ–яƒ повтор€ющиес€ эл-ты
	sort(begin(elements), end(elements));

	// оставл€ем из подр€д идущих повторов только один элемент
	auto it = unique(begin(elements), end(elements));
	elements.erase(it, end(elements)); // удал€ем повтор€ющиес€, которые выкинуты в конец
}

int main() {
	vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
	RemoveDuplicates(v1);
	for (int x : v1) {
		cout << x << " ";
	}
	cout << endl;

	vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
	RemoveDuplicates(v2);
	for (const string& s : v2) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
