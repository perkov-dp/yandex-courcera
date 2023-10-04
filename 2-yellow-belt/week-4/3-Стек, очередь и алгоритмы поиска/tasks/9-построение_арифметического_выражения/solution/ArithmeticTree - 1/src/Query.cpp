#include "Query.h"

//	считывание запроса
istream& operator >> (istream& is, Query& q) {
	string date;

	//	считываем операцию
	is >> q.operation;
	is >> q.number;

	return is;
}




