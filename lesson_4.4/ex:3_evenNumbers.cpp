#include <iostream>

int main() {
    
    int a = 0;

    std::cout << "Программа проверяет на четность введенное число" << std::endl;
    std::cout << std::endl;
    std::cout << "Введите число: ";
    std::cin >> a;
    std::cout << "----- Проверяем -----" << std::endl;
    if (a % 2 == 0) {
        std::cout << "Число " << a << " чётное" << std::endl;
    } else {
        std::cout << "Число " << a << " не чётное" << std::endl;
    }

}
