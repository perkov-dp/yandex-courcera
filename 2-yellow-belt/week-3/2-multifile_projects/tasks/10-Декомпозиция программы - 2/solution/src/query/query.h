#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

#ifndef QUERY_H_
#define QUERY_H_

//	типы запросов
enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

//	запрос
struct Query {
  QueryType type;		//	тип запроса из enum class QueryType
  string bus;			//	название маршрута
  string stop;			//	название остановки
  vector<string> stops;	//	вектор остановок
};

//	считывание запроса
istream& operator >> (istream& is, Query& q);



#endif /* QUERY_H_ */
