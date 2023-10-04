#pragma once
#include <ostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Day {
    int value;
    explicit Day(int new_value);
};

struct Month {
    int value;
    explicit Month(int new_value);
};

struct Year {
    int value;
    explicit Year(int new_value);
};


//  ключ БД
class Date {
public:
    Date(const Year& year, const Month& month, const Day& day);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

    string DateToString() const;
private:
    Year _year;
    Month _month;
    Day _day;
};

Date ParseDate(istringstream& stream);

ostream& operator << (ostream& stream, const Date& date);
ostream& operator << (ostream& stream, const pair<Date, string>& date_events);

bool operator < (const Date& lhs, const Date& rhs);
bool operator > (const Date& lsh, const Date& rhs);
bool operator <= (const Date& lsh, const Date& rhs);
bool operator >= (const Date& lsh, const Date& rhs);
bool operator == (const Date& lsh, const Date& rhs);
bool operator != (const Date& lsh, const Date& rhs);