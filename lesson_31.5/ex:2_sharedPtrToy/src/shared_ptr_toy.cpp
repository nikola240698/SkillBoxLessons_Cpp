#include "shared_ptr_toy.h"





// метод уменьшения счетчика с проверкой
void shared_ptr_toy::increase()
{
    // проверяем, что есть вообще счетчик
    if (count == nullptr)
    {
        return;
    }
    // уменьшаем счетчик
    --(*count);
    // проверяем, если больше нет копий
    if (*count == 0)
    {
        // удаляем объекты
        delete toy;
        delete count;
    }
    // зануляем указатель в этом объекте
    toy = nullptr;
    count = nullptr;
}


// конструкторы класса
shared_ptr_toy::shared_ptr_toy(const std::string inName)
{
    toy = new Toy(inName);
    count = new int(1);
}
shared_ptr_toy::shared_ptr_toy() : toy(nullptr), count(nullptr) {}
// деструктор класса
shared_ptr_toy::~shared_ptr_toy()
{
    increase();
}

// метод копирования
shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& other)
{
    // присваиваем поля
    toy= other.toy;
    count = other.count;
    // проверяем счетчик на нулевой указатель
    if (count != nullptr)
    {
        ++(*count);
    }
}

// метод присваивания
shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& other)
{
    // проверяем что присвоили самого себе
    if (this == &other)
        return *this;
    // проверяем, что игрушка та же самая
    if (toy == other.toy)
        return *this;
    // уменьшаем счетчик с проверкой
    increase();
    // присваиваем поля класса
    toy = other.toy;
    count = other.count;
    // проверяем, что счетчик был создан
    if (count != nullptr)
    {
        // увеличиваем его на единицу
        ++(*count);
    }
    // возвращаем новый объект
    return *this;
}

void shared_ptr_toy::reset()
{
    increase();
}

Toy* shared_ptr_toy::get() const
{
    return toy;
}

int shared_ptr_toy::use_count() const
{
    if (count == nullptr)
        return 0;
    return *count;
}

std::string shared_ptr_toy::getToyName() const
{
    if (toy == nullptr)
        return "Nothing";
    return toy->getName();
}

shared_ptr_toy make_shared_toy(const std::string name)
{
    return shared_ptr_toy(name);
}