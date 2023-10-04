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
static const Date START_DATE = Date::ParseDate("2000-01-01");
//	Даты принадлежат интервалу с 2000 до 2099 гг.
static const Date END_DATE = Date::ParseDate("2100-01-01");
//	количество дней всего - размер вектора полученных сумм за день
static const size_t DAY_COUNT = Date::ComputeDaysDiff(END_DATE, START_DATE);

int main() {
	//	для единообразия формата вывода вещественных чисел
	cout.precision(25);
	vector<double> money(DAY_COUNT, .0);
	Query q;
	size_t query_count;
	cin >> query_count;

	for (size_t i = 0; i < query_count; ++i) {
		cin >> q;
		//	Вычисляем стартовый индекс путем вычитания начала диапазона и начала отсчета (нулевого индекса)
		//	Получаем диапазон индексов вектора, с к-рым дальше и работаем
		auto start_indx = Date::ComputeDaysDiff(q.date_from, START_DATE);
		auto finish_indx = Date::ComputeDaysDiff(q.date_to, START_DATE);

		switch (q.type) {
			case QueryType::Earn:
				//	делим сумму полученную за период на количество дней -> получаем кол-во денег за каждый день этого периода
				q.money_from_per /= Date::ComputeDaysDiff(q.date_to, q.date_from) + 1;
				for (int j = start_indx; j <= finish_indx; ++j) {
					money[j] += q.money_from_per;
				}
				break;
			case QueryType::ComputeIncome:
				//	суммирует сумму за каждый день этого периода, включая
				cout << accumulate(money.begin() + start_indx, money.begin() + finish_indx + 1, 0.) << endl;
				break;
		}
	}

	return 0;
}
