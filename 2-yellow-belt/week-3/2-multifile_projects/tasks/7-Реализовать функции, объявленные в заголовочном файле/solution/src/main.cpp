#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Sum(int x, int y) {
	return x + y;
}

string Reverse(string s) {
	string result;
	//	цикл с конца с защитой от пустой строки
	for (size_t k = s.size(); k > 0 ; --k) {
		size_t i = k - 1;
		result.push_back(s[i]);
    }
    return result;
}

void Sort(vector<int>& nums) {
	sort(begin(nums), end(nums));
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << Reverse("Hello") << endl;
}
