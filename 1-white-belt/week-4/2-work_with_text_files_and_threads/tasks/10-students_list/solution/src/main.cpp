#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
�����-�� ���-�� "�������" �� ����. ������: ���, �������, �����, ��� ��������.
�������� �-� �� ����� ���-�, ��������� ��� �� ������� ������ � ����� �� ��������
�������� ������ ����.

������ �����:
������ ������ �������� ���� ����� ����� N �� 0 �� 10000 - ����� ���������.
����� ���� N �����, �-��� �� �-��� �������� 2 ������ ������ �� 1 �� 15 �������� - 
��� � ������� ���������� ��������, � 3 ����� ����� �� 0 �� 1000000000 - ����, ����� � ��� ��������.

��������� ������ �������� ���� ����� ����� M �� 0 �� 10000 - ����� ��������.

��������� M ����� �������� ������ ������ �� 1 �� 15 �������� - ������,
� ����� ����� �� 0 �� 1000000000 - ����� �������� (��������� ���������� � 1).

������ ������:
��� ������� ���� name K, ��� � �� 1 �� N, �������� �-� ������ ��� � ������� �-�� ��������.
��� ������� ���� date K, ��� � �� 1 �� N, �������� �-� ����� ����, ����� � ��� �������� �-�� ��������.
��� ��������� �������� �������� bad request.

������ �����:
3
Ivan Ivanov 1 1 1901
Petr Petrov 2 2 1902
Alexander Sidorov 3 3 1903
3
name 1
date 3
mark 5

������ ������:
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

	for (size_t i = 0; i < kolEl; i++)	//	� ���������� ��� size_t. �� ���� ������
	{
		cin >> name >> surname >> day >> month >> year;
		/*Student student = {name, surname, day, month, year};	//	��� � �������� ���� �� �������������� ����������� {}
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
	string request;	//	������
	int elNum = 1;	//	����� �������

	for (int i = 0; i < kolRequests; i++)
	{
		cin >> request >> elNum;
		--elNum;	//	��� �����-�� ��������� ��-�� � 1, ��� �-�� � 0

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
	
	/*���� ��������� � ������*/
	cin >> studentsKol;
	AddStudent(students, studentsKol);

	/*������� �� ����� ���� � ��������*/
	cin >> requestsCount;
	RequestProcessing(students, requestsCount);

	return 0;
}

