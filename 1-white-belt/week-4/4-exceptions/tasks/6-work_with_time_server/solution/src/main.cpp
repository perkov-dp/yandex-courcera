#include <cstdlib>
#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
    string ret_str = "OK";
    int flag = 2;
    
    if (flag == true)
    {
        return ret_str;
    }
    else if (flag == false)
    {
        throw system_error(error_code());
    }
    else
    {
        throw runtime_error("AskTimeServer(): неизвестная ошибка");
    }
}

class TimeServer {
public:
    string GetCurrentTime() {
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            * поля LastFetchedTime
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
        
        try{
            last_fetched_time = AskTimeServer();
            return last_fetched_time;
        }catch (system_error& e){
            std::cout << "Caught system_error with code " << e.code() 
                  << " meaning " << e.what() << endl;
            
            return last_fetched_time;
        }   
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: "<< e.what() << endl;
    }
    return 0;
}

