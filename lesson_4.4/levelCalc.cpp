#include <iostream>

int main() {
    
    int experience = 0;

    std::cout << "Программа для определения вашего уровня" << std::endl;
    std::cout << std::endl;
    std::cout << "Введите Ваше число очков опыта: ";
    std::cin >> experience;
    std::cout << "----- Считаем -----" << std::endl;

    if (experience < 0) {
        std::cout << "Ошибка! отрицательное значение!" << std::endl;
    } else if (experience >= 5000) {
        std::cout << "Ваш уровень: 4" << std::endl;
    } else if (experience >= 2500) {
        std::cout << "Ваш уровень: 3" << std::endl;
    } else if (experience >= 1000) {
        std::cout << "Ваш уровень: 2" << std::endl;
    } else {
        std::cout << "Ваш уровень: 1" << std::endl;
    }

}
