#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

enum class Gender {
	FEMALE,
	MALE
};

struct Person {
	int age;  // �������
	Gender gender;  // ���
	bool is_employed;  // ����� �� ������
};
//	�������� ������ ��� vector
ostream& operator << (ostream& os, const vector<Person>& s) {
	os << "{";
	bool first = true;	//	����� ������� ������ ����� ������� ��-��
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x.age << ' ' << ' ' << x.is_employed;
	}
	return os << "}";
}

// ��� ������ �������, ��� �� ����� ���������� ������ � �������� PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
	if (range_begin == range_end) {
		return 0;
	}
	vector<typename InputIt::value_type> range_copy(range_begin, range_end);

	//	���������� ������� ���������� ������������������, �.�. ��������� ��������� Person
	auto middle = begin(range_copy) + range_copy.size() / 2;

	/* ��������� ����������. ����� ���������� �� ��������� � �������
	 * ��-�� < ��-�� ���������� ����������� � ����� �����, ������� - � ������
	 * ����������������� �� �������������
	 * lambda �-�� ��������� ��-�� �� ����������� */
	nth_element(
		begin(range_copy), middle, end(range_copy),
		[](const Person& lhs, const Person& rhs) {
			return lhs.age < rhs.age;
		}
	);

	return middle->age;
}	//	31 40 24 20 80 78 10 55	�������� �-�
	//	31 40 24 20 78 10 55 80	����� nth_element ��� ����������
	//	10 20 24 31 40 55 78 80 ����� nth_element � �����������


int ComputeMedianAgeForGender(const vector<Person>& persons, Gender gender) {
	vector<Person> sort_persons = persons;
	auto result = remove_if(
		begin(sort_persons), end(sort_persons),
		[gender](const Person& person) {
			return person.gender != gender;
		}
	);
	sort_persons.erase(result, end(sort_persons)); // ������� �������������, ������� �������� � �����
	return ComputeMedianAge(sort_persons.begin(), sort_persons.end());
}

int ComputeMedianAgeForWorkStatGender(const vector<Person>& persons, Gender gender, bool is_employed) {
	vector<Person> sort_persons = persons;
	auto result = remove_if(
		begin(sort_persons), end(sort_persons),
		[gender, is_employed](const Person& person) {
			return ((person.gender != gender) || (person.is_employed != is_employed));
		}
	);
	sort_persons.erase(result, end(sort_persons)); // ������� �������������, ������� �������� � �����

	return ComputeMedianAge(sort_persons.begin(), sort_persons.end());
}


/* ������� PrintStats, �������� ������ �����, ��������� � ������� ��������� ������� ��� ������ �� ��������� ����� �����:
 * - ��� ����;
 * - ��� �������;
 * - ��� �������;
 * - ��� ������� �������;
 * - ��� ����������� �������;
 * - ��� ������� �������;
 * - ��� ����������� �������. */
void PrintStats(const vector<Person>& persons) {
	cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
	cout << "Median age for females = " << ComputeMedianAgeForGender(persons, Gender::FEMALE) << endl;
	cout << "Median age for males = " << ComputeMedianAgeForGender(persons, Gender::MALE) << endl;
	cout << "Median age for employed females = " << ComputeMedianAgeForWorkStatGender(persons, Gender::FEMALE, true) << endl;
	cout << "Median age for unemployed females = " << ComputeMedianAgeForWorkStatGender(persons, Gender::FEMALE, false) << endl;
	cout << "Median age for employed males = " << ComputeMedianAgeForWorkStatGender(persons, Gender::MALE, true) << endl;
	cout << "Median age for unemployed males = " << ComputeMedianAgeForWorkStatGender(persons, Gender::MALE, false) << endl;
}

int main() {
	vector<Person> persons = {
			{31, Gender::MALE, false},
			{40, Gender::FEMALE, true},
			{24, Gender::MALE, true},
			{20, Gender::FEMALE, true},
			{80, Gender::FEMALE, false},
			{78, Gender::MALE, false},
			{10, Gender::FEMALE, false},
			{55, Gender::MALE, true},
	};
	PrintStats(persons);

	return 0;
}
