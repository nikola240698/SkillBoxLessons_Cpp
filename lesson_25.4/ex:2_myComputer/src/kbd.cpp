#include "kbd.h"
#include <ram.h>
#include <limits>

int inputInt() {
    int val;
    while (true) {
        std::cout << "-> ";
        std::cin >> val;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Incorrect data. Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    return val;
}

void inputBuffer() {
    int data[8];
    for (int i = 0; i < 8; ++i) {
        std::cout << "Input the " << i << " number" << std::endl;
        data[i] = inputInt();
    }
    // записываем в ram-память
    write(data);
}

