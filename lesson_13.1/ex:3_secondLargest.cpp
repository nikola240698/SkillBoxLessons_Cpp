#include <iostream>
#include <vector>
#include <cctype>

int main() {

    int vecSize;
    std::cout << "What number of elements are needed? ";
    std::cin >> vecSize;

    if (!isdigit(vecSize) && vecSize < 2) {
        std::cout << "Incorrect data" << std::endl;
        return -1;
    }

    std::vector<int> vec(vecSize);

    for (int i = 0; i < vecSize; i++) {
        std::cout << "The " << i << " element: ";
        std::cin >> vec[i];
    }

    int first = vec[0];
    int second = vec[1];

    for (int i = 1; i < vecSize; i++) {
        if (vec[i] > first) {
            second = first;
            first = vec[i];
        } else if (vec[i] > second) {
            second = vec[i];
        }
    }

    std::cout << "The second largest number " << second << std::endl;

    return 0;
}
