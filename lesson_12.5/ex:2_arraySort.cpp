#include <iostream>

int main() {

    // array length
    int arraySize = 15;
    float numbers[arraySize];

    std::cout << "Program for sorting an array of float numbers" << std::endl;
    std::cout << std::endl;

    std::cout << "Input the numbers: " << std::endl;

    for (int i = 0; i < arraySize; i++) {
        std::cout << i << " number: ";
        std::cin >> numbers[i];
    }

    // we use Shake sort
    int start = -1;
    int end = arraySize - 1;
    bool step = true;

    while (step) {
        step = false;
        start++;
        for (int i = start; i < end; i++) {
            if (numbers[i] < numbers[i + 1]) {
                std::swap(numbers[i], numbers[i + 1]);
                step = true;
            }
        }
        if (!step) {
            break;
        }
        end--;
        for (int i = end; i > start; i-- ) {
            if (numbers[i] > numbers[i - 1]) {
                std::swap(numbers[i], numbers[i - 1]);
            }
        }
    }

    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << numbers[i] <<  " " ;
    }

    return 0;
}
