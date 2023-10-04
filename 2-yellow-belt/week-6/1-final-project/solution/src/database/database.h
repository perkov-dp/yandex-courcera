#pragma once

#include "../date/date.h"

#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Database {
public:
    //	Добавление события по ключу (дате). Если такое же событие уже есть в эту дату, то ничего не добавляется
    void Add(const Date& date, const string& event);

    template<typename UnaryPredicate>
    vector<pair<Date, string>> FindIf(UnaryPredicate pred) const {
        vector<pair<Date, string>> result;

        for (const auto& [date, events]: db) {
            for_each(events.first.begin(), events.first.end(),
                [&](const string &event) {
                    if (not pred(date, event)) {
                        return false;
                    }
                    result.emplace_back(date, event);
                    return true;
                }
            );
        }

        return result;
    }

    //	вывод всей БД в отсортированном порядке. Это обеспечивается конструкциями map и set
    void Print(ostream& out) const;

    string Last(const Date& date) const;

    template<typename UnaryPredicate>
    int RemoveIf(UnaryPredicate pred) {
        int count = 0;
        for (auto& [date, events] : db) {
            vector<string>& events_on_added_order = events.first;
            set<string>& events_on_exp_order = events.second;

            auto remove_it = stable_partition(events_on_added_order.begin(), events_on_added_order.end(),
                [&](const string &event) {
                return not pred(date, event);
            });
            if (remove_it != events_on_added_order.end()) {
                count += distance(remove_it, events_on_added_order.end());

                for (auto it = remove_it; it < events_on_added_order.end(); it++) {
                    events_on_exp_order.erase(*it);
                }

                events_on_added_order.erase(remove_it, events_on_added_order.end());
            }
        }

        for (auto it = db.begin(); it != db.end(); ) {
            if (it->second.first.empty()) {
                it = db.erase(it);
            } else {
                ++it;
            }
        }

        return count;
    }
private:
    map <Date, pair<vector<string>, set<string>>> db;
    map <Date, set<string>> db_unique;
    map <Date, vector<string>> db_on_added_order;
};
