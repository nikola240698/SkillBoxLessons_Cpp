#pragma once

#include <iostream>
#include <string>

// заголовочный файл класса
class Toy
{
    // поля класса
    std::string name;

public:
    // конструкторы класса
    Toy(const std::string inName);
    Toy();
    // деструктор класса
    ~Toy();
    // метод получения имени игрушки
    std::string getName();
};
