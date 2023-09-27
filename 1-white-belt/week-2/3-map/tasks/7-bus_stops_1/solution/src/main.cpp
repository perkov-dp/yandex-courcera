#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

//  Добавление нового эл-та в map
void AddMapEl (map< string, vector<string> >& m, const string& key, 
               const string& value)
{
    m[key].push_back(value);
}

//  ALL_BUSES — вывести список всех маршрутов с остановками.
void PrintMap(const map< string, vector<string> >& m) 
{
    if (!m.size())
    {
        cout << "No buses." << endl;
    }
    else
    {
        for (const auto& item: m) {
            cout << "bus " << item.first << ": ";
            for (const auto& i: item.second)
            {
                cout << i << ' ';
            }
            cout << endl;
        }        
    }
}

/*  
 * BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, 
 * проходящих через остановку stop, в том порядке, 
 * в котором они создавались командами NEW_BUS.
 */
/*
 * На вход поступает map, в-р маршрутов в порядке, в котором они создавались командами NEW_BUS
 * и искомая остановка.
 * 
 * Фактически ф-я делится на 2 части
 * 1) Поиск маршрутов для искомой остановки
 * 2) Вывод их в порядке, в котором они создавались командами NEW_BUS. 
 * Для этого и передается в-р маршрутов в кач-ве пар-ра
 */
void buses_for_stop (const map< string, vector<string> >& route, 
        const vector <string>& routes_in_order, const string& stop_name)
{
    /*
     * в-р для вывода маршрутов в порядке их добавления в словарь маршрута
     * т.к. ключи в словаре сортируются по алфавиту, а не в порядке их добавления
     */    
    vector<string> find_routes;
    
    //  цикл по эл-там словаря маршрутов
    for (const auto& route_el: route)
    {   //  для к-го маршрута проходим цикл по всем остановкам этого маршрута
        for (const auto& route_stop: route_el.second)
        {   //  если название остановки для этого маршрута совпадает с искомой остановкой  
            if (route_stop == stop_name)
            {   //  запишем найденный маршрут этой остановки в вектор
                find_routes.push_back(route_el.first);
                break;  //  переход к следующему маршруту
            }
        }
    }
    //  если не нашли совпадение, то так и напишем и выйдем из функции
    if (find_routes.size() <= 0)
    {
        cout << "No stop" << endl; //если не нашли совпадение, то так и напишем
        return;
    }
    
    /*
     * В в-ре всех маршрутов в порядке добавления цкилимся по всем найденным 
     * маршрутам для этой остановки.
     * Если этот маршрут есть и в списке найденных маршрутов для искомой остановки, 
     * то выводим его.
     * Это нужно для вывода найденных маршрутов именно в порядке добавления маршрута,
     * а не в порядке словаря, к-рый сортирует ключи по вохрастанию.
     * Для этого мы формируем и передаем в эту ф-ю в-р routes_in_order.
     */
    for (const auto& all_stops_el : routes_in_order)
    {   //  цикл в-ра найленных маршрутов для искомой остановки
        for (const auto& find_route : find_routes)
        {   //  если такой маршрут есть в в-ре найденных маршрутов
            if (all_stops_el == find_route)
            {   //  выводим найденный маршрут ч-з пробел по условию задачи
                cout << find_route << " ";
            }   
        }
    }
    cout << endl;
    //  т.о. у нас будут выведены маршруты в порядке записи командой NEW_BUS    
}

/*
 * Вывести названия всех остановок маршрута bus со списком автобусов, на которые 
 * можно пересесть на каждой из остановок.
 * Выведите описания остановок маршрута bus в отдельных строках в том порядке, 
 * в котором они были заданы в соответствующей команде NEW_BUS.
 * 
 * Т.е. вывести список остановок искомого маршрута.
 * Для к-дой из этих остановок вывести список маршрутов, в к-рых фигурирует эта остановка,
 * кроме искомого маршрута.
 * 
 * На вход поступает map, в-р маршрутов в порядке, в котором они создавались командами NEW_BUS
 * и искомый маршрут.
 * 
 * Фактически ф-я делится на 2 части
 * 1) Поиск маршрутов для остановок искомого маршрута
 * 2) Вывод их в порядке, в котором они создавались командами NEW_BUS. 
 * Для этого и передается в-р маршрутов в кач-ве пар-ра
 */

void stops_for_bus (const map< string, vector<string> >& route, 
        const vector <string>& routes_vec, const string& find_route_num)
{    
    //  Если маршрут find_route_num не существует
    if (route.count(find_route_num) == 0)
    {
        cout << "no bus" << endl;
        return;
    }
    
    //  цикл по словарю
    for (const auto& i: route)
    {
        if (i.first == find_route_num)
        {            
            //  цикл по всем остановкам искомого марщрута
            for (const auto& j: i.second)
            {
                cout << "Stop " << j << ": ";
                
                vector <string> find_routes;
                bool interchange_flag = false;
                
                //  ищем эту остановку в других маршрутах (кроме искомого искомом)
                for (const auto& rt: route)
                {
                    //  если это не исходный маршрут
                    if (rt.first != find_route_num)
                    {                        
                        for (const auto& stop : rt.second)
                        {
                            //  если такая же остановка есть и в искомом маршруте
                            if (stop == j)
                            {                                
                                find_routes.push_back(rt.first);
                                interchange_flag = true;
                            }
                        }
                    }
                }
                
                /*
                 * После того как мы нашли все нужные маршруты для каждой из остановок
                 * искомого маршрута, мы выводим их на экран в порядке,
                 * в котором они создавались командами NEW_BUS
                 */
                if (interchange_flag == false)
                {
                    cout << "no interchange" << endl;
                }
                else
                {
                    for (const auto& ordered_route: routes_vec)
                    {
                        for (const auto& find_rt: find_routes)
                        {
                            if (find_rt == ordered_route)
                            {
                                cout << find_rt << ' ';
                            }                                    
                        }
                    }
                    cout << endl;
                }                                
            }
        }
    }
}


int main(int argc, char** argv) {
    map<string, vector<string>> route;    //  маршрут и его остановки
    map<string, vector<string>> stops;    //  остановка и маршруты, к-рые ч-з нее проходят
    vector <string> routesVec;  //  в-р маршрутов
    
    int kolRequests = 0;    //  кол-во запросов
    cin >> kolRequests;
    
    for (int i = 0; i < kolRequests; i++)
    {
        string stop_name;   //  название остановки
        
        string request; //  запрос
        cin >> request;
        
        if (request == "NEW_BUS")
        {            
            int stop_count = 0; //  ко-во остановок
            string route_name;  //  название маршрута
            cin >> route_name >> stop_count;
            routesVec.push_back(route_name); //  добавляем маршрут в в-р маршрутов

            for (int j = 0; j < stop_count; j++)
            {
                cin >> stop_name;   //  название остановки
                AddMapEl(route, route_name, stop_name); //  создание словаря маршрутов
            }
        }
        else if (request == "BUSES_FOR_STOP")
        {
            cin >> stop_name;
            buses_for_stop (route, routesVec, stop_name);
        }
        else if (request == "STOPS_FOR_BUS")
        {
            string route_name;
            cin >> route_name;
            stops_for_bus (route, routesVec, route_name);
        }
        else if (request == "ALL_BUSES")
        {
            PrintMap(route);
        }
    }
    
    return 0;
}

