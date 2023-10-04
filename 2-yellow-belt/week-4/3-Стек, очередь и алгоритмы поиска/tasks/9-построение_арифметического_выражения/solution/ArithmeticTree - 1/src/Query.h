#pragma once
#include <string>
using namespace std;

//	запрос
struct Query {
	string operation;
	string number;
};

istream& operator >> (istream& is, Query& q);
