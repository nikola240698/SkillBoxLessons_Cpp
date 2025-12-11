#include <iostream>

int main() {
    
    int a   = 0;
    int b   = 0;
    int sum = 0;

    std::cout << "Программа проверяет Вас на правильность сложения чисел в уме" << std::endl;
    std::cout << std::endl;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    std::cout << "Введите их сумму: ";
    std::cin >> sum;

    if (a + b == sum) {
        std::cout << "Верно!" << std::endl;
    } else {
        std::cout << "Ошибка! Верный результат: " << a + b << std::endl;
    }

}
