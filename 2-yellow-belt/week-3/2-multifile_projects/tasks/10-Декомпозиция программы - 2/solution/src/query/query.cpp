#include "query.h"

//	считывание запроса
istream& operator >> (istream& is, Query& q) {
	//	считываем тип запроса
	string command;
	is >> command;

	// В зависимости от типа запроса заполняются разные поля
	if (command == "NEW_BUS") {
		q.type = QueryType::NewBus;

		//	считываем маршрут
		is >> q.bus;

		//	количество остановок в маршруте
		int stop_count = 0;
		is >> stop_count;

		//	перед каждым добавлением нового маршрута очищаем вектор остановок
		q.stops.clear();

		//	считываем остановки для маршрута
		for (int i = 0; i < stop_count; i++) {
			string stop;
			is >> stop;
			q.stops.push_back(stop);
		}
	}
	else if (command == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (command == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (command == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}

	return is;
}

