#include "toy.h"

// конструкторы класса
Toy::Toy(const std::string inName) : name(inName) {}
Toy::Toy() : Toy("SomeToy") {}
// метод получения имени
std::string Toy::getName()
    {
        return name;
    }
// деструктор класса
Toy::~Toy()
    {
        std::cout << "The Toy " << name << " was dropped" << std::endl;
    }