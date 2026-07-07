#include <iostream>
#include <memory>
#include <string>

// класс игрушки
class Toy
{
    // поле класса
    std::string name;

public:
    // конструкторы класса
    Toy(const std::string inName) : name(inName) {}
    Toy() : Toy("SomeToy") {}
    // метод получения имени
    std::string getName()
    {
        return name;
    }
    // деструктор класса
    ~Toy()
    {
        std::cout << "The Toy " << name << " was dropped" << std::endl;
    }
};

// класс собаки
class Dog
{
    // поля класса
    std::string name;
    std::shared_ptr<Toy> toy;
public:
    // констркутор класса
    Dog(const std::string inName) : name(inName) {}
    Dog() : Dog("Druzhok") {}
    // метод броска игрушки
    void dropToy()
    {
        std::cout << name << ": ";
        // если игрушки нет
        if (toy == nullptr)
        {
            std::cout << "Nothing to drop" << std::endl;
        } else
        // если игрушка есть в руках 
        {
            std::cout << "I drop the toy: " << toy->getName() << std::endl;
            toy.reset();
        }
    }
    // метод получения игрушки
    void getToy(std::shared_ptr<Toy> inToy)
    {
        std::cout << name << ": ";
        // проверяем что ссылок на игрушки более двух (значит кто-то ей владеет)
        if (inToy.use_count() > 2)
        {
            std::cout << "Another dog is playing with this toy: " << inToy->getName() << std::endl;
        // если передали ту же самую игрушку
        } else if (toy == inToy)
        {
            std::cout << "I already have this toy: " << inToy->getName() << std::endl;
        // если игрушка новая
        } else
        {
            std::cout << "I take this toy: " << inToy->getName() << std::endl;
            toy = inToy;
        }
    }
};

int main()
{
    // создаем указатели на игрушки
    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");
    std::shared_ptr<Toy> stick = std::make_shared<Toy>("Stick");
    // создаем собак
    Dog a = Dog("Snow");
    Dog b = Dog("Druzhok");
    Dog c = Dog("Laika");

    // раздаем и забираем игрушки
    a.getToy(ball);
    b.getToy(bone);
    c.getToy(bone);
    c.getToy(stick);
    a.dropToy();
    a.dropToy();
    // сбрасываем указатели на игрушки
    ball.reset();
    bone.reset();
    stick.reset();

    return 0;
}
