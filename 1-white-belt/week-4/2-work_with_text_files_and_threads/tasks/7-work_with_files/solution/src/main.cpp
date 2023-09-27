#include <iostream>
#include <fstream>	//	для работы с файлами
#include <string>
using namespace std;	//	без него не б/работать ifstream

/*
Н/написать 2 небольшие программы.
К-дый пункт - отдельная задача.

Часть 1
Считать файл input.txt и напечатать его на экран без изменений. Гарантируется, что содержимое файла input.txt заканчивается переводом строки.

Тестовые данные:
input.txt
Keep calm
and
learn C++

Вывод
Keep calm
and
learn C++


Часть 2
Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt. 
Точно так же гарантируется, что содержание файла input.txt заканчиваестся переводом строки.

Тестовые данные:
input.txt
Keep calm
and
learn C++

output.txt
Keep calm
and
learn C++
*/

/*
Читает файл построчно и выводит на экран прочитанное
Принимает на вход путь к файлу
*/
void ReadAllFile (const string& path)
{
	ifstream input (path);	//	для считывание файла создаем поток

	//	У файловых потоков есть метод input.is_open(), к-рый возвращает true если в данный мом-т с ним м/работать
	/*
	Но файловые потоки м/приводить к типу bool => м/переписать код input.is_open() на input
	*/
	if (input)
	{
		string line;	//	строка, в к-рую б/считываться содержимое фала
		/*getline вып-ет считывание файла построчно. Первый арг-т - поток из к-го читаем данные. Второй - переменная, в к-рую записываем данные
		Возвращает ссылку на поток, из к0го берет данные. Поток м/привести к типу bool.
		*/
		while (getline (input, line))
		{
			cout << line << endl;
		}
	}
	else 
	{
		cout << "Error open file" << endl;
	}
}

/*
Записывает данные в файл. При к-дом запуске программы файл записывается заново,
т.е. его содержимое удалялось и запись начиналась заново. Для того, чтобы открыть файл
в ражиме дозаписи, н/передатьспециальный флажок дозаписи ios::app (от слова append)
*/
void WriteFile(const string& path, const string writeString)
{
	ofstream output (path, ios::app);	//	первый пар-р путь файла для записи, второй пар-р - флаг дозаписи (от слова append)
	output << writeString << endl;	//	записываем в файл с переносом строки, т.е. если б/дозаписывать в файл, то новая запись б/начинаться с новой строки
}

/*
Читает файл построчно и записывает прочитанное в ДРУГОЙ ФАЙЛ
Принимает на вход путь к файлу для чтения
*/
void ReadToFile (const string& inpPath, const string& outPath)
{
	ifstream input (inpPath);	//	для считывание файла создаем поток

	//	У файловых потоков есть метод input.is_open(), к-рый возвращает true если в данный мом-т с ним м/работать
	/*
	Но файловые потоки м/приводить к типу bool => м/переписать код input.is_open() на input
	*/
	if (input)
	{
		string line;	//	строка, в к-рую б/считываться содержимое фала
		/*getline вып-ет считывание файла построчно. Первый арг-т - поток из к-го читаем данные. Второй - переменная, в к-рую записываем данные
		Возвращает ссылку на поток, из к0го берет данные. Поток м/привести к типу bool.
		*/
		while (getline (input, line))
		{
			WriteFile(outPath, line);
		}
	}
	else 
	{
		cout << "Error open file" << endl;
	}
}


int main()
{
	const string inputFilePath = "input.txt";
	const string outputFilePath = "output.txt";
	
	ReadAllFile(inputFilePath);
	ReadToFile(inputFilePath, outputFilePath);

	return 0;
}

