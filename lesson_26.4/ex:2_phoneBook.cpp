#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Contact {
    std::string name{};
    std::string number{};

public:
    // инициализируем данные
    Contact(std::string  name, std::string  number)
        : name(std::move(name)), number(std::move(number)) {}

    std::string getName() {
        return name;
    }

    std::string getNumber() {
        return number;
    }
};

class PhoneBook {

    std::vector<Contact> phoneBook;

    // определяем что ввел пользователь, если номер, то сразу работаем с ним
    // если имя - то ищем его в базе и определяем на какой номер звонить
    std::string takeNumber(std::string& data) {
        // проверяем, что введен номер
        if (isPhoneNumber(data)) {
            return data;
        }

        // если это не номер, то ищем по имени в справочнике
        for (int i = 0; i < phoneBook.size(); ++i) {
            if (phoneBook[i].getName() == data) {
                return phoneBook[i].getNumber();
            }
        }
        // иначе возвращаем пустую строку
        return "";
    }

public:
    // проверяем корректность введенного номера
    bool isPhoneNumber(const std::string& data) const {
        if (data.size() != 12 || data[0] != '+' || data[1] != '7') {
            return false;
        }

        for (int i = 2; i < data.size(); ++i) {
            if (!isdigit(data[i])) {
                return false;
            }
        }
        return true;
    }

    // метод добавления записи в книгу
    void addContact() {
        // строки для имени и номера
        std::string name, number;
        // получаем данные от пользователя
        std::cout << "Input the name of the contact -> ";
        std::getline(std::cin, name);
        do {
            std::cout << "Input the phone number if format +7XXXXXXXXXX -> ";
            std::getline(std::cin, number);
        } while (!isPhoneNumber(number));
        // добавляем в телефонную книгу
        phoneBook.push_back(Contact(name, number));
        std::cout << "The contact was added successfully" << std::endl;
    }

    // метод вызова звонка
    void call() {
        std::string data;
        std::cout << "Input the name or the number ->";
        std::getline(std::cin, data);

        std::string phoneNumber = takeNumber(data);

        // проверяем если строка пустая
        if (phoneNumber.empty()) {
            std::cout << "The name or number you entered was not found" << std::endl;
            return;
        }
        std::cout << "CALL " << phoneNumber << std::endl;
    }

    // метод отправки смс
    void sms() {
        std::string data;
        std::cout << "Input the name or the number ->";
        std::getline(std::cin, data);

        std::string phoneNumber = takeNumber(data);
        // проверяем если строка пустая
        if (data.empty()) {
            std::cout << "The name or number you entered was not found" << std::endl;
            return;
        }
        std::string message;
        std::cout << "Input your message:" << std::endl;
        std::getline(std::cin, message);

        std::cout << "Send to " << phoneNumber << " message: " << message << std::endl;
    }
};

int main() {

    PhoneBook* phoneBook = new PhoneBook;
    std::string command;

    while (true) {
        std::cout << "Input your command ->";
        std::getline(std::cin, command);
        if (command == "add") {
            phoneBook->addContact();
        } else if (command == "call") {
            phoneBook->call();
        } else if (command == "sms") {
            phoneBook->sms();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Incorrect command" << std::endl;
        }
    }

    delete phoneBook;
    return 0;
}
