#pragma once
#include "talent.h"
#include <vector>

// объявление класса
class Dog {
    // переменные класса
    std::string name = "Unknown";
    std::vector<Talent*> talents;

public:
    // определение конструктора класса
    Dog(const std::string &inName);
    // определение методов класса
    void addTalent(Talent* talent);
    void show_talents() const;
};