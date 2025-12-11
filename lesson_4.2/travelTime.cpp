#include <iostream>

int main() {
    
    int distanceMosRyaz = 200;
    int carSpeed;
    int travelTime;

    std::cout << "-----Сегодня путешествуем по России!-----" << std::endl;
    std::cout << std::endl;
    std::cout << "Прокатимся до Рязани из Москвы" << std::endl;
    std::cout << "Расстояние между городами " << distanceMosRyaz << " км" << std::endl;;
    std::cout << "Укажите, с какой скоростью будем двигаться? (км/ч)";
    std::cin >> carSpeed;

    travelTime = distanceMosRyaz / carSpeed;

    std::cout << std::endl;
    std::cout << "---------------- Считаем ----------------" << std::endl;
    std::cout << std::endl;

    if (travelTime > 2) {
        std::cout << "Нуу, так не пойдет совсем..." << std::endl;
        std::cout << "С нашей черепашьей скоростью в " << carSpeed << "км/ч" <<std::endl;
        std::cout << "За " << travelTime << "ч мы не доберемся до Рязани" << std::endl;
        std::cout << "Надо уложиться в 2ч" << std::endl;
    }

    if (travelTime <= 2) {
        std::cout << "Замечательно, отличная скорость!" << std::endl;
        std::cout << "-------- Спустя " << travelTime << "ч.  --------" << std::endl;
        std::cout << "Вы приехали!" << std::endl;
    }

}
