#include <cstdlib>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Person {
public:
    // добавить факт изменения имени на first_name в год year
    void ChangeFirstName(int year, const string& name) {
        names[year] = name;
    }
    // добавить факт изменения фамилии на last_name в год year
    void ChangeLastName(int year, const string& surname) {
        surnames[year] = surname;
    }
    // получить имя и фамилию по состоянию на конец года year
    string GetFullName(int year) {
        string first_name = findNameByYear(names, year);
        string last_name = findNameByYear(surnames, year);
        
        string full_name;
        
        //  К данному году не случилось ни одного изменения фамилии и имени
        if (first_name == "" && last_name == "")
        {
            full_name = "Incognito";
        }
        //  К данному году случилось изменение имени, 
        //  но не было ни одного изменения фамилии
        else if (first_name != "" && last_name == "")
        {
            full_name = first_name + " with unknown last name";
        }
        //  К данному году случилось изменение фамилии, 
        //  но не было ни одного изменения имени
        else if (first_name == "" && last_name != "")
        {
            full_name = last_name + " with unknown first name";
        }
        else if (first_name != "" && last_name != "")
        {
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
    string findNameByYear (const map<int, string>& names, int year)
    {
        string name = "";
        
        for (const auto& i: names)
        {
            //  если до этого года были изменения
            //  Т.к. map отсортирован по возрастанию. 
            //  Соотв-нно если самый раниий год в map > текущего года, 
            //  то не было никаких записей об этом имени/фамилии
            if (i.first <= year)
            {
                name = i.second;
            }
            else 
            {
                break;
            }
        }
        return name;
    }
};

int main(int argc, char** argv) {
    Person person;
  
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
      cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
      cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
      cout << person.GetFullName(year) << endl;
    }

    return 0;
}

