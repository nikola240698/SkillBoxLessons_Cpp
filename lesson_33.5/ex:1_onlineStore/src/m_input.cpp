#include "m_input.h"

int inputInt()
{
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Incorrect data. Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}

double inputDouble()
{
    double value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Incorrect data. Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}

