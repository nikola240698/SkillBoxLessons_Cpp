#include <iostream>

int main() {
    
    int x, y;

    std::cout << "Программа для определение местоположения точки координат" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите координаты Х и У";
    std:: cin >> x >> y;

    if (x == 0 || y == 0) std::cout << "Точка лежит на границе четвертей" << std::endl;
    else {

        if (x > 0) {
            if (y > 0) std::cout << "Точка находится в I четверти" << std::endl;
            else std::cout << "Точка находится в IV четверти" << std::endl;
        }
        if (x < 0) {
            if (y > 0) std::cout << "Точка находится во II четверти" << std::endl;
            else std::cout << "Точка находится в III четверти" << std::endl;
        }
    }
}
