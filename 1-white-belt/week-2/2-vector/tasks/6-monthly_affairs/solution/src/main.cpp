#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

/*
 * У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых
 * нужно выполнять в конкретный день каждого месяца: 
 * оплата счетов за электричество, абонентская плата за связь и пр. 
 * Вам нужно реализовать работу со списком таких дел на месяц, 
 * а именно, реализовать набор следующих операций:

 * ADD i s
 * Назначить дело с названием s на день i текущего месяца.

 * DUMP i
 * Вывести все дела, запланированные на день i текущего месяца.

 * NEXT
 * Перейти к списку дел на новый месяц. При выполнении данной команды вместо 
 * текущего (старого) списка дел на текущий месяц создаётся и 
 * становится активным (новый) список дел на следующий месяц: 
 * все дела со старого списка дел копируются в новый список. 
 * После выполнения данной команды новый список дел и следующий месяц становятся текущими, 
 * а работа со старым списком дел прекращается. 
 * При переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах:

 * 1) если следующий месяц имеет больше дней, чем текущий, 
 * «дополнительные» дни необходимо оставить пустыми (не содержащими дел);
 * 2) если следующий месяц имеет меньше дней, чем текущий, меньше дней, 
 * дела со всех «лишних» дней необходимо переместить на последний день следующего месяца.

 * Далее см. в файл задания, лежащий в папке проекте
 */ 

void AddDayAffair (vector <vector <string> >& day_affairs, const string& affair, 
         const int& day_number)
{
    //  память выделили до этого
    day_affairs[day_number].push_back(affair);
}

void PrintDayAffairs (vector <vector <string> >& day_affairs, 
        const int& day_number)
{
    for (auto i : day_affairs[day_number])
    {
        cout << i << ' ';
    }   
}

int main(int argc, char** argv) {
    int kolOperations = 0;
    cin >> kolOperations;
    string command;
    string affair_name;
    int day_number = 1;
    int cur_month = 0;
    
    //  Создаем в-р кол-ва дней в к-дом месяце
    vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //  Создаем в-р ежедневных дел
    vector < vector <string> > day_affairs (days_in_months[cur_month]);

    for (int i = 0; i < kolOperations; i++)
    {
        cin >> command;
        if (command == "ADD")
        {
            cin >> day_number >> affair_name;
            day_number--;
            AddDayAffair (day_affairs, affair_name, day_number);
        }
        else if (command == "DUMP")
        {
            cin >> day_number;
            day_number--;
            PrintDayAffairs(day_affairs, day_number);
        }
        else if (command == "NEXT")
        {
            cur_month++;
            if (cur_month > 11)
                cur_month = 0;
            /* 
             * Если кол-во дней в текущем месяце > чем в предыдущем, то
             * копируем весь в-р в новый, а оставшиеся дни заполняем 0
             */ 
            if (days_in_months[cur_month] > days_in_months[cur_month - 1])
            {
                day_affairs.resize(days_in_months[cur_month]);
            }
            else
            {
                vector < vector <string> > new_day_affairs (days_in_months[cur_month - 1]);
                new_day_affairs = day_affairs;
                
                day_affairs.resize(days_in_months[cur_month]);
                for (int j = days_in_months[cur_month]; j < days_in_months[cur_month - 1]; j++)
                {
                    day_affairs[days_in_months[cur_month] - 1].insert
                        (end(day_affairs[days_in_months[cur_month] - 1]), 
                            begin(new_day_affairs[j]), 
                            end (new_day_affairs[j]));                    
                }
                new_day_affairs.clear();
            }       
        }      
    }
    
    return 0;
}

