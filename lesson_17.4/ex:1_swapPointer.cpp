#include <iostream>
#include <limits> // для контроля верного ввода параметров по Вашему шаблону

bool inputNum(int* a, int* b) {
    int var1, var2;
    std::cin >> var1 >> var2;
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cerr << "Incorrect data" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    *a = var1;
    *b = var2;
    return true;
}

void swapPointer(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}


int main() {

    int a, b;
    int* pa = &a;
    int* pb = &b;

    std::cout << "Program for swapping variables" << std::endl;
    std::cout << "using their pointers" << std::endl;
    std::cout << std::endl;

    do  {
        std::cout << "Input two numbers separated by a space:";
    } while (!inputNum(pa, pb));

    std::cout << "Inputted numbers:\ta - " << a << "\tb - " << b << std::endl;
    swapPointer(pa, pb);
    std::cout << "Swapped numbers:\ta - " << a << "\tb - " << b << std::endl;

    return 0;
}
