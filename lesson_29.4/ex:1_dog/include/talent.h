#pragma once
#include <iostream>
// подключаем заголовочные файлы наследованных классов
#include "dancing.h"
#include "counting.h"
#include "dog.h"
#include "swimming.h"

// определение абстарктного класса
class Talent {
public:
    virtual void show_talents() = 0;
};