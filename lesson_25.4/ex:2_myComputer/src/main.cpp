#include "gpu.h"
#include "kbd.h"
#include "cpu.h"
#include "disk.h"
#include <string>
#include <iostream>

enum Command {
    SUM = 1,
    SAVE,
    LOAD,
    INPUT,
    DISPLAY,
    EXIT
};

void commandList() {
    std::cout << "Select one of the next command:" << std::endl;
    std::cout << "1 - sum\t\t (of all number in the RAM)" << std::endl;
    std::cout << "2 - save\t (data to the file)" << std::endl;
    std::cout << "3 - load\t (data from file)" << std::endl;
    std::cout << "4 - input\t (numbers in RAM)" << std::endl;
    std::cout << "5 - display\t (show numbers int the RAM)" << std::endl;
    std::cout << "6 - exit\t (exit the program)" << std::endl;
}

int main() {

    while (true) {
        commandList();
        int choice = inputInt();

        switch (choice) {
            case SUM: compute();
                break;
            case SAVE: save();
                break;
            case LOAD: load();
                break;
            case INPUT: inputBuffer();
                break;
            case DISPLAY: showBuffer();
                break;
            case EXIT: return 0;
                break;
            default: std::cout << "Incorrect command!" << std::endl;
                break;
        }
    }
}