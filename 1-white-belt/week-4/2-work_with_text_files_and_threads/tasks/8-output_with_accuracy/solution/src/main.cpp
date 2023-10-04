#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>		//	���������� ��� ��������� �������������
using namespace std;

/*
� ����� input.txt �������� ������������ �����, �� ������ �� �������. 
�� ����������� ����� ����������� ��� ����� � ��� �� �������, �� ������ �� ������, 
�� �������� ���, ����� � �-�� �� ��� ���� ����� ��� ����� ����� ���������� �����.

������ ����� 1
5
0.34567
10.4

������ ������ 1
5.000
0.346
10.400

������ ����� 2
3.33353
3.333
3.3

������ ������ 2
3.334
3.333
3.300

����������: �������������� ������������ �������������� ������� ������.
*/

/*
������ ���� ��������� � ������� �� ����� �����������
��������� �� ���� ���� � �����
*/
void ExactlyOuputFile (const string& path)
{
	ifstream input (path);	//	��� ���������� ����� ������� �����
	double number = 0;

	//	������� ����� � ������������� ���������(fixed) � � 3 ������� ����� ������� (setprecision (3))
	cout << fixed << setprecision(3);

	//	���� ���� ����� � ������� �����
	while (input >> number)
	{
		cout << number << endl;
	}
}

int main()
{
	const string inpFilePath = "input.txt";
	ExactlyOuputFile(inpFilePath);

	return 0;
}

