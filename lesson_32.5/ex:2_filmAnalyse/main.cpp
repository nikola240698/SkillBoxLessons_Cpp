#include <iostream>
#include <fstream>
#include <string>

#include "nlohmann/json.hpp"

int main() {
    // создаем поток
    std::ifstream file("films.json");
    // проверяем, что файл есть
    if (!file.is_open()) {
        std::cout << "Don't find \"films.json\"" << std::endl;;
        return 1;
    }
    // создаем переменную и читаем файл
    nlohmann::json films;
    file >> films;
    // строка для поиска
    std::string searchName;
    // вводим искомые данные
    std::cout << "Input name or family of the actor: ";
    std::getline(std::cin, searchName);
    // флаг найденного значения
    bool found = false;
    // читаем файл от начала до конца
    for (nlohmann::json::iterator it = films.begin(); it != films.end(); ++it)
    {
        // получаем значения каждого ключа
        std::string filmTitle = it.key();
        nlohmann::json filmInfo = it.value();
        // пробегаемся по данным ключа
        for (size_t i = 0; i < filmInfo["main_characters"].size(); ++i)
        {
            // ищем нужные нам значения
            std::string actor = filmInfo["main_characters"][i]["actor"];
            std::string character = filmInfo["main_characters"][i]["character"];
            // в случае успеха поиска
            if (actor.find(searchName) != std::string::npos)
            {
                std::cout << "Film: " << filmTitle << std::endl;
                std::cout << "Actor: " << actor << std::endl;
                std::cout << "Role: " << character << std::endl;
                std::cout << std::endl;

                found = true;
            }
        }
    }
    // в сулчае провала поиска
    if (!found) {
        std::cout << "The actor doesn't find.\n";
    }
    return 0;
}
