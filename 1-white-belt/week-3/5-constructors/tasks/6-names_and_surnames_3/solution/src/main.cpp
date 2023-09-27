#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Person {
public:
    Person (string first_name, string second_name, int year)
    {
        year_birth = year;
        ChangeFirstName(year, first_name);
        ChangeLastName(year, second_name);
    }
    // добавить факт изменения имени на first_name в год year
    void ChangeFirstName(int year, const string& name) {
        //  При получении на вход года, который меньше года рождения
        if (year < year_birth)
        {
            return;
        }
        names[year] = name;
    }
    // добавить факт изменения фамилии на last_name в год year
    void ChangeLastName(int year, const string& surname) {
        //  При получении на вход года, который меньше года рождения
        if (year < year_birth)
        {
            return;
        }
        surnames[year] = surname;
    }
        // получить все имена и фамилии по состоянию на конец года year
    string GetFullNameWithHistory(const int year) const {
        string first_name = getNameWithHistory(names, year);
        string last_name = getNameWithHistory(surnames, year);
        
        string full_name;   //  полное имя
        
        //  При получении на вход года, который меньше года рождения
        if (year < year_birth)
        {
            full_name = "No person";
        }
        //  К данному году не случилось ни одного изменения фамилии и имени
        else if (first_name == "" && last_name == "")
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
    int year_birth; //  год рождения
    
        /*
     * Возвращает строку - историю изменения имен/фамилий до выбранного года
     * Формируется в-р имен/фамилий присваиваемых до выбранного года.
     * После этого в-р преобразуется в строку ф-ей tranformVecToString()
     */
    string getNameWithHistory (const map<int, string>& names, int year) const
    {
        string name = "";
        vector<string> history_names;
        
        for (const auto& years: names)
        {
            if (years.first <= year)
            {
                if (history_names.size() == 0)
                {
                    history_names.push_back(years.second);
                }
                else if (history_names[history_names.size() - 1] != years.second)
                {
                    history_names.push_back(years.second);
                }
            }
            else
            {
                break;
            }
        }
        
        return tranformVecToString(history_names);
    }
    
    /*
     * Преобразует строковый в-р в строку 
     */
    string tranformVecToString (const vector<string>& vec_str) const
    {
        string hist_name;
        
        //  в-р непуст
        if (vec_str.size() > 0)
        {
            //  в-р состоит из одного эл-та, то этот эл-т и есть строка
            if (vec_str.size() == 1)
            {
                return vec_str[vec_str.size() - 1];
            }
            else
            {
                /* 
                 * цикл с конца (для того чтобы выводить в обратном хронологическом порядке)
                 * Но не с самого конца, а с предпоследнего эл-та.
                 * Последний эл-т добавится позже.
                 */
                for (int i = vec_str.size() - 2; i >= 0; i--)
                {
                    hist_name += vec_str[i];
                    //  добавляется запчтая пока не достигнем певрого эл-та
                    if (i > 0)
                    {
                        hist_name += ", ";
                    }
                }
                //  самое новое имя + все изменения до выбранного года
                hist_name = vec_str[vec_str.size() - 1] + " (" + hist_name + ')';
            }
        }
        
        return hist_name;
    }
};

int main(int argc, char** argv) {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    return 0;
}

