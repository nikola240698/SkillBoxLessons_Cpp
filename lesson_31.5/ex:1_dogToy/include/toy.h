#pragma once

#include <iostream>
#include <string>

// заголовочный файл класса
class Toy
{
    // поле класса
    std::string name;

public:
    // конструкторы класса
    Toy(const std::string inName);
    Toy();
    // метод получения имени
    std::string getName();
    // деструктор класса
    ~Toy();
};