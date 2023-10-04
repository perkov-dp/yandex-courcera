#include <iostream>
#include <set>
#include <iterator>
using namespace std;

/*	Напишите функцию FindNearestElement, для множества целых чисел numbers и
 *	данного числа border возвращающую итератор на элемент множества,
 *  ближайший к border. Если ближайших элементов несколько,
 *  верните итератор на наименьший из них.
 *  set<int>::const_iterator FindNearestElement(
 *  const set<int>& numbers,
 *  int border);
 *	set<int>::const_iterator —
 *	тип итераторов для константного множества целых чисел */

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
	/*	1) Ищем первый эл-т >= border
	 *	Если мн-во пусто или первый же эл-т >= border, то возвращаем этот эл-т
	 *	Это значит, что меньшего эл-та нет, поэтому первый эл-т и есть ближайший
	 *
	 *	2) Мн-во уже не пусто. Ищем первый эл-т < border.
	 *	Если нет эл-тов, >= border, то возвращаем последний эл-т < border,
	 *	т.е. последний эл-т отсортированного мн-ва
	 *
	 *	3) Сравниваем оба итератора и возвращаем тот,
	 *	чья разница м-ду ним и искомым меньше
	 */

	const auto first_not_less = numbers.lower_bound(border);
	if (first_not_less == numbers.begin()) {
		return first_not_less;
	}

	const auto last_less = prev(first_not_less);
	if (first_not_less == numbers.end()) {
		return last_less;
	}

	int diff_larger_border = *first_not_less - border;
	int diff_lower_border = border - *last_less;

	//	Если ближайших элементов несколько, верните итератор на наименьший из них
	bool diff_decision = diff_larger_border >= diff_lower_border;
	return diff_decision ? last_less : first_not_less;

	/*	обычный способ
	 * 	if (diff_larger_border >= diff_lower_border) {
	 *		return last_less;
	 *	}
	 *	else {
	 *		return first_not_less;
	 *	}
	 */
}

//set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
	/*	1) Ищем первый эл-т >= border
	 *	Если мн-во пусто или первый же эл-т >= border, то возвращаем этот эл-т
	 *	Это значит, что меньшего эл-та нет, поэтому первый эл-т и есть ближайший
	 *
	 *	2) Мн-во уже не пусто. Ищем первый эл-т < border.
	 *	Если нет эл-тов, >= border, то возвращаем последний эл-т < border,
	 *	т.е. последний эл-т отсортированного мн-ва
	 *
	 *	3) Сравниваем оба итератора и возвращаем тот,
	 *	чья разница м-ду ним и искомым меньше
	 */

	// Запрашиваем итератор на первый элемент, не меньший (>=) border;
	// если такого элемента нет, то мы получим numbers.end()
	/*const auto first_not_less = numbers.lower_bound(border);

	// Если множество пусто или до первого элемента не меньше border
	// нет элементов, то мы уже получили ответ
	if (first_not_less == numbers.begin()) {
		return first_not_less;
	}

	// prev -> http://ru.cppreference.com/w/cpp/iterator/prev
	const auto last_less = prev(first_not_less);

	// Если элементов, не меньших border, нет и set не пуст, то достаточно взять
	// итератор на последний элемент, меньший border
	if (first_not_less == numbers.end()) {
		return last_less;
	}

	// Разыменуем оба итератора-кандидата и выберем тот,
	// чей элемент ближе к искомому
	const bool is_left = (border - *last_less <= *first_not_less - border);
	return is_left ? last_less : first_not_less;
}*/


int main() {
	set<int> numbers = {1, 4, 6};
	cout <<
		*FindNearestElement(numbers, 0) << " " <<
		*FindNearestElement(numbers, 3) << " " <<
		*FindNearestElement(numbers, 5) << " " <<
		*FindNearestElement(numbers, 6) << " " <<
		*FindNearestElement(numbers, 100) << endl;

	set<int> empty_set;

	cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
	return 0;
}
