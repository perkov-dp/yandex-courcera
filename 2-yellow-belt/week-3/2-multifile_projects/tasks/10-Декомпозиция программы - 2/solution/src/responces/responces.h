#pragma once

#ifndef RESPONCES_H_
#define RESPONCES_H_

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

struct BusesForStopResponse {
	vector<string> buses;
};

//	вывод для запроса "BUSES_FOR_STOP"
ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	map<string, vector<string>> routes;    //  маршрут и его остановки
	map<string, vector<string>> stops;    //  остановки и их маршруты
	string bus;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	map<string, vector<string>> route;    //  маршрут и его остановки
};

ostream& operator << (ostream& os, const AllBusesResponse& r);



#endif /* RESPONCES_H_ */
