#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct datalist {
    std::string firstName;
    std::string lastName;
    std::string date;
    std::string payments;
};


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
    // для контроля точек
    bool point = false;

    for (int i = 0; i < payment.length(); ++i) {
        if (!std::isdigit(payment[i])) {
            // если это точка и она первая
            if (payment[i] == '.' && !point) {
                point = true;
                continue;
            }
            std::cout << "There is not a number, ";
            return false;
        }
    }

    return true;
}

// функция чтения из файла
void readFile(std::vector<datalist> &statements) {
    // создаем поток
    std::ifstream fileR;

    // дополнительная строка для чтения валют
    std::string currency;
    // пробуем открыть старый файл
    fileR.open("payments.txt");
    if (fileR.is_open()) {
        // очищаем вектор
        statements.clear();
        // переменная для контроля длины вектора
        int size;
        // если файл открыт, то читаем всё в вектор
        while (!fileR.eof()) {
            // определяем текущий размер вектора
            size = statements.size();
            // увеличиваем размер на единицу
            statements.resize(size + 1);
            // записываем данные в вектор
            fileR >> statements[size].firstName >> statements[size].lastName
                >> statements[size].date >> statements[size].payments >> currency;
            // проверяем, что не достигли конца списка
            if (statements[size].firstName == "") {
                // удаляем зря созданный элемент массива и выходим
                statements.pop_back();
                break;
            }
            // добавляем валюту в конце суммы платежа
            statements[size].payments += " " + currency;
        }
    }
    fileR.close();
}

// функция вывода в консоль ведомости
void showStatements(std::vector<datalist> &statements) {
    // читаем из файла данные
    readFile(statements);
    // выводим их на экран
    std::cout << "--------------------------------" << std::endl;
    for (int i = 0; i < statements.size(); ++i) {
        std::cout << statements[i].firstName << " " << statements[i].lastName << " "
            << statements[i].date << " " << statements[i].payments << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << std::endl;
}

void writeFile(std::vector<datalist> statements) {
    // дополнительные строки для проверки введенных данных
    std::string firstName, lastName, date, payments;

    // создаем поток для записи в режиме добавления новых строк в конец
    std::ofstream fileW("payments.txt",  std::ios::app);

    // принимаем и проверяем запись
    while (true) {

        // инструкция
        std::cout << "You need to enter data line by line" << std::endl;
        std::cout << "To stop recording, enter four zeros: \"0 0 0 0\"" << std::endl;
        std::cout << "The date is entered in the format \"DD.MM.YYYY\"" << std::endl;
        std::cout << std::endl;

        std::cout << "Input the data (first_name last_name date payments)" << std::endl;
        std::cout << "-> ";
        std::cin >> firstName >> lastName >> date >> payments;

        // проверяем условие выхода из режима записи
        if (firstName == "0" && lastName == "0" && date == "0" && payments == "0") {
            break;
        }

        // флаг верных значений данных
        bool correct = true;

        // проверяем дату
        if (!checkDate(date)) {
            std::cout << " of the date is incorrect!" << std::endl;
            correct = false;
        }

        // проверяем имя
        if (!checkName(firstName)) {
            std::cout << "in the first name!" << std::endl;
            correct = false;
        }

        // проверяем фамилию
        if (!checkName(lastName)) {
            std::cout << "int the last name!" <<  std::endl;
            correct = false;
        }

        // проверяем сумму
        if (!checkPayment(payments)) {
            std::cout << "in the payments!" <<std::endl;
            correct = false;
        }

        // если неверно что-то введено
        if (!correct) {
            std::cout << "Try again" << std::endl << std::endl;
            continue;
        }

        // записываем всё в структуру
        statements.push_back({firstName, lastName, date, payments + " RUB"});

        // записываем в файл последнюю запись структуры
        int size = statements.size() - 1;
        fileW << statements[size].firstName << " " << statements[size].lastName << " "
            << statements[size].date << " " << statements[size].payments << std::endl;

    }
    // закрываем поток на запись
    fileW.close();
}

int main() {

    // основной вектор данных
    std::vector<datalist> statements;
    // выбор пользователя
    std::string select;

    std::cout << "A program for recording payroll statements to a file" << std::endl;


    readFile(statements);

    while (true) {
        std::cout << "Enter the command (Enter \"help\" for a hint) -> ";
        std::cin >> select;

        // проверяем что выбрал пользователь
        if (select == "help") {
            std::cout << "\"list\" - Output the statement to the console" << std::endl;
            std::cout << "\"add\" - Mode for adding records to the statement" << std::endl;
            std::cout << "\"-1\" - Close the program" << std::endl;
        } else if (select == "list") {
            showStatements(statements);
        } else if (select == "add") {
            writeFile(statements);
        } else if (select == "-1") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}
