#include <cstdlib>
#include <string>
using namespace std;

/*
 * Ключевое слово explicit заставляет явно вызывать конструктор.
 * Такой код исп-ть теперь нельзя.
 * Date date = {10, 11, 12};
 * Date date = {{10}, {11}, {12}};
 * 
 * Ключевое слово explicit не позволяет вызывать конструктор неявно
 * Это вынуждает записать такой код: 
 * Date date = {Day(10), Month(11), Year(12)};
 */
struct Specialization{
    string spec;
    explicit Specialization (const string& new_str)
    {
        spec = new_str;
    }
};

struct Course{
    string cource;
    explicit Course (const string& new_str)
    {
        cource = new_str;
    }
};

struct Week{
    string week;
    explicit Week (const string& new_str)
    {
        week = new_str;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle (Specialization new_srec, Course new_cource, Week new_week)
    {
        specialization = new_srec.spec;
        course = new_cource.cource;
        week = new_week.week;
    }
};

int main(int argc, char** argv) {
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );


    return 0;
}

