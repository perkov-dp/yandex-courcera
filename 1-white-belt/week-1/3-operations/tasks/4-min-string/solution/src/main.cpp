#include <iostream>
#include <string>
using namespace std;

/*
� ����������� ������ ���� ��� ������, ���������� ��������. 
������ ������ ������� �� �������� ��������� ���� � ����� ����� �� ����� 30 ��������. 
�������� � ����������� ����� ����������������� ����������� �� ���.

����� ��� ���-�� ������������ ��� �-���, �� �� �������������� ��� �� ������ ����� �� �� �����
std::sort()
std::lexicographical_compare()

������� ������:
milk milkshake month	=> milk
c a b					=> a
fire fog wood			=> fire
*/

/*	������������ ��������� �� ������ ����������� ���� 
alpha beta gamma - min is first string		��
beta alpha gamma   - min is second string	��
beta gamma alpha - min is third string		��

2 ���������� ������
alpha beta alpha	������ �� �������. ������� ������� c < a && c < b. ��
beta alpha alpha	��
alpha alpha beta	������� beta. ������� ��������� ���������. ��

��� ������ ����������
gamma gamma gamma	��
*/

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	//	�������� ����������
	if (a <= b && a <= c){		//	��� alpha alpha beta �� ����������� ������� ���������. ������ 2 ��-�� ����������
		cout << a << endl;
	}
	else if (b <= a && b <= c){	//	��� alpha alpha beta alpha > beta => ������� 3 �������. ������
		cout << b << endl;
	}
	else {	//	else if (c < a && c < b) �� �����, �.�. ���� �� ����������� ���������� ������� => ���������� ���
		cout << c << endl;
	}
	/***********************/

	return 0;
}

