#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
using namespace std;

template<typename Collection>
string Join(const Collection& c, const string& d) {
	stringstream ss;
	bool first = true;
	for (const auto& i : c) {
		if (!first) {
			ss << d;
		}
		first = false;
		ss << i;
	}
	return ss.str();
}

//	оператор вывода для vector
template <typename T>
ostream& operator << (ostream& os, const vector<T>& v) {
	return os << '[' << Join(v, ", ") << ']';
}

//	оператор вывода для pair
template <typename First, typename Second>
ostream& operator << (ostream& os, const pair<First, Second>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

//	оператор вывода для map
template <typename Key, typename Value>
ostream& operator << (ostream& os, const map<Key, Value>& m) {
	return os << '{' << Join(m, ", ") << '}';
}
