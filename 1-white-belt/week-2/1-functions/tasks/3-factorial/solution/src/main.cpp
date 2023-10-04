#include <iostream>
using namespace std;

/*
 * �������� �-�, �-��� ��������� � ���������� int.
 * ��������� int � ���������� ��������� ������ ���������.
 * �������������, ��� ���-� �-� �� ������ �� ��������� 10.
 * ��� ������������� ���-��� �-� �/���������� 1.
 * �������� ������:
 * 1  => 1
 * -2 => 1
 * 4  => 24
 */

int Factorial (int number)
{
	int factorial = 1;	//	���� � ����, �� ��������� ������ �/������ 0

	//	�������� ��������� ��� 0 � 1
	if (number == 0 || number == 1 || number < 0)
		return 1;
	for (int i = 1; i <= number; i++)
	{
		factorial *= i;
	}
	return factorial;
}

int main()
{
	int fact = 0, number = 0;
	cin >> number;
	fact = Factorial(number);
	cout << "���������: " << fact << endl;

	return 0;
}

