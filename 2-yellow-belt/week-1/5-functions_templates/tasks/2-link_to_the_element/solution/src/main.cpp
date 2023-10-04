#include <iostream>
#include <map>
#include <exception>
using namespace std;

//	Реализуйте шаблонную функцию GetRefStrict, которая на вход принимает: map и значение ключа k.
//	Если элемент по ключу k в коллекции отсутствует,
//	то функция должна бросить исключение runtime_error, иначе вернуть ссылку на элемент в коллекции.

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
	cout << m[0] << endl; // выведет newvalue

	return 0;
}
