#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <chrono>

using namespace std;

#include "Date.h"
#include "Query.h"

//	начало отсчета - нулевой индекс в векторе полученных сумм за день
static const Date START_DATE = Date::ParseDate("1700-01-01");
//	Даты принадлежат интервалу с 2000 до 2099 гг.
static const Date END_DATE = Date::ParseDate("2100-01-01");
//	количество дней всего - размер вектора полученных сумм за день
static const size_t DAY_COUNT = Date::ComputeDaysDiff(END_DATE, START_DATE);

int main() {
	//	положительные целые числа, не превышающие 1000000
	vector<uint64_t> money(DAY_COUNT, 0);
	vector<uint64_t> partial_sums(DAY_COUNT, 0);
	Query q;
	size_t query_count;

	cin >> query_count;
	q.type = QueryType::DateValue;
	for (size_t i = 0; i < query_count; ++i) {
		cin >> q;
		//	Вычисляем стартовый индекс путем вычитания начала диапазона и начала отсчета (нулевого индекса)
		//	Получаем диапазон индексов вектора, с к-рым дальше и работаем
		auto earn_indx = Date::ComputeDaysDiff(q.earn_date, START_DATE);
		money[earn_indx] = q.money_from_day;
	}
	//	эл-т partial_sums - сумма к определенному дню
	partial_sum(money.begin(), money.end(), partial_sums.begin());

	cin >> query_count;
	q.type = QueryType::FromTo;
	for (size_t i = 0; i < query_count; ++i) {
		cin >> q;
	    auto start_indx = Date::ComputeDaysDiff(q.date_from, START_DATE);
	    auto finish_indx = Date::ComputeDaysDiff(q.date_to, START_DATE);

	    //	зароботок за период
	    if (start_indx > 0) {
	    	cout << partial_sums[finish_indx] - partial_sums[start_indx - 1] << '\n';
	    }
	    else {
	    	cout << partial_sums[finish_indx] << '\n';
	    }
	}

	return 0;
}
