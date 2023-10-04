#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    explicit Person(const string& name) : Name(name)
    {
    }
    virtual ~Person() = default;
    virtual void Walk(const string& destination) const = 0;

    const string Name;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong) : Person(name) {
        FavouriteSong = favouriteSong;
    }

    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    string FavouriteSong;
};


class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject) : Person(name) {
        Subject = subject;
    }

    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Teacher: " << Name << " walks to: " << destination << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    explicit Policeman(const string& name) : Person(name)
    {
    }

    void Check(const Teacher& t) {
        cout << "Policeman: " << Name << " checks Teacher. Teacher's name is: " << t.Name << endl;
    }

    void Check(const Student& s) {
        cout << "Policeman: " << Name << " checks Student. Student's name is: " << s.Name << endl;
    }

    void Check(const Policeman& p) {
        cout << "Policeman: " << Name << " checks Policeman. Policeman's name is: " << p.Name << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Policeman: " << Name << " walks to: " << destination << endl;
    }
};


void VisitPlaces(const Person& t, const vector<string>& places) {
    for (const auto& p : places) {
        t.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});

    return 0;
}
