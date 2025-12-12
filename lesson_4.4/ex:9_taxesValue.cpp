#include <iostream>

int main() {
   
    int earning = 0;
    int highTaxesValue      = 0;
    int mediumTaxesValue    = 0;
    int lowTaxesValue       = 0;

    std::cout << "Программа для вычисления Вашего налога от доходов" << std::endl;
    std::cout << "Пожалуйста, укажите Ваш доход: ";
    std::cin >> earning;

    if (earning <= 0 ) {
        std::cout << "Ошибка! Не вепно введены данные!" << std::endl;
    } else {
        std::cout << "------------- Вычисляем -------------" << std::endl;

        if (earning > 50000) {
            highTaxesValue      = (earning - 50000) * 30 / 100;
            mediumTaxesValue    = (50000 - 10000) * 20 / 100;
            lowTaxesValue       = 10000 * 13 /100;

            std::cout << "Получившийся налог с Вашего дохода в " << earning << " руб:" << std::endl;
            std::cout << "(" << earning << "-50000)*30%+(50000-10000)*20%+10000*13%=" << std::endl;
            std::cout << "=" << highTaxesValue << "+" << mediumTaxesValue << "+" << lowTaxesValue << "=";
            std::cout << highTaxesValue + mediumTaxesValue + lowTaxesValue << " руб" << std::endl;
        } else if (earning >10000) {
            mediumTaxesValue    = (earning - 10000) * 20 / 100;
            lowTaxesValue       = 10000 * 13 /100;

            std::cout << "Получившийся налог с Вашего дохода в " << earning << " руб:" << std::endl;
            std::cout << "(" << earning << "-10000)*20%+10000*13%=" << std::endl;
            std::cout << "=" << mediumTaxesValue << "+" << lowTaxesValue << "=";
            std::cout << mediumTaxesValue + lowTaxesValue << " руб" << std::endl;
        } else {
            lowTaxesValue       = earning * 13 /100;

            std::cout << "Получившийся налог с Вашего дохода в " << earning << " руб:" << std::endl;
            std::cout << earning << "*13%=" << lowTaxesValue << " руб" << std::endl;
        }
    }
}
