#include <iostream>
#include <ctime>
#include <iomanip>

#define HEADER(text)                                                    \
    std::cout << std::endl;                                             \
    std::cout << "========== " << text << " ==========" << std::endl    \

int main() {
    // заголовок
    HEADER("A program - timer!");
    std::cout << std::endl;
    // вводим требуемое время
    std::tm inpTime{};
    std::cout << "Input the time (MM:SS) -> ";
    std::cin >> std::get_time(&inpTime, "%M:%S");
    // условие неверного ввода поля
    if (std::cin.fail()) {
        std::cout << "Invalid input format!\n";
        return 1;
    }
    // переменные расчета времени
    int timerSec = inpTime.tm_sec;
    int timerMin = inpTime.tm_min;
    // считаем время таймер
    int timerTime = timerMin * 60 + timerSec;
    // определяем начальное и конечное время
    std::time_t startTime = std::time(nullptr);
    std::time_t endTime = startTime + timerTime;
    // заводим переменную для вывода в консоль при истечении одной секунды
    int diffTime = static_cast<int>(startTime);
    // бесконечный цикл
    while (true) {
        // определяем текущее время
        std::time_t currTime = std::time(nullptr);
        // высчитываем оставшееся время
        int remainTime = static_cast<int>(endTime - currTime);
        // условие пропуска вывода в консоль, если не прошла секунда
        if (diffTime - remainTime < 1) {
            continue;
        }
        // условие выхода
        if (remainTime <= 0) {
            std::cout << "DING! DING! DING!" << std::endl;
            break;
        }
        // определяем сколько минут и секунд осталось
        int remainMin = remainTime / 60;
        int remainSec = remainTime % 60;
        // выводим в консоль с красивым оформлением
        std::cout << std::setfill('0') << std::setw(2) << remainMin << ":";
        std::cout << std::setw(2) << remainSec << std::endl;
        // переписываем переменную сдвига времени
        diffTime = remainTime;
    }

    return 0;
}
