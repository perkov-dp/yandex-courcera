#include "phone_number.h"

#include <iostream>
#include <sstream>
#include <exception>

using namespace std;

//	проверяет следующий символ и кидает исключение, если это необходимо, а затем пропускает его
void EnsureNextSymbolAndSkip(stringstream& stream, char symb) {
	if (stream.peek() != symb) {
		string ss = "expected ";
		ss.append(&symb);
		ss += ", but has: ";
		char symb_ = char(stream.peek());
		ss.append(&symb_);
		throw invalid_argument(ss);
	}
	stream.ignore(1);
}

void EnsureNumberPart(const string& parse_str, const string& reason) {
	if (parse_str.empty()) {
		throw invalid_argument(reason);
	}
}

PhoneNumber::PhoneNumber(const string& international_number) {
	stringstream stream(international_number);
	EnsureNextSymbolAndSkip(stream, '+');

	getline(stream, country_code_, '-');
	EnsureNumberPart(country_code_, "country_code_ is empty");
	cout << country_code_ << endl;

	getline(stream, city_code_, '-');
	EnsureNumberPart(city_code_, "city_code_ is empty");
	cout << city_code_ << endl;

	getline(stream, local_number_);
	EnsureNumberPart(local_number_, "local_number_ is empty");
	cout << local_number_ << endl;
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}
