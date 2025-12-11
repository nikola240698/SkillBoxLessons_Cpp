#include <iostream>

int main() {
    
    int firstProduct, secondProduct, thirdProduct, fourthProduct;
    int totalCost;
    int delivery = 0;

    std::cout << "Программа для вычисления стоимости товаров";
    std::cout << "и предоставления скидки, если это возможно" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите стоимость первого товара: ";
    std::cin >> firstProduct;

    std::cout << "Введите стоимость второго товара: ";
    std::cin >> secondProduct;

    std::cout << "Введите стоимость третьего товара: ";
    std::cin >> thirdProduct;

    std::cout << "Введите стоимость четвертого товара: ";
    std::cin >> fourthProduct;

    totalCost = firstProduct + secondProduct + thirdProduct + fourthProduct;

    std::cout << "Итоговая стоимость товаров: " << totalCost << " руб." << std::endl;
    if (totalCost > 10000) {
        delivery = 10;
        std::cout << "Так как сумма превыает порог в 10 000 руб.,";
        std::cout << "Вам назначена скидка в " << delivery << "%" << std::endl;
        std::cout << "С учетов скидки стоимость товара " << totalCost - (totalCost/delivery) << " руб.";
    }

}
