#pragma once

#include "toy.h"


class shared_ptr_toy
{
    // поля класса
    Toy* toy;
    int* count;

    // метод уменьшения счетчика с проверкой
    void increase();


public:
    // конструкторы класса
    shared_ptr_toy(const std::string inName);
    shared_ptr_toy();
    // деструктор класса
    ~shared_ptr_toy();

    // метод копирования
    shared_ptr_toy(const shared_ptr_toy& other);

    // метод присваивания
    shared_ptr_toy& operator=(const shared_ptr_toy& other);

    void reset();

    Toy* get() const;

    int use_count() const;

    std::string getToyName() const;

};

shared_ptr_toy make_shared_toy(const std::string name);