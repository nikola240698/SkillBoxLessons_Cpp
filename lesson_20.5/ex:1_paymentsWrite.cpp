#include <iostream>
#include <fstream>
#include <string>

// проверка на високосный год
bool isLeapYear (const int &year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// проверка правильного введения даты
bool checkDay(const int &day, const int &month, const int &year) {
  
    if (year < 1900 || year > 2026) {
        std::cout << "Year ";
        return false;
    }

    if (month <= 0 || month > 12) {
        std::cout << "Month ";
        return false;
    }

    int dayOfMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeapYear(year)) {
        dayOfMonth[1] = 29;
    }

    if (day <= 0 || day >> dayOfMonth[month - 1]) {
        std::cout << "Day ";
        return false;
    }
    return true;
}

bool checkDate(const std::string &date) {

    // проверяем длину введенной даты
    if (date.length() != 10) {
        std::cout << "Length";
        return false;
    }

    // проверяем наличие и позицию точки
    int pointCo = 0;
    for (int i = 0; i < date.length(); ++i) {
        if (date[i] == '.') {
            ++pointCo;
            if (!(i == 2 || i == 5)) {
                std::cout << "Point";
                return false;
            }
        }
    }    
  
    if (pointCo != 2) {
        std::cout << "Point";
        return false;
    }

    // извлекаем численные данные из даты
    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    // проверяем правильно введенную дату
    return checkDay(day, month, year);
}

// проверяем правильно введенное имя или фамилию
bool checkName(const std::string &name) {

    for (int i = 0; i < name.length(); ++i) {
        if (std::isdigit(name[i])) {
            std::cout << "There is a digit, ";
            return false;
        }
        if (std::isupper(name[i]) && i != 0) {
            std::cout << "There is a extra UpperCase word, ";
            return false;
        }
    }

    return true;
}

// проверяем корректность введения выплат
bool checkPayment(const std::string &payment) {

    for (int i = 0; i < payment.length(); ++i) {
        if (!std::isdigit(payment[i])) {
            std::cout << "There is not a number, ";
            return false;
        }
    }

    return true;
}


int main() {

    std::string firstName, lastName, date, payments, record;
    std::string path;
    std::ofstream file;

    std::cout << "A program for recording payroll statements to a file" << std::endl;
    std::cout << "You need to enter data line by line" << std::endl;
    std::cout << "To stop recording, enter four zeros: \"0 0 0 0\"" << std::endl;
    std::cout << "The date is entered in the format \"DD.MM.YYYY\"" << std::endl;
    std::cout << std::endl;

    // пытаемся открыть файл
    while (true) {
        // вводим путь к файлу
        std::cout << "Input the path of the file, it \"txt\" format: " << std::endl;
        std::cout << "-> ";
        std::cin >> path;

        // пробуем открыть файл на запись и проверяем
        file.open(path);
        if (file.is_open()) {
            break;
        }
        std::cout << "Incorrect path of the file! Try again:" << std::endl;
    }

    // принимаем и проверяем запись
    while (true) {
        std::cout << "Input the data (first_name last_name date payments)" << std::endl;
        std::cout << "-> ";
        std::cin >> firstName >> lastName >> date >> payments;

        if (firstName == "0" && lastName == "0" && date == "0" && payments == "0") {
            break;
        }

        bool correct = true;

        if (!checkDate(date)) {
            std::cout << " of the date is incorrect!" << std::endl;
            correct = false;
        }

        if (!checkName(firstName)) {
            std::cout << "in the first name!" << std::endl;
            correct = false;
        }

        if (!checkName(lastName)) {
            std::cout << "int the last name!" <<  std::endl;
            correct = false;
        }

        if (!checkPayment(payments)) {
            std::cout << "in the payments!" <<std::endl;
            correct = false;
        }

        if (!correct) {
            std::cout << "Try again" << std::endl << std::endl;
            continue;
        }

        // создаем сроку на запись;
        record = firstName + " " + lastName + " " + date + " " + payments + "RUB";

        // записываем в файл
        file << record << std::endl;
        std::cout << "The recording was successful" << std::endl;
    }
    
    // закрываем файл
    file.close();
    std::cout << "End of writing data to file" << std::endl;

    return 0;
}
