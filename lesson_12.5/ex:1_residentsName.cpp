#include <iostream>
#include <string>

int main() {

    std::string residents[10];
    int apartNum;

    for (int i = 0; i < 10; i++) {
        std::cout << "Input name of the resident " << (i + 1) << " apartment: " << std::endl;;
        std::getline(std::cin, residents[i]);
    }

    for (int j = 0; j < 3; ) {
        std::cout << "Input number of the apartment: ";
        std::cin >> apartNum;
        std::cout << std::endl;
        // хотел тут ещё сделать проверку, что введено число при помощи
        // isdigit(apartNum), но в условии запрещено подключать другие библиотеки
        if (apartNum < 1 || apartNum > 10) {
            std::cout << "Incorrect number" << std::endl;
        } else {
            std::cout << residents[apartNum - 1] << std::endl;;
            j++;
        }
    }
    return 0;
}
