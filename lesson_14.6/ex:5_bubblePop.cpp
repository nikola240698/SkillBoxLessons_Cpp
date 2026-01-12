#include <iostream>
#include <limits>

void inputNum(int &i, int &j) {
    while(true)
    {
        int a, b;
        std::cin >> a >> b;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (a < 0 || a > 11 || b < 0 || b > 11) {
            std::cout << "Incorrect coordinates" << std::endl;
        } else {
            i = a;
            j = b;
            break;
        }
    }
}

void createMatrix(auto mtrx[][12],const auto value) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            mtrx[i][j] = value;
        }
    }
}

void showBoard(const char arr[][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void popBubble(bool state[][12], char pop[][12],int &startI, int &startJ, int &endI, int &endJ, int &counter) {
    // если вдруг указаны коорд-ты прав.верх.угла->лев.ниж.угла
    if (startI < endI && startJ > endJ )
        std::swap(startJ, endJ);

    // если вдруг указаны коорд-ты прав.ниж.угла->лев.верх.угла
    if (startI > endI && startJ > endJ ) {
        std::swap(startI, endI);
        std::swap(startJ, endJ);
    }

    // если вдруг указаны коорд-ты лев.ниж.угла->прав.верх.угла
    if (startI > endI && startJ < endJ) {
        std::swap(startI, endI);
    }

    for (int i = startI; i <= endI; i++) {
        for (int j = startJ; j <= endJ; j++) {
            if (state[i][j]) {
                std::cout << "Pop! ";
                state[i][j] = false;
                pop[i][j] = 'x';
                --counter;
            }
        }
    }
    std::cout << std::endl;
}

int main () {

    bool popSate[12][12];
    char popChar[12][12];
    int popCount = 12 * 12;
    int strtI, strtJ, endI, endJ;

    createMatrix(popSate, true);
    createMatrix(popChar, 'o');

    std::cout << "Program for calming nerves. Pop!" << std::endl;
    std::cout << "We will pop bubble wrap!" << std::endl;
    std::cout << std::endl;
    showBoard(popChar);

    while (true) {
        std::cout << "Input start coordinates [x][y]: ";
        inputNum(strtI, strtJ);

        std::cout << "Input end coordinates [x][y]: ";
        inputNum(endI, endJ);

        popBubble(popSate, popChar, strtI, strtJ, endI, endJ, popCount);
        showBoard(popChar);

        if (popCount == 0) break;
    }

    std::cout << std::endl;
    std::cout << "Oops... The bubble wrap is over!!!" << std::endl;

    return 0;

}
