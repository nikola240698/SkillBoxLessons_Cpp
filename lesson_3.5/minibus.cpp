#include <iostream>

int main() {
 
    int ticketPrice = 20;
    int passengersNumer = 0;
    int passengersComeIn = 0;
    int passengersGoOut = 0;
    int income = 0;

    std:: string firstStop = "'Улица программистов'";
    std:: string secondStop = "'Проспект алгоритмов'";
    std:: string thirdStop = "'Аллея переменных'";
    std:: string fourthStop = "'Массивы строк'";

    std::cout << "======================================" << std::endl;
    std::cout << "|                                    |" << std::endl;
    std::cout << "|   Программа-симулятор маршрутки!   |" << std::endl;
    std::cout << "|                                    |" << std::endl;
    std::cout << "======================================" << std::endl;

    // Первая остановка

    std::cout << "Прибываем на остановку" << firstStop << ". В салоне пассажиров: ";
    std::cout << passengersNumer << std::endl;
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> passengersGoOut;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> passengersComeIn;

    income += ticketPrice * passengersComeIn;
    passengersNumer += (passengersComeIn - passengersGoOut);

    std::cout << "Отправляемся с остановки " << firstStop << ". В салоне пассажиров: ";
    std::cout << passengersNumer << std::endl;
    std::cout << "---------Едем---------" << std::endl;

    //Вторая остановка

    std::cout << "Прибываем на остановку " << secondStop << ". В салоне пассажиров: ";
    std::cout << passengersNumer << std::endl;
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> passengersGoOut;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> passengersComeIn;

    income += ticketPrice * passengersComeIn;
    passengersNumer += (passengersComeIn - passengersGoOut);

    std::cout << "Отправляемся с остановки " << secondStop << ". В салоне пассажиров: ";
    std::cout << passengersNumer << std::endl;
    std::cout << "---------Едем---------" << std::endl;

    //Третья остановка

    std::cout << "Прибываем на остановку " << thirdStop << ". В салоне пассажиров: ";
    std::cout << passengersNumer << std::endl;
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> passengersGoOut;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> passengersComeIn;

    income += ticketPrice * passengersComeIn;
    passengersNumer += (passengersComeIn - passengersGoOut);

    std::cout << "Отправляемся с остановки " << thirdStop << ". В салоне пассажиров: ";
    std::cout << passengersNumer << std::endl;
    std::cout << "---------Едем---------" << std::endl;

    //Четвертая остановка

    std::cout << "Прибываем на остановку " << fourthStop << ". В салоне пассажиров: ";
    std::cout << passengersNumer << std::endl;
    std::cout << "Сколько пассажиров вышло на остановке? ";
    std::cin >> passengersGoOut;
    std::cout << "Сколько пассажиров зашло на остановке? ";
    std::cin >> passengersComeIn;

    income += ticketPrice * passengersComeIn;
    passengersNumer += (passengersComeIn - passengersGoOut);

    std::cout << "Отправляемся с остановки " << fourthStop << ". В салоне пассажиров: ";
    std::cout << passengersNumer << std::endl;
    std::cout << "---------Едем на конечную---------" << std::endl;
    std::cout << std::endl;

    int driverIncome = income/4;
    int fuelCost = income/5;
    int taxes = income/5;
    int careRepairCost = income/5;
    int dailyIncome = income - (driverIncome + fuelCost + taxes + careRepairCost);

    std::cout << "--------Итоги рабочего дня--------" << std::endl;
    std::cout << "Всего заработано: " << income << " руб." << std::endl;
    std::cout << "Зарплата водителя: " << driverIncome << " руб." << std::endl;
    std::cout << "Расходы на топливо: " << fuelCost << " руб." << std::endl;
    std::cout << "налоги: " << taxes << " руб." << std::endl;
    std::cout << "Расходы на ремонт машины: " << careRepairCost << " руб." << std::endl;
    std::cout << "Итого доход: " << dailyIncome << " руб." << std::endl;

}
