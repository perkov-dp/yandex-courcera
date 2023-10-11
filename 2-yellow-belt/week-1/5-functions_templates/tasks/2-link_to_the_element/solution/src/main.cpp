#include <iostream>
#include <map>
#include <exception>
using namespace std;

//	���������� ��������� ������� GetRefStrict, ������� �� ���� ���������: map � �������� ����� k.
//	���� ������� �� ����� k � ��������� �����������,
//	�� ������� ������ ������� ���������� runtime_error, ����� ������� ������ �� ������� � ���������.

//template <typename Key, typename Value>
//Value& GetRefStrict (const map<Key, Value>& m, Key key);

template <typename Key, typename Value>
Value& GetRefStrict (map<Key, Value>& m, Key key) {
	if (m.count(key) == 0) {
		throw runtime_error("no such value on this key in dictionary");
	}

	return m.at(key);
}

int main() {
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // ������� newvalue

	return 0;
}
