#pragma once
#include "Date.h"

//	типы запросов
enum class QueryType {
	DateValue,
	FromTo
};

//	запрос
struct Query {
	QueryType type;			//	тип запроса из enum class QueryType
	Date date_from;			//	начало диапазона дат
	Date date_to;			//	конец диапазона дат

	//	положительные целые числа, не превышающие 1000000
	uint64_t money_from_day;	//	поступившее кол-во денег за день
	Date earn_date;			//	дата, в которую поступили деньги
};

istream& operator >> (istream& is, Query& q);
