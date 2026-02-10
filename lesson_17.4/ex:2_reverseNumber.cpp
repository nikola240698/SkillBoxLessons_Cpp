#include <iostream>

void reverseInt(int* var) {
    /*
    for (int i = 0; i < 5; ++i) {
        int tmp = *(var + i);
        *(var + i) = *(var + 9 - i);
        *(var + 9 - i) = tmp;
    }
    */

    for (int i = 0; i < 5; ++i) {
        int tmp = var[i];
        var[i] = var[9 - i];
        var[9 - i] = tmp;
    }

}

void showArr(int arr[]) {
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main() {

    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Program for reversing series of number " << std::endl;
    std::cout << "using their pointer" << std::endl;
    std::cout << std::endl;

    std::cout << "Series of number before:\t";
    showArr(num);

    reverseInt(num);

    std::cout << "Series of number after:\t\t";
    showArr(num);

    return 0;
}
