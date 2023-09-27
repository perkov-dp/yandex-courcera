#include <cstdlib>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

void build_map (map <set <string>, int>& route, const set <string>& stops)
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

int main(int argc, char** argv) {
    int kolRequests = 0;
    cin >> kolRequests;
    map <set <string>, int> routes;
    
    for (int i = 0; i < kolRequests; i++)
    {
	int kol_stops = 0;
	cin >> kol_stops;
        
        vector <string> stops(kol_stops);

        /*
         * заполняем в-р введенными остановками
         */
	for (int i = 0; i < kol_stops; i++)
	{
            string stop;
            cin >> stop;
            stops.push_back(stop);
	}
        
        /*
         * В отличие от задачи «Автобусные остановки — 2», наборы остановок, 
         * которые можно получить друг из друга перестановкой элементов или 
         * добавлением/удалением повторяющихся, следует считать одинаковыми.
         * Т.е. Marushkino Kokoshkino и Kokoshkino Marushkino - это 
         * одинаковый набор осановок => здесь нужен set.
         * Формируем набор из в-ра, оставляя только отличные др. от др. остановки 
         * 
         * Т.о. первичный ключ словаря - набор уникальных остановок без повторений
         */
        set <string> set_stops(begin(stops), end(stops));
        
	build_map (routes, set_stops);
    }

    return 0;
}

