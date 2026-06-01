#include <iostream>
#include <map>
#include <string>

// проверяем корректно введенный номер
bool checkNumber(const std::string &number) {
    // флаг для проверки
    bool numFlag = true;
    // проверяем что тире имеется в правильных местах и длину номера
    if ((number[2] != '-' || number[5] != '-') && number.length() == 8) {
        numFlag = false;
    } else {
        // проверяем, что остальные места заняты цифрами
        for (int i = 0; i < number.length(); i++) {
            if (!std::isdigit(number[i])) {
                if ((i == 2 || i == 5) && number[i] == '-') {
                } else {
                    numFlag = false;
                }
            }
        }
    }
    // проверяем что всё нормально
    if (!numFlag) {
        std::cout << "Incorrect phone number" << std::endl;
        return numFlag;
    }
    return true;
}

// функция создания пары из введенных данных
bool createPair(const std::string &str, std::pair<std::string, std::string> &p) {
    // создаем строки с заполнением в них данных
    std::string number = str.substr(0, 8);
    std::string subscriber = str.substr(9);

    if (checkNumber(number)) {
        p = {number, subscriber};
        return true;
    }
    return false;
}

bool parsingStr(const std::string &str, std::pair<std::string, std::string> &p) {
    // проверяем, что записан только номер и фамилия через пробел
    bool space = false;
    bool error = false;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && space) {
            std::cout << "Incorrect data! Try again" << std::endl;
            error = true;
            break;
        }
        if (str[i] == ' ' && !space) {
            space = true;
        }
    }
    if (error) {
        return false;
    }

    // определяем, что за строка на входе: данные для записи или поиска
    if (space && std::isdigit(str[0])) {
        if (createPair(str, p)) {
            return true;
        }
        return false;
    }
    if (std::isdigit(str[0]) && checkNumber(str)) {
        p = {str, ""};
        return true;;
    }
    if (!std::isdigit(str[0])) {
        p = {"", str};
        return true;
    }
    return false;
}

// вставка новой записи с проверкой имеющейся по ключу
void findInsert(std::map<std::string, std::string> &map, std::multimap<std::string, std::string> &mapMult,
        std::pair<std::string, std::string> &p) {
    // Проверяем, если есть такой номер уже в справочнике
    if (map.contains(p.first)) {
        // если есть совпадение, то добавляем при согласии
        while (true) {
            std::cout << "This number is already taken by another subscriber" << std::endl;
            std::cout << "Would you like to replace it (y/n)?" << std::endl;
            std::cout << "-> ";
            std::string answ;
            std::getline(std::cin, answ);
            // при согласии на замену
            if (answ == "y") {
                // находим диапазон итераторов по данным ключа для multimap
                auto range = mapMult.equal_range(map.at(p.first));                
                // удаляем ключ при совпадении 
                for (auto it = range.first; ; ++it) {
                    if (it->second == p.first) {
                        mapMult.erase(it);
                        break;
                    }
                    if (it == range.second) {
                        break;
                    }
                }
                mapMult.insert(std::pair<std::string, std::string>(p.second, p.first));
                // используем [] для точной замены значения по ключу в map
                map[p.first] = p.second;
                std::cout << "The entry has been added to the book" << std::endl;
                return;
            }
            if ( answ == "n") {
                // если отказался - выходим просто
                return;
            }
            // в случае ввода других символов
            std::cout << "Incorrect answer!" << std::endl;
        }
    }
    // если нет совпадения, то просто вставляем новую запись
    map.insert(p);
    mapMult.insert(std::pair<std::string, std::string> {p.second, p.first});

    std::cout << "The entry has been added to the book" << std::endl;
}

int main() {

    std::cout << "This program is a telephone directory!" << std::endl << std::endl;
    std::cout << "You can both add and search for records" << std::endl;
    std::cout << "To add a record, enter the phone number and " << std::endl;
    std::cout <<"last name of the subscriber in the format" << std::endl;
    std::cout << "##-##-## LastName (# is a digit)" << std::endl;
    std::cout << "To search, simply enter the number or last name" << std::endl;

    // объявляем словари
    std::map<std::string, std::string> phoneDict;
    // multimap для словаря с ключом по фамилиям
    std::multimap<std::string, std::string> phoneDictMult;

    std::string str;


    // бесконечный цикл ввода запроса
    while (true) {
        std::cout << "Input your query -> ";
        std::getline(std::cin, str);
        // условие выхода
        if (str == "-1") {
            break;
        }

        std::pair<std::string, std::string> p;
        if (parsingStr(str, p)) {
            if (p.first == "") {
                // поиск по фамилии
                if (phoneDictMult.contains(p.second)) {
                    // находим диапазон итераторов по данным ключа
                    auto range = phoneDictMult.equal_range(p.second);
                    // выводим все значения по диапазону итераторов
                    for (auto it = range.first; it != range.second; ++it) {
                        std::cout << it->second << " ";
                    }
                    std::cout << std::endl;
                } else {
                    // если нет совпадений
                    std::cout << "No match found" << std::endl;
                }
            } else if (p.second == "") {
                // поиск по номеру
                if (phoneDict.count(p.first) > 0) {
                    std::cout << phoneDict.at(p.first) << std::endl;
                } else {
                    std::cout << "No match found" << std::endl;
                }
            } else {
                //добавление в справочник записи
                findInsert(phoneDict, phoneDictMult, p);
            }
        } else {
            std::cout << "Incorrect command" << std::endl;
        }
    }
    return 0;
}
