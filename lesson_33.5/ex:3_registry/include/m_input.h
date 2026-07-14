#pragma once

#include <iostream>
#include <limits>

// шаблон функции ввода произвольных переменных с проверкой на ошибки
template<typename T>
T inputValue()
{
    T value;
    while (true)
    {
        if (std::cin >> value)
        {
            return value;
        }
        std::cerr << "Incorrect input. Try again.\n";
        // Сбрасываем состояние ошибки потока
        std::cin.clear();
        // Удаляем неправильные данные из буфера
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
