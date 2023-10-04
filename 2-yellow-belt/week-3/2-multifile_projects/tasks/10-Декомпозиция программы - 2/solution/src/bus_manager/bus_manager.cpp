#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	//	Для всех остановок добавляем новый маршрут
	//	Создаем словарь остановок
	for (const string& stop : stops) {
	stops_to_buses[stop].push_back(bus);
	}
	//  создание словаря маршрутов
	buses_to_stops[bus] = stops;
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	// Вернуть пустой в-р маршрутов
	if (stops_to_buses.count(stop) == 0) {
		return BusesForStopResponse{};	//	C++11
		//return BusesForStopResponse{vector<string>()};
	}
	//	Вернуть в-р маршрутов
	return {stops_to_buses.at(stop)};
}

// Вернуть словарь маршрутов и вектор остановок в порядке добавления для заданного маршрута
StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
	//	заданного маршрута нет в словаре
	if (buses_to_stops.count(bus) == 0) {
    	  return StopsForBusResponse{};	//	C++11
	}

	//	Вернуть словари остановок маршрутов, остановок и остановку
	return {buses_to_stops, stops_to_buses, bus};
}

AllBusesResponse BusManager::GetAllBuses() const {
	//	вернуть словарь маршрутов
	return AllBusesResponse{buses_to_stops};
}
