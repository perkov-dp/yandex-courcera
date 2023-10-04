#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail "  << email << endl;
}

//	1. Абстрактный базовый класс INotifier, у которого будет один чисто виртуальный метод Notify.
class INotifier {
public:
	virtual void Notify(const string& message) const = 0;
};

/* 2. Класс SmsNotifier, который:
 * - является потомком класса INotifier;
 * - в конструкторе принимает один параметр типа string — номер телефона;
 * - переопределяет метод Notify и вызывает из него функцию SendSms. */
class SmsNotifier : public INotifier {
public:
	SmsNotifier(const string& phone_number) : phone_number_(phone_number) {}
	void Notify (const string& message) const override {
		SendSms(phone_number_, message);
	}
private:
	string phone_number_;
};

/* 3. Класс EmailNotifier, который:
 * - является потомком класса INotifier;
 * - в конструкторе принимает один параметр типа string — адрес электронной почты;
 * - переопределяет метод Notify и вызывает из него функцию SendEmail. */
class EmailNotifier : public INotifier {
public:
	EmailNotifier(const string& e_mail) : e_mail_(e_mail) {}
	void Notify (const string& message) const override {
		SendEmail(e_mail_, message);
	}
private:
	string e_mail_;
};

void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}

int main() {
	SmsNotifier sms{"+7-495-777-77-77"};
	EmailNotifier email{"na-derevnyu@dedushke.ru"};

	Notify(sms, "I have White belt in C++");
	Notify(email, "And want a Yellow one");
	return 0;
}
