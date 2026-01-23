#include <iostream>
#include <vector>
#include <cmath>

void showVector(const std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
//{1, 5, 10, 15, 50, 100}
    std::vector vec = {-100, -50, -5, 1, 10, 15};
    int negInd, posInd;
    bool neg = false;
    bool pos = false;

    for (int i = 0; i <vec.size(); i++) {
        if (vec[i] >= 0 ) {
            posInd = i;
            negInd = posInd - 1;
            pos = true;
            neg = true;
            break;
        }
    }

    // проверяем, что в векторе есть положительные и отрицательные числа
    if (pos && neg) {
        std::vector<int> vecSort;
        while (neg || pos) {

            if (!neg) {
                vecSort.push_back(vec[posInd]);
                posInd++;
            } else if (!pos) {
                vecSort.push_back(vec[negInd]);
                negInd--;
            } else if (vec[posInd] < abs(vec[negInd])) {
                vecSort.push_back(vec[posInd]);
                posInd++;
            } else {
                vecSort.push_back(vec[negInd]);
                negInd--;
            }
            if (negInd < 0)
                neg = false;
            if (posInd >= vec.size())
                pos = false;
        }
      
        showVector(vecSort);
      
    // если числа только одного знака2, то просто выводим тот же вектор
    } else {
        showVector(vec);
    }

    return 0;
}
