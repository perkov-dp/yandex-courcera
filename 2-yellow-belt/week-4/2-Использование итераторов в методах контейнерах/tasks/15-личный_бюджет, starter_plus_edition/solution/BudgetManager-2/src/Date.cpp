#include "Date.h"

//	преобразует диапазон дат в разницу в днях
int Date::ComputeDaysDiff(const Date& date_to, const Date& date_from) {
	const time_t timestamp_to = date_to.AsTimestamp();
	const time_t timestamp_from = date_from.AsTimestamp();
	static constexpr int SECONDS_IN_DAY = 60 * 60 * 24;
	return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
}

// Weird legacy, can't wait for chrono::year_month_day
time_t Date::AsTimestamp() const {
	tm t;
	t.tm_sec  = 0;
	t.tm_min  = 0;
	t.tm_hour = 0;
	t.tm_mday = day_;
	t.tm_mon  = month_ - 1;
	t.tm_year = year_ - 1900;
	t.tm_isdst = 0;

	//	Преобразуют локальное время в календарное значение
	return mktime(&t);
}

void Date::EnsureNextSymbolAndSkip(stringstream& stream, char symb) {
	if (stream.peek() != symb) {
		stringstream ss;
		ss << "expected " << symb << ", but has: " << char(stream.peek());
		throw runtime_error(ss.str());
	}
	stream.ignore(1);
}

Date Date::ParseDate(const string& s){
	stringstream stream(s);
	int year;
	stream >> year;
	Date::EnsureNextSymbolAndSkip(stream, '-');

	int month;
	stream >> month;
	Date::EnsureNextSymbolAndSkip(stream, '-');

	int day;
	stream >> day;

	return {year, month, day};
}
