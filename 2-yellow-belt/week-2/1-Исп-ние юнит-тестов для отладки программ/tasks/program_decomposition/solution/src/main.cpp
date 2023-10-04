#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cassert>	//	для unit-тестов

using namespace std;

void PrintMap(const map< string, vector<string> >& m)
{
    if (!m.size()) {
        cout << "No buses." << endl;
    }
    else {
        for (const auto& item: m) {
            cout << "bus " << item.first << ": ";
            for (const auto& i: item.second) {
                cout << i << ' ';
            }
            cout << endl;
        }
    }
}

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

struct BusesForStopResponse {
	vector<string> buses;
};

//	вывод для запроса "BUSES_FOR_STOP"
ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.buses.size() == 0) {
    	os << "No stop" << endl;
    } else {
    	for (const string& bus : r.buses) {
    		os << bus << " ";
    	}
    	os << endl;
	}

	return os;
}

struct StopsForBusResponse {
	map<string, vector<string>> routes;    //  маршрут и его остановки
	map<string, vector<string>> stops;    //  остановки и их маршруты
	string bus;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	// Реализуйте эту функцию
    if (r.routes.count(r.bus) == 0) {
      cout << "No bus" << endl;
    } else {
    	//	цикл по всем остановкам для заданного маршрута
    	for (const string& stop : r.routes.at(r.bus)) {
    		cout << "Stop " << stop << ": ";
    		//	для к-дой остановки вывести все маршруты кроме заданного
    		if (r.stops.at(stop).size() == 1) {
    			cout << "no interchange";
    		} else {
    			for (const string& other_bus : r.stops.at(stop)) {
    				if (r.bus != other_bus) {
    					cout << other_bus << " ";
    				}
    			}
    		}
    		cout << endl;
    	}
	}

	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> route;    //  маршрут и его остановки
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.route.empty()) {
      cout << "No buses" << endl;
    } else {
      for (const auto& bus_item : r.route) {
        cout << "Bus " << bus_item.first << ": ";
        for (const string& stop : bus_item.second) {
          cout << stop << " ";
        }
        cout << endl;
      }
    }

	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		//	Для всех остановок добавляем новый маршрут
		//	Создаем словарь остановок
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
		//  создание словаря маршрутов
		buses_to_stops[bus] = stops;
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		// Вернуть пустой в-р маршрутов
		if (stops_to_buses.count(stop) == 0) {
			return BusesForStopResponse{};	//	C++11
			//return BusesForStopResponse{vector<string>()};
		}
		//	Вернуть в-р маршрутов
		return {stops_to_buses.at(stop)};
	}

	// Вернуть словарь маршрутов и вектор остановок в порядке добавления для заданного маршрута
	StopsForBusResponse GetStopsForBus(const string& bus) const {
		//	заданного маршрута нет в словаре
		if (buses_to_stops.count(bus) == 0) {
	    	  return StopsForBusResponse{};	//	C++11
		}

		//	Вернуть словари остановок маршрутов, остановок и остановку
		return {buses_to_stops, stops_to_buses, bus};
	}

	AllBusesResponse GetAllBuses() const {
		//	вернуть словарь маршрутов
		return AllBusesResponse{buses_to_stops};
	}
private:
	//	названия всех маршрутов автобуса, проходящих через остановку stop
	map<string, vector<string>> stops_to_buses;
	//	названия всех остановок маршрута bus
	map<string, vector<string>> buses_to_stops;
};

// Не меняя тела функции main, реализуйте функции и классы выше
int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
