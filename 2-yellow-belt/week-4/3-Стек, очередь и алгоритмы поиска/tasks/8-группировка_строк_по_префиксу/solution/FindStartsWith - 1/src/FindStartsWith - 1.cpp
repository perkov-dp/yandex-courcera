#include <iostream>
#include <string>
#include <utility>	//	pair
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

//	- принимает отсортированный набор строк в виде итераторов range_begin,
//	range_end и один символ prefix;
//	- возвращает диапазон строк, начинающихся с символа prefix,
//	в виде пары итераторов.
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix
) {
	/* Здесь исп-ся алгоитм equal_range ==
	 * make_pair(lower_bound (...), upper_bound (...))
	 * Рез-т equal_range = [lower_bound, upper_bound)
	 * Т.к. upper_bound возвращает итератор на эл-т строго больший >,
	 * а верхняя граница equal_range на <, то upper_bound д/указывать
	 * на следующий эл-т, чтобы включить последний эл-т из заданного диапазона,
	 * т.е. эл-т перед upper_bound
	 *
	 * Например
	 * "moscow", "murmansk", "vologda"
	 * lower_bound = moscow, upper_bound = murmansk
	 * Диапазон возвращаемых значений - [moscow, murmansk) -> moscow
	 * Поэтому upper_bound д/возвращать итератор на следующий эл-т,
	 * к-рый не входит в возвращаемый диапазон.
	 * Этот эл-т - следующая строка, первая буква к-рой нач-ся не с prefix.
	 * Тогда Диапазон возвращаемых значений - [moscow, vologda) -> moscow, murmansk*/

	/* Подсказка
	 * К символам (char) можно прибавлять или вычитать числа, получая таким образом
	 * следующие или предыдущие буквы в алфавитном порядке.
	 * Например, для строки s выражение --s[0] заменит её первую букву на
	 * предыдущую.
	 *
	 * Обратите внимание, что выражение 'a' + 1 имеет тип int и поэтому
	 * может понадобиться привести его к типу char с помощью static_cast. */
	//	next_symbol  - точная верхняя грань мн-ва строк, начинающихся с prefix
	char next_symbol = static_cast<char>(prefix + 1);

	//	string(1, prefix) преобразует char в строку для оператора <
	return {lower_bound (range_begin, range_end, string(1, prefix)),
		upper_bound (range_begin, range_end, string(1, next_symbol))};
}

int main() {
	const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

	const auto m_result =
			FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
	for (auto it = m_result.first; it != m_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto p_result =
			FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
	cout << (p_result.first - begin(sorted_strings)) << " " <<
			(p_result.second - begin(sorted_strings)) << endl;

	const auto z_result =
			FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
	cout << (z_result.first - begin(sorted_strings)) << " " <<
			(z_result.second - begin(sorted_strings)) << endl;

	return 0;
}
