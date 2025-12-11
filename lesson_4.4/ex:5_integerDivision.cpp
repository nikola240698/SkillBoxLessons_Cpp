#include <iostream>

int main() {
    
    int a = 0;
    int b = 0;

    std::cout << "Программа для определения целочисленного деления" << std::endl;
    std::cout << std::endl;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    std::cout << "----- Проверяем -----" << std::endl;

    if (b == 0) {
        std::cout << "Ошибка! На 0 делить нельзя!" << std::endl;
    } else if (a % b == 0) {
        std::cout << "Да, число " << a << " делится на число " << b << " без остатка" << std::endl;
    } else {
        std::cout << "Нет, число " << a << " не делится на число " << b << " без остатка" << std::endl;
    }

}
