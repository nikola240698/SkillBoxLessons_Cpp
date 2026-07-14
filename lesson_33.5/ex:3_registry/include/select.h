#pragma once

#include "registry.h"
#include "m_input.h"

// перечисления для битовых масок выбора типа переменных регистра
enum
{
    HasIntKey = 1,
    HasDoubleKey = 2,
    HasStringKey = 4,
    HasIntValue = 8,
    HasDoubleValue = 16,
    HasStringValue = 32
};

// шаблон работы реестра произвольного типа по командам
template<typename Key, typename Value>
void registryWork()
{
    // создаем новый регистр
    auto* registry = new Registry<Key, Value>();
    // строка для ввода команд
    std::string command;
    // цикл работы
    while (true)
    {
        // список команд
        std::cout << std::endl;
        std::cout << "Commands:" << std::endl;
        std::cout << "add" << std::endl;
        std::cout << "remove" << std::endl;
        std::cout << "find" << std::endl;
        std::cout << "print" << std::endl;
        std::cout << "exit" << std::endl;
        std::cout << "Input the command ->";
        std::cin >> command;
        // условие выхода из программы
        if (command == "exit")
        {
            break;
        }
        // условие добавления новой записи в реестр
        if (command == "add")
        {
            try
            {
                // вводим ключ и значение с проверкой ввода данных
                std::cout << "Key ->";
                Key key = inputValue<Key>();
                std::cout << "Value ->";
                Value value = inputValue<Value>();
                // добавляем записьв рееестр
                registry->addRecord(key, value);
            }
            // ловим оишибки
            catch (const std::invalid_argument& error)
            {
                std::cerr << "Error: " << error.what() << std::endl;
            }
        // условие удаления записи из реестра по ключу
        } else if (command == "remove")
        {
            try
            {
                // получаем необходимый ключ
                std::cout << "Key ->";
                Key key = inputValue<Key>();
                // удаляем значение
                registry->removeRecord(key);
            }
            // ловим ошибки
            catch (const std::invalid_argument& error)
            {
                std::cerr << "Error: " << error.what() << std::endl;
            }
        // условие поиска всех значений по ключу
        } else if (command == "find")
        {
            try
            {
                // получаем значение ключа
                std::cout << "Key ->";
                Key key = inputValue<Key>();
                // производим поиск
                registry->findRecord(key);
            }
            /// ловим ошибки
            catch (const std::invalid_argument& error)
            {
                std::cerr << "Error: " << error.what() << std::endl;
            }
        // условие вывода на экран всех значений реестра
        } else if (command == "print")
        {
            try
            {
                // выводим значения
                registry->printRegistry();
            }
            // ловим ошибки
            catch (const std::invalid_argument& error)
            {
                std::cout << "Error: " << error.what() << std::endl;
            }
        // если ввели не правильную команду
        } else
        {
            std::cout << "Incorrect command" << std::endl;
        }

    }
    // удаляем реестр из памяти
    delete registry;
}

// функция выбора типа переменной ключа/значения реестра
int selectType(const std::string& valueName);

// функция выбора типа переменных для словаря реестра
int selectTypename();

// функция запуска необходимого словаря по шаблону
void selectTemplate();
