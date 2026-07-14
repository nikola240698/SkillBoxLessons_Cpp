
#include "field.h"


Field::Field()
{
    // определяем рандомный сектор для рыбы
    const int fishSector = std::rand() % SECTOR_COUNT;
    // добавляем в этот сектор рыбу
    field[fishSector].addFish();
    // добавляем ботинки
    for (int i = 0; i < BOOT_COUNT; ++i)
    {
        int bootSector;
        // выбираем рандомный сектор с проверкой на пустоту
        do
        {
            bootSector = std::rand() % SECTOR_COUNT;
        } while (!field[bootSector].isEmptySector());
        // бросаем ботинок в воду
        field[bootSector].addBoot();
    }
}


// метод вылова рыбы
void Field::castFishingRod(const int sectorNumber)
{
    // проверяем что верно ввели номер сектора
    if (sectorNumber < 1 || sectorNumber > SECTOR_COUNT)
    {
        throw std::invalid_argument("The sector number must be in the range from 1 to 9");
    }
    // определяем индекс сектора
    int indexNumber = sectorNumber - 1;
    // смотрим что в секторе лежит
    // либо рыба
    if (field[indexNumber].getFish() != nullptr)
    {
        throw Fish();
    }
    // либо ботинок
    if (field[indexNumber].getBoot() != nullptr)
    {
        throw Boot();
    }
    // либо ничего
    std::cout << "Sector is empty. Try gain" << std::endl;

}