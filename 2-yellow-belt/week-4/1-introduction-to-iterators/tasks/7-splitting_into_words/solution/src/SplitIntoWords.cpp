#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector <string> words;

	//	���� �� ������
	for (auto it = begin(s); it != end(s); ++it) {
		//	����� ������� � ������������� [������� ������, ����� ������)
		auto resultIt = find(it, s.end(), ' ');
		//	������ ������ -> ��������� ����� � ������������� [������� ������, ������ �������)
		if (*resultIt == ' ') {
			words.push_back({it, resultIt});
			it = resultIt;
		}
		//	�������� - ��� -> ��������� ��� �������� � ������������� [������� ������, ����� ������)
		else {
			words.push_back({it, end(s)});
			break;
		}
	}
	return words;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}
