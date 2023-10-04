#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
 * �������� �-�, �-��� ���������� vector,
 * ��������� vector words � int minLength � ���������� ��� ������ �� ������� words,
 * �-��� �������� ������������ � ����� ����� �� ������ minLength.
 * ������� �-� �������� �� ����� 100 �����, ����� �-��� �������� ������ 100 ��������.
 *
 * �������� ������:
 * words			minLength	���-�
 * abacaba, aba		5			abacaba
 * abacaba, aba		2			abacaba, aba
 * weew, bro, code	4			weew
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

vector <string> PalindromFilter (vector <string> words, int minLength)
{
	vector <string> retWords;
	for (int i = 0; i < words.size(); i++)
	{
		//	����� ������ ����������� ����� � ��� �������� �����������
		if (words[i].size() >= minLength && IsPalindrom(words[i]))
		{
			retWords.push_back(words[i]);			
		}
	}

	return retWords;
}

int main()
{
	int vecSize = 0;
	int minLength = 0;
	cout << "Set vector size" << endl;
	cin >> vecSize;
	cout << "Set palindrom minLength" << endl;
	cin >> minLength;
	vector <string> words(vecSize);
	cout << "Set words vector" << endl;
	for (int i = 0; i < vecSize; i++)
	{
		cin >> words[i];
	}

	vector <string> word = PalindromFilter(words, minLength);
	for (int i = 0; i < word.size(); i++)
	{
		cout << word[i] << endl;
	}

	return 0;
}

