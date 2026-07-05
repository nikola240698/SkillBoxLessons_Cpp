#pragma once
#include "talent.h"

// объявление класса с наследованием
class Swimming : public Talent {

public:
    // определение метода класса
    void show_talents() override;
};