#include <iostream>


int main() {

    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};

    std::cout << "Program find start and repeating numbers in sequence of number" << std::endl;
    std::cout << std::endl;

    int min = numbers[0];
    for (int i = 0; i < 15; i++ ) {
        if (min > numbers[i]) {
            min = numbers[i];
        }
    }

    std::cout << "The sequence starts with a number " << min << std::endl;

    int sum;
    for (int i = 0; i < 15; i++) {
        sum = 0;
        for (int j = 0; j < 15; j++) {
            if (j == i) {
                continue;
            } else {
                sum += (numbers[j] - min);
            }
        }
        if (sum == 91) {
            std::cout << "Repeating number is " << numbers[i] << std::endl;
            break;
        }
    }

}
