#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void build_map (map <vector <string>, int>& route, const vector <string>& stops)
{
	if (route.count(stops) == 0) 
	{
		int new_value = route.size();
		route[stops] = new_value + 1;
		cout << "New bus " << new_value + 1 << endl;
	} 
	else 
	{
		cout << "Already exists for " << route[stops] << endl;
	}
}

int main()
{
	int kolRequests = 0;    //  кол-во запросов
    cin >> kolRequests;
	map <vector <string>, int> routes;
    
    for (int i = 0; i < kolRequests; i++)
	{
		int kol_stops = 0;	//	кол-во остановок в маршруте
		cin >> kol_stops;

		vector <string> stops (kol_stops);

		//	считыввние названия остановок для маршрута
		for (int i = 0; i < kol_stops; i++)
		{
			string stop;  //  название маршрута
			cin >> stop;
			stops.push_back(stop);
		}

		build_map (routes, stops);
	}

	return 0;
}

