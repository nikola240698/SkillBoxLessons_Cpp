#include <iostream>

void showArray(const auto arr[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {

    int number = 0;
    int multiply = 1;
    int snake[5][5];

    std::cout << "The program displays an array filled with a snake" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            snake[i][2 - (2 * multiply) + (multiply * j)] = number;
            number++;
        }
        multiply *= -1;
    }

    showArray(snake);

    return 0;
}
