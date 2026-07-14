#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#include "sector.h"

#define SECTOR_COUNT 9
#define BOOT_COUNT 3



class Field
{
    Sector field[SECTOR_COUNT];

public:

    // конструктор класса
    Field();


    // метод вылова рыбы
    void castFishingRod(const int sectorNumber);
};
