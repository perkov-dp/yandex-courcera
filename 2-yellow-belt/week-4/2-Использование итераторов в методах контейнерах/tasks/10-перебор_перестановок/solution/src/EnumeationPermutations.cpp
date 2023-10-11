#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

/*
 * ���� ����� ������������� ����� N, �� ����������� 9.
 * �������� ��� ������������ ����� �� 1 �� N � �������� ������������������ ������� (��. ������).

 * ������
 * ����
 * 3

 * �����
 * 3 2 1
 * 3 1 2
 * 2 3 1
 * 2 1 3
 * 1 3 2
 * 1 2 3

 * ���������
 * ���������� <algorithm> �������� ������� �������, ����������� ������ ��� ������.
 */
//	�������� ������ ��� vector
template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;	//	����� ������� ������ ����� ������� ��-��
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

//	�������� ������ ��� set
template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;	//	����� ������� ������ ����� ������� ��-��
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

//	�������� ������ ��� map
template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;	//	����� ������� ������ ����� ������� ��-��
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

	//	�������� �������� � �������� ������������������ �������
	sort(begin(perm), end(perm), greater<T>());

	/* ����������� �������� � ���������� (�����������������) ������������,
	 * ���� ��� ���������� � ���������� true,
	 * ����� ���������� false � ����������� �������� �������� � ��������� (����������) ������������ */
	do {
		cout << perm << endl;
	}
	while (prev_permutation(begin(perm), end(perm)));
}

int main() {
	Permutation(3);
	return 0;
}
