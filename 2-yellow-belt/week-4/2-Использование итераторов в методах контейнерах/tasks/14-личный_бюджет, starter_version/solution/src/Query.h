#pragma once
#include "Date.h"

//	типы запросов
enum class QueryType {
	Earn,
	ComputeIncome
};

//	запрос
struct Query {
	QueryType type;			//	тип запроса из enum class QueryType
	Date date_from;			//	начало диапазона дат
	Date date_to;			//	конец диапазона дат
	double money_from_per;	//	поступившее кол-во денег за период
};

istream& operator >> (istream& is, Query& q);
