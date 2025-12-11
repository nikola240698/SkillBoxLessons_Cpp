#include <iostream>

int main() {
    
    int number;

    std::cout << "Программа вычисляет модуль от введенного числа" << std::endl;
    std::cout << std::endl;
    std::cout << "Введите число: ";
    std::cin >> number;

    std::cout << "Получаем ответ |" << number;

    if (number < 0) {
        number = -number;
    }

    std::cout << "| = " << number << std::endl;

}
