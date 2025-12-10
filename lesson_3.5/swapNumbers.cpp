#include <iostream>

int main() {
    
    int a, b;

    std::cout << "Программа для замены местами двух переменных!" << std::endl;
    std::cout << "Введите первую переменную: ";
    std::cin >> a;
    std::cout << "Введите вторую переменную: ";
    std::cin >> b;

    std::cout << "Вы ввели а=" << a << " и b=" << b << std::endl;

    a += b;
    b = a-b;
    a -= b;

    std::cout << "Получаем a=" << a << " и b=" << b << std::endl;

}
