#include <iostream>

#include <dog.h>




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