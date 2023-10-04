#include <iostream>
#include <fstream>	//	��� ������ � �������
#include <string>
using namespace std;	//	��� ���� �� �/�������� ifstream

/*
�/�������� 2 ��������� ���������.
�-��� ����� - ��������� ������.

����� 1
������� ���� input.txt � ���������� ��� �� ����� ��� ���������. �������������, ��� ���������� ����� input.txt ������������� ��������� ������.

�������� ������:
input.txt
Keep calm
and
learn C++

�����
Keep calm
and
learn C++


����� 2
����� �������� ��� ���������� ����� input.txt, �� �� ���� ��� �������� ��� � ���� output.txt. 
����� ��� �� �������������, ��� ���������� ����� input.txt �������������� ��������� ������.

�������� ������:
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
������ ���� ��������� � ������� �� ����� �����������
��������� �� ���� ���� � �����
*/
void ReadAllFile (const string& path)
{
	ifstream input (path);	//	��� ���������� ����� ������� �����

	//	� �������� ������� ���� ����� input.is_open(), �-��� ���������� true ���� � ������ ���-� � ��� �/��������
	/*
	�� �������� ������ �/��������� � ���� bool => �/���������� ��� input.is_open() �� input
	*/
	if (input)
	{
		string line;	//	������, � �-��� �/����������� ���������� ����
		/*getline ���-�� ���������� ����� ���������. ������ ���-� - ����� �� �-�� ������ ������. ������ - ����������, � �-��� ���������� ������
		���������� ������ �� �����, �� �0�� ����� ������. ����� �/�������� � ���� bool.
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
���������� ������ � ����. ��� �-��� ������� ��������� ���� ������������ ������,
�.�. ��� ���������� ��������� � ������ ���������� ������. ��� ����, ����� ������� ����
� ������ ��������, �/������������������� ������ �������� ios::app (�� ����� append)
*/
void WriteFile(const string& path, const string writeString)
{
	ofstream output (path, ios::app);	//	������ ���-� ���� ����� ��� ������, ������ ���-� - ���� �������� (�� ����� append)
	output << writeString << endl;	//	���������� � ���� � ��������� ������, �.�. ���� �/������������ � ����, �� ����� ������ �/���������� � ����� ������
}

/*
������ ���� ��������� � ���������� ����������� � ������ ����
��������� �� ���� ���� � ����� ��� ������
*/
void ReadToFile (const string& inpPath, const string& outPath)
{
	ifstream input (inpPath);	//	��� ���������� ����� ������� �����

	//	� �������� ������� ���� ����� input.is_open(), �-��� ���������� true ���� � ������ ���-� � ��� �/��������
	/*
	�� �������� ������ �/��������� � ���� bool => �/���������� ��� input.is_open() �� input
	*/
	if (input)
	{
		string line;	//	������, � �-��� �/����������� ���������� ����
		/*getline ���-�� ���������� ����� ���������. ������ ���-� - ����� �� �-�� ������ ������. ������ - ����������, � �-��� ���������� ������
		���������� ������ �� �����, �� �0�� ����� ������. ����� �/�������� � ���� bool.
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

