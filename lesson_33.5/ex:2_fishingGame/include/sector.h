#pragma once

#include "fish.h"
#include "boot.h"


// класс сектора
class Sector
{
    // поля сектора
    Fish* fish;
    Boot* boot;

public:

    // конструктор класса
    Sector() : fish(nullptr), boot(nullptr) {}
    // деструктор класса
    ~Sector();
    // метод проверки сектора на пустоту
    bool isEmptySector() const;
    // метод добавления рыбы в сектор
    void addFish();
    // метод добавления ботинка в сектор
    void addBoot();
    // геттер указателя на рыбу
    Fish* getFish();
    // геттер указателя на ботинок
    Boot* getBoot();
};