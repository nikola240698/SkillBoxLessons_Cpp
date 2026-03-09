#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <limits>

// проверка вводимых данных
void checkInput(int &value) {
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n' || value <= 0)
        {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Try again" << std::endl;
            continue;
        }
        break;
    }
}


int main() {

    std::string path;
    int width, height;
    std::ofstream file;

    std::srand(std::time(nullptr));

    // вводим путь к файлу
    while (true) {
        std::cout << "Input the path of the file: " << std::endl;
        std::cout << "-> ";
        std::cin >> path;
        file.open(path);
        if (file.is_open()) {
            break;
        }
        std::cout << "Incorrect path of the file" << std::endl;
    }

    // вводим размеры картины
    std::cout << "Input the width of the painting: ";
    checkInput(width);
    std::cout << "Enter the height of the painting: ";
    checkInput(height);

    // заполняем файл
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file << (std::rand() % 2);
        }
        file << std::endl;
    }

    // закрываем файл
    file.close();

    return 0;
}
