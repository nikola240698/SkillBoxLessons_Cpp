#include <iostream>

int main() {
   
    int beginHight  = 0;
    int dailyGrowth = 0;
    int nightFade   = 0;
    int dayX        = 0;
    int totalHight  = 0;

    std::cout << "Программа для вычисления длины бамбука, в связи с нашествием гусениц." << std::endl;
    std::cout << "Сейчас узнаем, какой же будет его рост к середине выбранного дня." << std::endl;
    std::cout << std::endl;
    std::cout << "Укажите начальную высоту саженцев бамбука (см): ";
    std::cin >> beginHight;
    std::cout << "Укажите величину ежедневного роста бамбука (см): ";
    std::cin >> dailyGrowth;
    std::cout << "Укажите аппетит гусениц (сколько съедают бамбука за ночь (см)): ";
    std::cin >> nightFade;
    std::cout << "Укажите, на какой день будем прогнозировать его высоту: ";
    std::cin >> dayX;
    std::cout << std::endl;
    std::cout << "----------- Вычисляем -----------" << std::endl;

    totalHight = beginHight + (dailyGrowth - nightFade) * dayX + dailyGrowth/2;

    std::cout << std::endl;
    std::cout << "При начальном росте бамбука " << beginHight << " см ";
    std::cout << "и ежедневном росте в " << dailyGrowth << " см, " << std::endl;
    std::cout << "с учетом ночного поедания гусениц в " << nightFade << " см, получаем, " << std::endl;
    std::cout << "что на середиину " << dayX << " дня высота бамбука будет равна ";
    std::cout << totalHight << " см." << std::endl;
    std::cout << "Отличный результат!";

}
