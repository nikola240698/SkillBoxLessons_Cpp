#include <iostream>
// подключаем заголовочный файл базового класса
#include "talent.h"


int main() {
    // создаем первую собаку
    Dog dog1("Boss");
    // добавляем ей таланты
    dog1.addTalent(new Dancing());
    dog1.addTalent(new Counting());
    // создаем вторую собаку
    Dog dog2("Hugo");
    // добавляем ей таланты
    dog2.addTalent(new Swimming());
    dog2.addTalent(new Counting());
    // создаем третью собаку без талантов
    Dog dog3("Mailo");
    // выводим информацию о собаках
    dog1.show_talents();
    dog2.show_talents();
    dog3.show_talents();

  return 0;
}
