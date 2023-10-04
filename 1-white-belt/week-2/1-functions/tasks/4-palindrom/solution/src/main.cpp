#include <string>
#include <iostream>
using namespace std;

/*
 * �������� �-� IsPalindrom, �-��� ���������� bool � ��������� ���-� ���� string
 * � ����������, �������� �� ���������� ������ �����������.
 * ��������� - ����� ��� �����, �-��� ��������� �������� ����� ������� � ������ ������.
 * ������ ������ �������� �����������!!!
 * �������� ������:
 * madam => true
 * gentleman => false
 * X => true
 */

bool IsPalindrom (string word)
{
	//	���������� ������ ��-� � ���������, ������ � ������������� � �.�.
	for (int i = 0; i < word.length()/2; i++)
	{
		if (word[i] != word[word.length() - i - 1])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	string str;
	cin >> str;
	cout << IsPalindrom(str) << endl;

	return 0;
}

