#include "Query.h"

//	считывание запроса
istream& operator >> (istream& is, Query& q) {
	string date;

	// В зависимости от типа запроса заполняются разные поля
	if (q.type == QueryType::DateValue) {
		//	считываем дату поступления денег
		is >> date;
		q.money_from_day.first = Date::ParseDate(date);

		//	считываем поступившее кол-во денег вь этот день
		is >> q.money_from_day.second;
	}
	else if (q.type == QueryType::FromTo) {
		//	считываем дату - начало диапазона
		is >> date;
		q.date_from = Date::ParseDate(date);

		//	считываем дату - конец диапазона
		is >> date;
		q.date_to = Date::ParseDate(date);
	}

	return is;
}




