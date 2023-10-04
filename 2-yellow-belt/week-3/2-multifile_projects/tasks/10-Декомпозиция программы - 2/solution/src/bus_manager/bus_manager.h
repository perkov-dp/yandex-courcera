#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

#include "../responces/responces.h"


#ifndef BUS_MANAGER_H_
#define BUS_MANAGER_H_


class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops);

	BusesForStopResponse GetBusesForStop(const string& stop) const;

	// Вернуть словарь маршрутов и вектор остановок в порядке добавления для заданного маршрута
	StopsForBusResponse GetStopsForBus(const string& bus) const;

	AllBusesResponse GetAllBuses() const;
private:
	//	названия всех маршрутов автобуса, проходящих через остановку stop
	map<string, vector<string>> stops_to_buses;
	//	названия всех остановок маршрута bus
	map<string, vector<string>> buses_to_stops;
};


#endif /* BUS_MANAGER_H_ */
