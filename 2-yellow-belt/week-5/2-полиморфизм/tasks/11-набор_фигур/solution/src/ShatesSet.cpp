#include <iostream>
#include <string>
#include <vector>
#include <memory> 	// заголовок с shared_ptr
#include <sstream>	//	std::ws
#include <iomanip>	//	setprecision
#include <cmath>

using namespace std;

//	- базовый класс Figure с чисто виртуальными методами Name, Perimeter и Area;
class Figure {
public:
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

/* - классы Triangle, Rect и Circle, которые являются наследниками класса Figure и
 * переопределяют его виртуальные методы; */
class Triangle : public Figure {
public:
	Triangle (int a, int b, int c) : a_(a), b_(b), c_(c) {}
	string Name() override {
		return name_;
	}
	double Perimeter() override {
		return a_ + b_ + c_;
	}
	double Area() override {
		const double half_per = (a_ + b_ + c_) / 2;
		return sqrt(half_per * (half_per - a_) * (half_per - b_) * (half_per - c_));
	}
private:
	const string name_ = "TRIANGLE";
	int a_, b_, c_;
};

class Rect : public Figure {
public:
	Rect (int width, int hidth) : width_(width), hidth_(hidth) {}
	string Name() override {
		return name_;
	}
	double Perimeter() override {
		return 2 * (width_ + hidth_);
	}
	double Area() override {
		return width_ * hidth_;
	}
private:
	const string name_ = "RECT";
	int width_, hidth_;
};

class Circle : public Figure {
public:
	Circle (double radius) : radius_(radius) {}
	string Name() override {
		return name_;
	}
	double Perimeter() override {
		return 2 * pi_ * radius_;
	}
	double Area() override {
		return pi_ * radius_ * radius_;
	}
private:
	const double pi_ = 3.14;
	const string name_ = "CIRCLE";
	int radius_;
};

shared_ptr<Figure> CreateFigure(istream& is) {
	string name;
	is >> name;
	if (name == "RECT") {
		int width, hidth;
		is >> width >> hidth;
		return make_shared<Rect>(width, hidth);
	}
	else if (name == "TRIANGLE") {
		int a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);
	}
	else if (name == "CIRCLE") {
		int radius;
		is >> radius;
		return make_shared<Circle>(radius);
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line);) {
		istringstream is(line);

	    string command;
	    is >> command;
	    if (command == "ADD") {
	    	// Пропускаем "лишние" ведущие пробелы.
	    	// Подробнее об std::ws можно узнать здесь:
	    	// https://en.cppreference.com/w/cpp/io/manip/ws
	    	is >> ws;
	    	figures.push_back(CreateFigure(is));
	    } else if (command == "PRINT") {
	    	for (const auto& current_figure : figures) {
	    		cout << fixed << setprecision(3)
	            	 << current_figure->Name() << " "
					 << current_figure->Perimeter() << " "
					 << current_figure->Area() << endl;
	     }
	   }
	}
	return 0;
}
