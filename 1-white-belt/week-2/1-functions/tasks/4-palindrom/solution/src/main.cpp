#include <string>
#include <iostream>
using namespace std;

/*
 * Ќаписать ф-ю IsPalindrom, к-ра€ возвращает bool и принимает пар-р типа string
 * и возвращает, €вл€етс€ ли переданна€ строка палиндромом.
 * ѕалиндром - слово или фраза, к-рые одинаково читаютс€ слева направо и справа налево.
 * ѕуста€ строка €вл€етс€ палиндромом!!!
 * “естовые данные:
 * madam => true
 * gentleman => false
 * X => true
 */

bool IsPalindrom (string word)
{
	//	сравниваем первый эл-т с последним, второй с предпоследним и т.д.
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

