#include <dog.h>

// констркутор класса
Dog::Dog(const std::string inName) : name(inName) {}
Dog::Dog() : Dog("Druzhok") {}
// метод броска игрушки
void Dog::dropToy()
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
void Dog::getToy(std::shared_ptr<Toy> inToy)
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