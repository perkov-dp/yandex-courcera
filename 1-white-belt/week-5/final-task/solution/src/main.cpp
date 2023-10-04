#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <exception>
#include <iomanip>	//	setw(), setfill()
#include <algorithm>
using namespace std;

struct Day {
    int value;
    explicit Day(int new_value) {
        value = new_value;
    }
};

struct Month {
    int value;
    explicit Month(int new_value) {
        value = new_value;
    }
};

struct Year {
    int value;
    explicit Year(int new_value) {
        value = new_value;
    }
};


//  ключ БД
class Date {
public:
    Date(Year new_year, Month new_month, Day new_day) {
        year = new_year.value;
        month = new_month.value;
        day = new_day.value;
    }

    int GetYear() const{
    	return year;
    }
    int GetMonth() const{
    	return month;
    }
    int GetDay() const{
    	return day;
    }
private:
    int year;
    int month;
    int day;
};

//	оператор вывода класса даты
ostream& operator<<(ostream& stream, const Date& date) {
	stream << setfill('0');	//	setfill Указывает, каким символом заполнять расстояние между колонками.
	stream << setw(4) << date.GetYear() << '-'	//	setw - указывает ширину поля, которое резервируется для вывода переменной.
		   << setw(2) << date.GetMonth() << '-'
		   << setw(2) << date.GetDay();
	return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			return lhs.GetDay() < rhs.GetDay();
		}
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}

class Database {
public:
	//	Добавление события по ключу (дате). Если такое же событие уже есть в эту дату, то ничего не добавляется
    void AddEvent(const Date& date, const string& event){
    	//	Значение - это контейнер set. Если в нем есть такое событие, то ничего не добавляется
    	//	Ключ - дата. Если такой даты не бвло, то она создается при обращении по этому ключу
    	db[date].insert(event);
    }

    //	Улаление одного из событий за указанную дату
    bool DeleteEvent(const Date& date, const string& event)
    {
    	//	если нету даты или события в эту дату, то ничего не удаляется
    	if (db.count(date) == 0 || db.at(date).count(event) == 0)
    	{
    		cout << "Event not found" << endl;
    		return false;
    	}

    	db.at(date).erase(event);
		cout << "Deleted successfully" << endl;

		return true;
    }

    //	Команда удаляет все ранее добавленные события за указанную дату
    int DeleteDate(const Date& date){
    	int kol_del_events = 0;	//

    	//	если эта дата была ранее добавлена, то удаляем все события связанные с ней
    	if (db.count(date) > 0){
    		kol_del_events = db.at(date).size();
    		db.erase(date);
    	}
    	cout << "Deleted " << kol_del_events << " events" << endl;

    	return kol_del_events;
    }

	void Find(const Date& date) const
	{
		//	если есть требуемая дата
		if (db.count(date) > 0)
		{
			//	если есть события связанные с этой датой
			if (db.at(date).size() > 0)
			{
				for (const auto& event: db.at(date)) {
					cout << event << ' ';
				}
				cout << endl;
			}
		}
	}

	//	вывод всей БД в отсортированном порядке. Это обеспечивается конструкциями map и set
    void Print() const
    {
        if (db.size() == 0)
        {
            cout << "Data base is empty" << endl;
        }
        else
        {
			for (const auto& date: db)
			{
				cout << date.first << ' ';
				for (const auto& event: date.second) {
					cout << event << ' ';
				}
				cout << endl;
			}
        }
    }
private:
    map <Date, set<string>> db;
};


////////////////////////////////////////////////////////////////////////////////////////////////
void EnsureNextSymbolAndSkip(stringstream& stream) {
    if (stream.peek() != '-') {
        stringstream ss;
        ss << "Wrong date format: expected - , but has: " << char(stream.peek());
        throw runtime_error(ss.str());
    }
    stream.ignore(1);
}

//	считывание месяца
int ParseMonth (stringstream& stream)
{
	int month = 0;

	//	символ '+' нас устраивает => переходим к анализу следующего символа
	if (stream.peek() == '+')
	{
		stream.ignore(1);	//	игнорируем его
	}

	//	если первый символ 0, то второй д/б 1-9
    if (stream.peek() == '0')
    {
    	stream.ignore(1);	//	игнорируем его

    	//	второй символ - месяц от 1 до 9
    	stream >> month;
    	if (month < 1 || month > 9)
    	{
            stringstream ss;
            //  вывод ошибки и преобразование месяца к строке
            string error = "Month value is invalid: " + to_string(month);
            ss << error;
            throw runtime_error(ss.str());
    	}
    }
    //	цифры от 1 - 9
    else if (isdigit(stream.peek()))
    {
    	//	месяц - число от 1 до 12
    	stream >> month;
    	if (month < 1 || month > 12)
    	{
            stringstream ss;
            //  вывод ошибки и преобразование месяца к строке
            string error = "Month value is invalid: " + to_string(month);
            ss << error;
            throw runtime_error(ss.str());
    	}
    }
	else if(stream.peek() == '-')
	{
		stringstream ss;
		char symb = char(stream.peek());	//	запоминаем символ '-' для вывода ошибки

		stream.ignore(1);	//	переходим к следующему символу

		//	является ли следующий символ после '-' числом
		if (isdigit(stream.peek()))	//	char(stream.peek()) > '0' && char(stream.peek()) < '9'
		{
			stream >> month;
	        //  вывод ошибки и преобразование месяца к строке
	        string error = "Month value is invalid: -" + to_string(month);
	        ss << error;
		}
		//	после '-' не число => неверный формат
		else
		{
			//	выводим символ '-' и следующий за ним
			ss << "Wrong date format: " << char(symb) << char(stream.peek());
		}

        throw runtime_error(ss.str());
	}
	else
	{
		stringstream ss;
		ss << "Wrong date format: " << char(stream.peek());
		throw runtime_error(ss.str());
	}

    return month;
}

//	ситывание строки даты в форматном виде
Date ParseDate(const string& s){
    stringstream stream(s);
    int year = 0;
    int month = 0;
    int day = 0;

    stream >> year;
    EnsureNextSymbolAndSkip(stream);

    month = ParseMonth(stream);
    EnsureNextSymbolAndSkip(stream);

    stream >> day;
    if (day < 1 || day > 31)
    {
        stringstream ss;
        //  вывод ошибки и преобразование дня месяца к строке
        string error = "Day value is invalid: " + to_string(day);
        ss << error;
        throw runtime_error(ss.str());
    }

    return {Year(year), Month(month), Day(day)};
}


int main() {
    Database db;

    string line;	//	вся строка с командой и данными целиком
    while (getline(cin, line)) {
    	// Считайте команды с потока ввода и обработайте каждую
    	string command;
    	stringstream ss(line);

    	ss >> command;

    	if (command == "")
    	{
    		break;
    	}

    	if (command == "Add")
    	{
    		string date_str;
    		string event;

    		ss >> date_str >> event;
    		try{
    			Date date = ParseDate(date_str);
    			db.AddEvent(date, event);
    		}
    		catch(exception& ex){
    			cout << "exception happenes: " << ex.what();
			}
    	}
    	else if (command == "Del")
    	{
    		string date_str;
    		string event;

    		ss >> date_str >> event;
    		try{
        		Date del_date = ParseDate(date_str);
        		if (event.empty())
        		{
        			db.DeleteDate(del_date);
        		}
        		else
        		{
        			db.DeleteEvent(del_date, event);
        		}
    		}
    		catch(exception& ex){
    			cout << "exception happenes: " << ex.what();
			}
    	}
    	else if (command == "Find")
    	{
    		string date_str;
    		ss >> date_str;
    		try{
    			Date find_data = ParseDate(date_str);
    			db.Find(find_data);
    		}
    		catch(exception& ex){
    			cout << "exception happenes: " << ex.what();
			}
    	}
    	else if (command == "Print")
    	{
    		db.Print();
    	}
    }

	return 0;
}
