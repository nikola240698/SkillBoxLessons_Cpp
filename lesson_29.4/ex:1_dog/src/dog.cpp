#include "dog.h"

// описание конструктоора класса
Dog::Dog(const std::string &inName) : name(inName) {}
// описание методов класса
// метод добавления таланта к объекту
void Dog::addTalent(Talent* talent) {
    talents.push_back(talent);
}

// метод вывода списка талантов
void Dog::show_talents() const {
    std::cout << "This is " << name << " and ";
    // проверяем, что таланты есть
    if (talents.empty()) {
        std::cout << "it has no talents" << std::endl;
        return;
    }
    // если есть, то выводим их все
    std::cout << "it has some talents:" << std::endl;
    for (int i = 0; i < talents.size(); ++i) {
        talents[i]->show_talents();
    }
}

