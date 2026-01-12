#include <iostream>
#include <limits>

int inputNum() {
    while(true)
    {
        int value;
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return value;
    }
}

void inputMatrix(int mtrx[][4]) 
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "Input " << (4 * i + j) << " element: ";
            mtrx[i][j] = inputNum();
        }
    }
}

bool checkAndNull (int mtrxA[][4], int mtrxB[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mtrxA[i][j] != mtrxB[i][j]) return false;
            if (j > i) mtrxA[i][j] = 0.f;
        }
    }
    return true;
}

void showArray(int arr[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {

    int mtrxA[4][4];
    int mtrxB[4][4];


    std::cout << "Input first matrix" << std::endl;
    inputMatrix(mtrxA);

    std::cout << "Input second matrix" << std::endl;
    inputMatrix(mtrxB);

    if (checkAndNull(mtrxA, mtrxB)) {
        std::cout << "Matrices are equal!" << std::endl;
        std::cout << "The diagonal matrix:" << std::endl;
        showArray(mtrxA);
    } else {
        std::cout << "Matrix is different!" << std::endl;
    }

    return 0;
}
