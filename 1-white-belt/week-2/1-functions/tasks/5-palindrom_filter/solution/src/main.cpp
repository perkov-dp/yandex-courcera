#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
 * Ќапишите ф-ю, к-ра€ возвращает vector,
 * принимает vector words и int minLength и возвращает все строки из вектора words,
 * к-рые €вл€ютс€ палиндромами и имеют длину не меньше minLength.
 * ¬ходной в-р содержит не более 100 строк, длина к-дой строкине больше 100 символов.
 *
 * “естовые данные:
 * words			minLength	рез-т
 * abacaba, aba		5			abacaba
 * abacaba, aba		2			abacaba, aba
 * weew, bro, code	4			weew
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

vector <string> PalindromFilter (vector <string> words, int minLength)
{
	vector <string> retWords;
	for (int i = 0; i < words.size(); i++)
	{
		//	слово больше минимальной длины и оно €вл€етс€ палиндромом
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

