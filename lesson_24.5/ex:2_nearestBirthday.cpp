// идея такая, что надо создать std::multimap<int, std::string>
// и ключами будут даты переведенные в int, чтобы сортировать их по возрастанию
// при чем первой цифрой всегда будет 1, чтобы не сокращать даты
// начинающиеся с однозначного числа, например
// дата 1998/09/04 будет храниться как 10904, так как год тут нам не важен
// то есть YYYY/MM/DD -> 1MMDD

#include <iostream>
#include <ctime>
#include <map>
#include <vector>
#include <sstream>

// проверка года на високосность
bool isLeapYear(const int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// проверка всей даты
bool isValidDate(const int day,const int month,const int year) {
    // проверка диапазона года и месяца
    if (year < 1 || month < 1 || month > 12) {
        std::cout << "Incorrect number of month" << std::endl;
        return false;
    }
    // определение количества дней в месяце
    int daysInMonth = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else if (month == 2) {
        daysInMonth = isLeapYear(year) ? 29 : 28;
    }
    // проверка дня
    if (day >= 1 && day <= daysInMonth) {
        return true;
    } else {
        std::cout << "Incorrect number of day" << std::endl;
        return false;
    }
}

// разбиваем введенную дату на год месяц и число отдельно
std::vector<int> parsingDate(const std::string &str) {
    // вектор для хранения
    std::vector<int> container;
    // переменные для чтения строки
    std::stringstream ss(str);
    std::string date;
    // записываем в контейнер числа отдельно
    while (std::getline(ss, date,'/')) {
        container.push_back(std::stoi(date));
    }
    return container;
}

// проверка введенной даты и парсинг ее на составляющие
bool checkBirth(const std::string &str, std::vector<int> &container) {
    // если длина и формат не сходятся с макетом YYYY/MM/DD
    if (str.length() != 10 || (str[4] != '/' && str[7] != '/')) {
        std::cout << "Incorrect format!" << std::endl;
        return false;
    }
    // проверяем, что все остальные это цифры
    for (int i = 0; i < str.length(); ++i) {
        // пропускаем разделители
        if (i == 4 || i == 7) {
            continue;
        }
        if (!std::isdigit(str[i])) {
            std::cout << "There are no digits" << std::endl;
            return false;
        }
    }
    // разбиваем строку на составляющие
    container = parsingDate(str);
    // проверяем, что введенная дата существует
    return isValidDate(container[2], container[1], container[2]);
}

// вставка записи в std::multimap
void insertBirth(std::multimap<int, std::string> &map, const std::string &name,
        const std::vector<int> &container) {
    // превращаем дату в целочисленное значение
    int date = 10000 + container[1] * 100 + container[2];
    // вставляем в словарь
    map.insert(std::pair<int, std::string>(date, name));
}

// поиск ближайшего дня рождения
void findNearest(std::multimap<int, std::string> &map,const int &nowDate) {
    // вставляем запись в словарь, ищем его итератор
    // увеличиваем итератор на 1, и смотрим кто там
    map.insert(std::pair<int, std::string>{nowDate, "Today"});
    std::multimap<int, std::string>::iterator it = map.find(nowDate);
    // проверяем, что сегодняшний день не последний в списке
    if (++it != map.end()) {
        std::cout << "Birthday is coming soon:" << std::endl;
        auto range = map.equal_range(it->first);
        for (auto it = range.first; it != range.second; ++it) {
            // выводим имя и дату ближайших ДР
            std::cout << it->second << " ";
            // достаем число из ключа
            int birth = it->first;
            // формируем число дня и месяца
            int birthDay = birth % 100;
            birth /= 100;
            int birthMonth = birth % 100;
            // красиво выводим в консоль, учитывая нули в датах
            if (birthMonth < 10) {
                std::cout << "0";
            }
            std::cout << birthMonth << "/";
            if (birthDay < 10) {
                std::cout << "0";
            }
            std::cout << birthDay << std::endl;
        }
        std::cout << std::endl;
    } else {
        // если нет дней рождения скоро
        std::cout << "There are no upcoming birthdays this year" << std::endl;
    }
}

// функция создания записи о текущей дате
void todayDate(std::multimap<int, std::string> &map) {
    // определяем время
    std::time_t tm = std::time(nullptr);
    std::tm* local = std::localtime(&tm);
    // получаем значения нужных частей структуры
    int curMonth = local->tm_mon + 1;
    int curDay = local->tm_mday;
    // формируем ключ текущего дня
    int nowDate = 10000 + curMonth * 100 + curDay;
    // проверяем, нет ли ДР сегодня у кого-нибудь
    if (map.contains(nowDate)) {
        std::cout << "Today's birthday persons: ";
        auto range = map.equal_range(nowDate);
        for (auto it = range.first; it != range.second ; ++it) {
            std::cout << it->second << " ";
        }
        std::cout << std::endl;
    } else {
        // если сегодня нет, то ищем ближайшее
        findNearest(map, nowDate);
    }
}

int main() {   
    std::cout << "A program for show nearest birthday!" << std::endl;
    std::cout << std::endl;

    std::multimap<int, std::string> birthDay;
    // строки для ввода данных
    std::string name, birth;
    // контейнер для записи чисел
    std::vector<int> container(3);

    // основной цикл ввода
    while (true) {
        // очищаем вектор для новой записи
        container.clear();
        // вводим имя
        std::cout << "Input the name of person (\"end\" for exit) ->";
        std::cin >> name;
        // условие выхода
        if (name == "end") {
            break;
        }
        // цикл ввода даты с проверкой
        do {
            std::cout << "Input the Date of birth" << std::endl;
            std::cout << "In format: NAME YYYY/MM/DD" << std::endl;
            std:: cout << "-> ";
            std::cin >> birth;
        } while (!checkBirth(birth, container));        
        insertBirth(birthDay, name, container);
    }
    todayDate(birthDay);

    return 0;
}
