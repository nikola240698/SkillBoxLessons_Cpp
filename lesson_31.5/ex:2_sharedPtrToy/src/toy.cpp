#include "toy.h"

Toy::Toy(const std::string inName) : name(inName) {}
Toy::Toy() : Toy("SomeToy") {}

std::string Toy::getName()
{
    return name;
}

Toy::~Toy()
{
    std::cout << "Toy " << name << " was dropped" << std::endl;
}