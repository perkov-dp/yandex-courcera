#include <iostream>
using namespace std;

/*
 * Ќаписать ф-ю, к-ра€ принимает и возвращает int.
 * ѕринимает int и возвращает факториал своего аргумента.
 * √арантируетс€, что арг-т ф-и по модулю не превышает 10.
 * ƒл€ отрицательных арг-тов ф-€ д/возвращать 1.
 * “естовые данные:
 * 1  => 1
 * -2 => 1
 * 4  => 24
 */

int Factorial (int number)
{
	int factorial = 1;	//	если с нул€, то факториал всегда б/равным 0

	//	‘акторал определен дл€ 0 и 1
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
	cout << "‘акториал: " << fact << endl;

	return 0;
}

