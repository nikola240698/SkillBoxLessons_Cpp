#include <iostream>

int main() {
    
    int yearCheck;

    std::cout << "Программа для определения високосного года" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите проверяемый год";
    std:: cin >> yearCheck;

    if (yearCheck < 0) std::cout << "Введите год н.э." << std::endl;
    else {
        if (yearCheck % 4 == 0) {
            if (yearCheck % 100 == 0 && yearCheck % 400 != 0)
                std::cout << "Год не високосный" << std::endl;
            else std::cout << "Год високосный" << std::endl;
        } else std::cout << "Год не високосный" << std::endl;
    }
}
