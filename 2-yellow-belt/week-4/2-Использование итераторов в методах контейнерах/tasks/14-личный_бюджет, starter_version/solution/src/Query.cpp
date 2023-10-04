#include "Query.h"

//	считывание запроса
istream& operator >> (istream& is, Query& q) {
	//	считываем тип запроса
	string command;
	string date;
	is >> command;

	//	считываем дату - начало диапазона
	is >> date;
	q.date_from = Date::ParseDate(date);

	//	считываем дату - конец диапазона
	is >> date;
	q.date_to = Date::ParseDate(date);

	// В зависимости от типа запроса заполняются разные поля
	if (command == "Earn") {
		q.type = QueryType::Earn;
		is >> q.money_from_per;
	}
	else if (command == "ComputeIncome") {
		q.type = QueryType::ComputeIncome;
	}

	return is;
}




