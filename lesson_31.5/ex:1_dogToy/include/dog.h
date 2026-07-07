#pragma once

#include <memory>

#include "toy.h"

// класс собаки
class Dog
{
    // поля класса
    std::string name;
    std::shared_ptr<Toy> toy;
public:
    // констркутор класса
    Dog(const std::string inName);
    Dog();
    // метод броска игрушки
    void dropToy();
    // метод получения игрушки
    void getToy(std::shared_ptr<Toy> inToy);
};