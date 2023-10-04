#include "date.h"
#include <tuple>

Day::Day(int new_value) : value(new_value)
{
}

Month::Month(int new_value) : value(new_value)
{
}

Year::Year(int new_value) : value(new_value)
{
}

Date::Date(const Year& year, const Month& month, const Day& day)
    : _year(year), _month(month.value), _day(day.value)
{
}

int Date::GetYear() const{
    return _year.value;
}
int Date::GetMonth() const{
    return _month.value;
}
int Date::GetDay() const{
    return _day.value;
}
string Date::DateToString() const {
    stringstream stream;
    stream << setfill('0');
    stream << setw(4) << _year.value << '-'
           << setw(2) << _month.value << '-'
           << setw(2) << _day.value;
    return stream.str();
}

void EnsureNextSymbolAndSkip(istringstream& stream) {
    if (stream.peek() != '-') {
        stringstream ss;
        ss << "Wrong date format: expected - , but has: " << char(stream.peek());
        throw runtime_error(ss.str());
    }
    stream.ignore(1);
}

//	считывание месяца
int ParseMonth (istringstream& stream)
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
Date ParseDate(istringstream& stream) {
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

//	оператор вывода класса даты
ostream& operator << (ostream& stream, const Date& date) {
    stream << setfill('0');	//	setfill Указывает, каким символом заполнять расстояние между колонками.
    stream << setw(4) << date.GetYear() << '-'	//	setw - указывает ширину поля, которое резервируется для вывода переменной.
           << setw(2) << date.GetMonth() << '-'
           << setw(2) << date.GetDay();
    return stream;
}

ostream& operator << (ostream& stream, const pair<Date, string>& date_events) {
    stream << date_events.first << ' ' << date_events.second;
    return stream;
}

bool operator < (const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <
        make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator > (const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >
        make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator <= (const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <=
        make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator >= (const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >=
        make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator == (const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) ==
        make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator != (const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) !=
        make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}