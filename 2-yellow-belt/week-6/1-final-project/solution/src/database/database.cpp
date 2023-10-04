#include <iostream>

#include "database.h"

//	Добавление события по ключу (дате). Если такое же событие уже есть в эту дату, то ничего не добавляется
void Database::Add(const Date& date, const string& event) {
    if (db[date].second.count(event) == 0) {
        db[date].second.emplace(event);
        db[date].first.emplace_back(event);
    }
}

void Database::Print(ostream& out) const {
    if (db.size() == 0) {
        out << "Data base is empty" << endl;
    } else {
        for (const auto& [date, events]: db) {
            for (const auto& ev: events.first) {
                out << date << ' ' << ev << endl;
            }
        }
    }
}

string Database::Last(const Date& date) const {
    stringstream ss;

    auto it_upper = db.upper_bound(date);
    if (it_upper == db.begin()) {
        return "No entries";
    }
    auto it = prev(it_upper);

    return it->first.DateToString() + ' ' + it->second.first.back();
}