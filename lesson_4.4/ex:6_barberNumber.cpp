#include <iostream>

int main() {
    
    int dayInMonth      = 30;       //кол-во дней в месяце
    int barberShift     = 8;        //часов в смене барбера
    int barberSpeed     = 1;        //количество мужчин за 1 час работы барбера

    int manNumber, barberNumberInStock;
    int barberPowerMonth;
    int totalMonthNumber;

    std::cout << "Пограмма для вычисления необходимого количества барберов" << std::endl;
    std::cout << std::endl;
    std::cout << "Укажите, сколько мужчин проживает в городе? ";
    std::cin >> manNumber;
    std::cout << "Укажите, сколько барберов уже работают в городе? ";
    std::cin >> barberNumberInStock;
    std::cout << std::endl;

    if (manNumber <= 0) {
        std::cout << "Ошибка! Не верно введены данные" << std::endl;
    } else if (barberNumberInStock <= 0) {
        std::cout << "Ошибка! Не верно введены данные" << std::endl;
    } else {
        std::cout << "----------- Производим расчеты -----------" << std::endl;
        std::cout << std::endl;

        barberPowerMonth = barberSpeed * barberShift * dayInMonth;

        std::cout << "При скорости работы барбера в " << barberSpeed << " муж/ч" << std::endl;
        std::cout << "И смене в " << barberShift << " ч, его производительность ";
        std::cout << barberSpeed * barberShift << " муж/смен" << std::endl;
        std::cout << "За месяц длиной в " << dayInMonth << " дней его производительность ";
        std::cout << barberPowerMonth << " муж/мес" << std::endl;

        totalMonthNumber = manNumber / barberPowerMonth;

        if (manNumber % barberPowerMonth > 0) {
            totalMonthNumber += 1;
        }

        std::cout << "Для успешной компании требуется " << totalMonthNumber
                  << " барберов" << std::endl;
        std::cout << "Способных обслужить " << totalMonthNumber * barberPowerMonth
                  << " человек" << std::endl;
        std::cout << "------------------ Получаем итог ------------------" << std::endl;

        if (totalMonthNumber > barberNumberInStock) {
            std::cout << "Для успешной работы нам необходимо еще ";
            std::cout << totalMonthNumber - barberNumberInStock << " барберов" << std::endl;
        } else if (totalMonthNumber == barberNumberInStock) {
            std::cout << "Наши барберы справляются успешно!" << std::endl;
        } else {
            std::cout << "Наши барберы работают не всю смену" << std::endl;
            std::cout << "Предлагаем сократить " << barberNumberInStock - totalMonthNumber
                      << " барберов" << std::endl;
        }
    }
}
