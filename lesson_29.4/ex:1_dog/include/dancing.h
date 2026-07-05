#pragma once
#include "talent.h"

// объявление класса с наследованием
class Dancing : public Talent {

public:
    // определение метода класса
    void show_talents() override;
};