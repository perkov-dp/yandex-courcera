#include <set>
#include <string>
#include <iostream>
using namespace std;

/*
��� ����� �����. ������� ���������� ���������� ����� � ���� ������.

������ �����
������� �������� ���������� ����� N, ����� � ���� N �����, ���������� ��������. ��� ������ ������� ���� �� ��������� ����, ���� � �������� �������������.

������ ������
�������� ������������ ����� ����� � ���������� ���������� ����� � ������ ������.

������
����
6
first
second
first
third
second
second

�����
3
*/

int main()
{
	/*
	� ���������� ������������� ������������ ���������. 
	�� ���� �������� ������� ������� �� ����� ���� �������� � ���������.
	*/
	set <string> set_str;
	int kol_req = 0;
	cin >> kol_req;

	for (int i = 0; i < kol_req; i++)
	{
		string request;
		cin >> request;

		set_str.insert(request);
	}

	cout << set_str.size();

	return 0;
}

