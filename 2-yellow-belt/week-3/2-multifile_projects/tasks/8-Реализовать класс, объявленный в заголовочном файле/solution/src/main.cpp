#include <iostream>
using namespace std;

#include "phone_number.h"

void Test(const string& number) {
	PhoneNumber pn(number);
	cout << pn.GetInternationalNumber() << endl;
}

int main() {
	try {
		//Test("+7-812-5985881");
		//Test("+7-812-598-58-81");
		//Test("+323-22-460002");
		//Test("+323-22-courcera-cpp");
		//Test("1-2-333");
		Test("+7-1233");
	}
	catch (exception& ex) {
		cout << "exception happens: " << ex.what();
	}

	return 0;
}
