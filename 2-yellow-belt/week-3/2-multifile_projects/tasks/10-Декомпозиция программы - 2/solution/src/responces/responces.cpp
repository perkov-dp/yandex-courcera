#include "responces.h"

#ifndef RESPONCES_CPP_
#define RESPONCES_CPP_

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


#endif /* RESPONCES_CPP_ */
