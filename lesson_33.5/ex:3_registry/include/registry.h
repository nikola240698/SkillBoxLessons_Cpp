#pragma once

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

// шаблон класса реестра
template<typename Key, typename Value>
class Registry
{
    // поле класса
    std::multimap<Key, Value> registry;

public:
    // метод добавления записи в реестр
    void addRecord(const Key& inKey, const Value& inValue)
    {
        registry.insert(std::make_pair(inKey, inValue));
    }

    // метод вывода содержимого реестра
    void printRegistry() const
    {
        // проверка реестра на пустоту
        if (registry.empty())
        {
            throw std::invalid_argument("The registry is empty");
        }
        // цикл прохода по всему реестру
        for (auto it = registry.begin(); it != registry.end(); ++it)
        {
            // выводим значения в консоль
            std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        }
    }

    // метод поиска значения по ключу
    void findRecord(const Key& key) const
    {
        // проверка на заполненность реестра
        if (registry.empty())
        {
            throw std::invalid_argument("The registry is empty");
        }
        // указатель на диапазон искомых значений
        auto range = registry.equal_range(key);
        // если диапазон пуст, то ничего не нашли
        // точнее, если указатель начала диапазона и конца совпадают
        if (range.first == range.second)
        {
            throw std::invalid_argument("There is no record with key");
        }
        // выводим все значения по диапазону итераторов
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
        }
    }

    // метод удаления всех записей по ключу в реестре
    void removeRecord(const Key& key)
    {
        // проверяем реестр на заполненность
        if (registry.empty())
        {
            throw std::invalid_argument("The registry is empty");
        }
        // создаем счетчик удаленных элементов
        int removeCount = registry.erase(key);
        // если счетчик равен нулю
        if (removeCount == 0)
        {
            throw std::invalid_argument("There is no record with this key");
        }
        // иначе выводим сообщение о количестве удаленных записей
        std::cout << "Removed records: " << removeCount << std::endl;
    }
};