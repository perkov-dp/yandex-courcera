#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	/* ����� 1. ���������� � ���������� �� 2 �����
	 * ��������
	 * ������������ �������� ���������� �������� �������� ��������� �������:
	 * 1) ���� �������� �������� ������ 2 ���������, ����� �� �������.*/
	if (range_end - range_begin < 2) {
		return;
	}
	//	2) ������� ������, ���������� ��� �������� �������� ���������.
	/*
	 * ���������
	 * ����� ������� ������, ���������� ��� �������� �������� ��������� (�. 2 ���������), ���������� ����� �� ���� ��������� �������� ��� ���������,
	 * �� ������� �� ���������. ���� �������� RandomIt ����������� ������������ ���������� (�������, ������, ���������, �������...),
	 * ����������� ��� ����� �������� � ������� ��������� typename RandomIt::value_type.
	 * ����� �������, �������������, ��� ������� ������ � �. 2 ����� ��������� �������:
	 * vector<typename RandomIt::value_type> elements(range_begin, range_end); */
	vector<typename RandomIt::value_type> v(range_begin, range_end);

	/* 3) ������� ������ �� ��� ������ �����. (� ���� ������ �������������, ��� ����� ������������� ��������� �������� �������� ������,
	 * ��� ��� ������ ������ ����� ������� �� ��� ������ �����.) */
	auto it_mid = v.begin() + ((range_end - range_begin) / 2);	//	�������� = ������ + �������� / 2

	//	4) ������� ������� MergeSort �� ������ �������� �������.
	MergeSort(v.begin(), it_mid);
	MergeSort(it_mid, v.end());

	//	5) � ������� ��������� std::merge ����� ��������������� ��������, ������� ���������� ��������������� �������� ������ ���������.
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
