#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>		//	библиотека для потоковых манипуляторов
using namespace std;

/*
В файле input.txt записаны вещественные числа, по одному на строчку. 
На стандартный вывод напечатайте эти числа в том же порядке, по одному на строке, 
но сделайте так, чтобы у к-го из них было ровно три знака после десятичной точки.

Пример ввода 1
5
0.34567
10.4

Пример вывода 1
5.000
0.346
10.400

Пример ввода 2
3.33353
3.333
3.3

Пример вывода 2
3.334
3.333
3.300

Примечание: воспользуйтесь стандартными манипуляторами потоков вывода.
*/

/*
Читает файл построчно и выводит на экран прочитанное
Принимает на вход путь к файлу
*/
void ExactlyOuputFile (const string& path)
{
	ifstream input (path);	//	для считывание файла создаем поток
	double number = 0;

	//	выводим числа с фиксированной точностью(fixed) и с 3 знаками после запятой (setprecision (3))
	cout << fixed << setprecision(3);

	//	пока есть числа в строках файла
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

