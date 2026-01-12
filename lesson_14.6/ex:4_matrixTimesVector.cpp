#include <iostream>
#include <limits>

float inputNum() {
    while(true)
    {
        float value;
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

void inputMatrix(float mtrx[][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << "Input a" << (i + 1) << (j + 1) << ": ";
            mtrx[i][j] = inputNum();
        }
    }
}

void multMtrxVec(const float mtrx[][4], const float (&vec)[4], float (&result)[4]) {
    float sum;
    for (int i = 0; i < 4; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += mtrx[i][j] * vec[j];
        }
        result[i] = sum;
    }

}

void showVector(const float (&arr)[4]) {
    for (int i = 0; i < 4; i++) {
        std::cout << arr[i] << std::endl;
    }
}

int main() {

    float mtrxA[4][4];
    float vecB[4];
    float vecC[4];

    std::cout << "Program for multiplying a square matrix A[4][4] by a vector[4]" << std::endl;
    std::cout << std::endl;

    std::cout << "Input matrix A: " << std::endl;
    inputMatrix(mtrxA);

    std::cout << "Input vector B:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "Input b" << (i + 1) << ": ";
        vecB[i] = inputNum();
    }

    multMtrxVec(mtrxA, vecB, vecC);

    std::cout << "The resault of A x B:" << std::endl;
    showVector(vecC);

    return 0;
}
