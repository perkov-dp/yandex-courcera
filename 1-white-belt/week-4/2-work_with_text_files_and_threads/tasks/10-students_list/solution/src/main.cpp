#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
Опред-те стр-ру "Студент" со след. полями: имя, фамилия, месяц, год рождения.
Создайте в-р из таких стр-р, заполните его из входных данных и затем по запросам
выведите нужные поля.

Формат ввода:
Первая строка содержит одно целое число N от 0 до 10000 - число студентов.
Далее идут N строк, к-дая из к-рых содержит 2 строки длиной от 1 до 15 символов - 
имя и фамилию очередного студента, и 3 целых числа от 0 до 1000000000 - день, месяц и год рождения.

Следующая строка содержит одно целое число M от 0 до 10000 - число запросов.

Следующие M строк содержат строку длиной от 1 до 15 символов - запрос,
и целое число от 0 до 1000000000 - номер студента (нумерация начинается с 1).

Формат вывода:
Для запроса вида name K, где К от 1 до N, выведите ч-з пробел имя и фамилию К-го студента.
Для запроса вида date K, где К от 1 до N, выведите ч-з точку день, месяц и год рождения К-го студента.
Для остальных запросов выведите bad request.

Пример ввода:
3
Ivan Ivanov 1 1 1901
Petr Petrov 2 2 1902
Alexander Sidorov 3 3 1903
3
name 1
date 3
mark 5

Пример вывода:
Ivan Ivanov
3.3.1903
bad request
*/

struct Student
{
	string name;
	string surname;

	int dayBirth;
	int monthBirth;
	int yearBirth;
};

void AddStudent(vector<Student>& vec, int kolEl)
{
	string name, surname;
	int day = 0, month = 0, year = 0;

	for (size_t i = 0; i < kolEl; i++)	//	в решениитип был size_t. Не знаю почему
	{
		cin >> name >> surname >> day >> month >> year;
		/*Student student = {name, surname, day, month, year};	//	ьак я добавлял если не поддерживалась конструкция {}
		vec.push_back(student);*/
		vec.push_back(Student
		{
			name,
			surname, 
			day,
			month,
			year
		});
	}
}

void RequestProcessing (const vector<Student>& vec, int kolRequests)
{
	string request;	//	запрос
	int elNum = 1;	//	номер судента

	for (int i = 0; i < kolRequests; i++)
	{
		cin >> request >> elNum;
		--elNum;	//	Для польз-ля нумерация на-ся с 1, для в-ра с 0

		if (request == "name" && elNum >= 0 && elNum < vec.size())
		{
			cout << vec[elNum].name << ' '
				 << vec[elNum].surname << endl;
		}
		else if (request == "date" && elNum >= 0 && elNum < vec.size())
		{
			cout << vec[elNum].dayBirth << '.' 
				 << vec[elNum].monthBirth << '.' 
				 << vec[elNum].yearBirth << endl;
		}
		else
			cout << "bad request" << endl;
	}
}

int main()
{
	vector <Student> students;
	int studentsKol = 0;
	int requestsCount = 0;
	
	/*Ввод студентов в вектор*/
	cin >> studentsKol;
	AddStudent(students, studentsKol);

	/*Запросы на вывод инфы о студенте*/
	cin >> requestsCount;
	RequestProcessing(students, requestsCount);

	return 0;
}

