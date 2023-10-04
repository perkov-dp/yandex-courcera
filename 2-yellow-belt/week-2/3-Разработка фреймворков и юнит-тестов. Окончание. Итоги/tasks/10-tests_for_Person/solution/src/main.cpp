#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Person {
public:
    // добавить факт изменения имени на first_name в год year
    void ChangeFirstName(int year, const string& name) {
    	//	за один год не более одного измененния
    	if (names.count(year) == 0) {
    		names[year] = name;
    	}
    }
    // добавить факт изменения фамилии на last_name в год year
    void ChangeLastName(int year, const string& surname) {
    	//	за один год не более одного измененния
    	if (surnames.count(year) == 0) {
    		surnames[year] = surname;
    	}
    }
    // получить имя и фамилию по состоянию на конец года year
    string GetFullName(int year) {
        string first_name = findNameByYear(names, year);
        string last_name = findNameByYear(surnames, year);

        string full_name;

        //  К данному году не случилось ни одного изменения фамилии и имени
        if (first_name == "" && last_name == "") {
            full_name = "Incognito";
        }
        //  К данному году случилось изменение имени,
        //  но не было ни одного изменения фамилии
        else if (first_name != "" && last_name == "") {
            full_name = first_name + " with unknown last name";
        }
        //  К данному году случилось изменение фамилии,
        //  но не было ни одного изменения имени
        else if (first_name == "" && last_name != "") {
            full_name = last_name + " with unknown first name";
        }
        else if (first_name != "" && last_name != "") {
            full_name = first_name + ' ' + last_name;
        }

        return full_name;
    }
private:
    //  приватные поля
    //  ключ - год изменения имени или фамилии
    map<int, string> names;
    map<int, string> surnames;

    //  Находим имя и фамилию по году
    //  Принимает на вход год и словарь «год → имя/фамилия».Возвращает имя/фамилию,
    //  соответствующую данному году
    //  Возвращает последнее на момент года имя/фамилию
    string findNameByYear (const map<int, string>& names, int year) {
        string name = "";

        for (const auto& i: names) {
            //  если до этого года были изменения
            //  Т.к. map отсортирован по возрастанию.
            //  Соотв-нно если самый раниий год в map > текущего года,
            //  то не было никаких записей об этом имени/фамилии
            if (i.first <= year) {
                name = i.second;
            } else {
                break;
            }
        }
        return name;
    }
};

void Test_surname_before_name() {
	Person person;

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeFirstName(1967, "Polina");

    AssertEqual(person.GetFullName(1964), "Incognito");	//	до внесения в базу
    AssertEqual(person.GetFullName(1966), "Sergeeva with unknown first name");	//	внесли фамилию
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");	//	внесли имя и фамилию
}

void Test_predefined() {
	Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1964), "Incognito");	//	до внесения в базу
    AssertEqual(person.GetFullName(1965), "Polina with unknown last name");	//	внесли только имя
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");	//	внесли имя и фамилию

    person.ChangeFirstName(1970, "Appolinaria");
    AssertEqual(person.GetFullName(1969), "Polina Sergeeva");		//	до изменения имени
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva");	//	в год изменения имени
    AssertEqual(person.GetFullName(1971), "Appolinaria Sergeeva");	//	после изменения имени

    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1967), "Polina Sergeeva");		//	до изменения фамилии
    AssertEqual(person.GetFullName(1968), "Polina Volkova");		//	в год изменения фамилии
    AssertEqual(person.GetFullName(1971), "Appolinaria Volkova");	//	после изменения фамилии и имени
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(Test_surname_before_name, "Test_surname_before_name");
  runner.RunTest(Test_predefined, "Test_predefined");

  return 0;
}
