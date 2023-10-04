#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>	//	mktime
using namespace std;

class Date {
public:
	Date()
		: year_(0), month_(0), day_(0) {};

	static Date ParseDate(const string& s);
	static int ComputeDaysDiff(const Date& date_to, const Date& date_from);

	int year_;
	int month_;
	int day_;
private:
	Date(int year, int month, int day)
		: year_(year), month_(month), day_(day) {}

	// Weird legacy, can't wait for chrono::year_month_day
	time_t AsTimestamp() const;
	static void EnsureNextSymbolAndSkip(stringstream& stream, char symb);
};


