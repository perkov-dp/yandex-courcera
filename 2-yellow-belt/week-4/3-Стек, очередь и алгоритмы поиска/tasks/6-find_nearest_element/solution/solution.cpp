#include <iterator>
#include <set>

set<int>::const_iterator FindNearestElement(const set<int>& numbers,
                                            int border) {
  // ����������� �������� �� ������ �������, �� ������� border;
  // ���� ������ �������� ���, �� �� ������� numbers.end()
  // set::lower_bound ->
  // http://ru.cppreference.com/w/cpp/container/set/lower_bound
  const auto first_not_less = numbers.lower_bound(border);

  // ���� ��������� ����� ��� �� ������� �������� �� ������ border
  // ��� ���������, �� �� ��� �������� �����
  if (first_not_less == numbers.begin()) {
    return first_not_less;
  }

  // ���� ���������, �� ������� border, ��� � set �� ����, �� ���������� �����
  // �������� �� ��������� �������, ������� border
  // prev -> http://ru.cppreference.com/w/cpp/iterator/prev
  const auto last_less = prev(first_not_less);
  if (first_not_less == numbers.end()) {
    return last_less;
  }

  // ���������� ��� ���������-��������� � ������� ���,
  // ��� ������� ����� � ��������
  const bool is_left = (border - *last_less <= *first_not_less - border);
  return is_left ? last_less : first_not_less;
}
