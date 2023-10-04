#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cassert>	//	для unit-тестов

#include "query/query.h"
#include "responces/responces.h"
#include "bus_manager/bus_manager.h"

using namespace std;

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
