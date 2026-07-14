
#include "sector.h"

// деструктор класса
Sector::~Sector()
{
    delete fish;
    delete boot;

    fish = nullptr;
    boot = nullptr;
}
// метод проверки сектора на пустоту
bool Sector::isEmptySector() const
{
    return fish == nullptr && boot == nullptr;
}
// метод добавления рыбы в сектор
void Sector::addFish()
{
    fish = new Fish();
}
// метод добавления ботинка в сектор
void Sector::addBoot()
{
    boot = new Boot();
}
// геттер указателя на рыбу
Fish* Sector::getFish()
{
    return fish;
}
// геттер указателя на ботинок
Boot* Sector::getBoot()
{
    return boot;
}

