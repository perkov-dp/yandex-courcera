#include <iostream>
#include <map>
#include <iostream>
#include <string>
using namespace std;

/*
 Реализуйте справочник столиц стран.

На вход программе поступают следующие запросы:

1) CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, 
 * либо добавление такой страны с такой столицей, если раньше её не было.
2) RENAME old_country_name new_country_name — переименование страны из old_country_name в 
 * new_country_name.
3) ABOUT country — вывод столицы страны country.
4) DUMP — вывод столиц всех стран.

Формат ввода
В первой строке содержится количество запросов Q, в следующих Q строках — описания запросов. 
Все названия стран и столиц состоят лишь из латинских букв, цифр и символов подчёркивания.

Формат вывода
Выведите результат обработки каждого запроса:

В ответ на запрос CHANGE_CAPITAL country new_capital выведите
- Introduce new country country with capital new_capital, если страны country раньше не существовало;
- Country country hasn't changed its capital, если страна country до текущего момента имела столицу new_capital;
- Country country has changed its capital from old_capital to new_capital, если страна country до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.

В ответ на запрос RENAME old_country_name new_country_name выведите
- Incorrect rename, skip, если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует;
- Country old_country_name with capital capital has been renamed to new_country_name, если запрос корректен и страна имеет столицу capital.

В ответ на запрос ABOUT country выведите
- Country country doesn't exist, если страны с названием country не существует;
- Country country has capital capital, если страна country существует и имеет столицу capital.

В ответ на запрос DUMP выведите
- There are no countries in the world, если пока не было добавлено ни одной страны;
- последовательность пар вида country/capital, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна. 

При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом.
 */

void ChangeCapital (map<string, string>& cap_ref, const string& country, const string& new_capital)
{
    //	если страны country раньше не существовало
    if (cap_ref.count(country) == 0)
    {
    	cout << "Introduce new country " << country << " with capital " << new_capital << endl;
    }
    else 
    {	
	//	страна country до текущего момента имела столицу new_capital
        if (cap_ref[country] == new_capital)
	{
            cout << "Country " << country << " hasn't changed its capital" << endl;
	}
	//	страна country до текущего момента имела столицу old_capital, название которой не совпадает с названием new_capital.
	else
	{
            cout << "Country " << country << " has changed its capital from " << cap_ref[country]
		 << " to " << new_capital << endl;
	}
    }

    cap_ref[country] = new_capital;
}

void RenameCoutry (map<string, string>& cap_ref, const string& old_country_name, const string& new_country_name)
{
    //	если новое название страны совпадает со старым, страна old_country_name не существует или страна new_country_name уже существует
    if (old_country_name == new_country_name ||
    	cap_ref.count(old_country_name) == 0 || cap_ref.count(new_country_name) == 1)
    {
	cout << "Incorrect rename, skip" << endl;
    }
    //	запрос корректен и страна имеет столицу capital
    else
    {
    	cout << "Country " << old_country_name << " with capital " << cap_ref[old_country_name]
             << " has been renamed to " << new_country_name << endl;
        cap_ref[new_country_name] = cap_ref[old_country_name];	//	меняем ключ (т.е. добавляем новый)
	cap_ref.erase(old_country_name);	//	удаляем старый ключ
    }
}

//	почему-то VS жалуется на const map при выводе столицы!!!!
void AboutCountry (map<string, string>& cap_ref, const string& country)
{
    //	если страны country раньше не существовало
    if (cap_ref.count(country) == 0)
    {
    	cout << "Country " << country << " doesn't exist" << endl;
    }
    //	страна country существует и имеет столицу capital
    else
    {
    	cout << "Country " << country << "has capital " << cap_ref[country] << endl;
    }
}

void Dump (const map<string, string>& cap_ref)
{
    //	пока не было добавлено ни одной страны
    if (cap_ref.empty())
    {
    	cout << "There are no countries in the world" << endl;
    }
    //	Последовательность пар вида country/capital, описывающую столицы всех стран, если в мире уже есть хотя бы одна страна
    else
    {
	//	При выводе последовательности пары указанного вида необходимо упорядочить по названию страны и разделять между собой пробелом
        for (const auto& country_item : cap_ref)
	{
            cout << country_item.first << '/' << country_item.second << ' ';
	}
        //  вывод с пом-щью указателей. М/еще (*it).first
        /*for (auto it = cap_ref.begin(); it != cap_ref.end(); it++)
        {
            cout << it->first << '/' << it->second << ' ';
        }*/
        cout << endl;
    }
}

int main() {
    map <string, string> cap_ref;
    int reqCnt = 0;
    cin >> reqCnt;
    string request;
    string country_name;
    string new_capital;

    for (int i = 0; i < reqCnt; i++)
    {
	cin >> request;
	if (request == "CHANGE_CAPITAL")
	{
            cin >> country_name >> new_capital;
            ChangeCapital(cap_ref, country_name, new_capital);
	}
	else if (request == "RENAME")
	{
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            RenameCoutry(cap_ref, old_country_name, new_country_name);
        }
	else if (request == "ABOUT")
	{
            cin >> country_name;
            AboutCountry (cap_ref, country_name);
        }
	else if (request == "DUMP")
	{
            Dump(cap_ref);
	}
    }

    return 0;
}