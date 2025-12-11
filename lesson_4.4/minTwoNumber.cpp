#include <iostream>

int main() {
    
    int a = 0;
    int b = 0;

    std::cout << "Программа для нахождения минимального числа из введенных" << std::endl;
    std::cout << std::endl;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;

    if (a < b) {
        std::cout << "Нименьшее число: " << a << std::endl;
    } else if (b < a) {
        std::cout << "Нименьшее число: " << b << std::endl;
    } else {
        std::cout << "Числа равны!" << std::endl;
    }

}
