#include <iostream>

int main() {
    
    int firstSalary, secondSalary, thirdSalary;
    int maxSalary, minSalary;

    std::cout << "Введите зарплату первого сотрудника: ";
    std::cin >> firstSalary;
    std::cout << "Введите зарплату второго сотрудника: ";
    std::cin >> secondSalary;
    std::cout << "Введите зарплату третьего сотрудника: ";
    std::cin >> thirdSalary;
    std::cout << "----------------Считаем----------------";
    std::cout << std::endl;

    if (firstSalary > secondSalary) {
        maxSalary = firstSalary;
        minSalary = secondSalary;
    } else {
        maxSalary = secondSalary;
        minSalary = firstSalary;
    }

    if (maxSalary > thirdSalary) {
        if (thirdSalary < minSalary) {
            minSalary = thirdSalary;
        }
    } else {
        maxSalary = thirdSalary;
    }

    std::cout << "Самая высокая зарплата в отделе: " << maxSalary << " руб." << std::endl;
    std::cout << "Самая низкая зарплата в отделе: " << minSalary << " руб." << std::endl;
    std::cout << "Разнциа между самой высокой и самой низкой зарплатой в отделе: ";
    std::cout << maxSalary - minSalary << " рублей" << std::endl;
    std::cout << "Средняя зарплата в отделе: ";
    std::cout << (firstSalary + secondSalary + thirdSalary) / 3 << " рублей" << std::endl;

}
