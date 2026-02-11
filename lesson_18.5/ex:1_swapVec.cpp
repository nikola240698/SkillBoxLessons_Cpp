#include <iostream>
#include <vector>

void swapvec(std::vector<int> &vec, int arr[]) {
    for (int i = 0; i < vec.size(); i++) {
        int tmp = vec[i];
        vec[i] = arr[i];
        arr[i] = tmp;
    }
}

void showArray(const int arr[]) {
    std::cout << "Array - ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void showVector(const std::vector<int> &vec) {
    std::cout << "Vector - ";
    for (int i = 0; i < 5; ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
  
    std::vector<int> a = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 0};

    std::cout << "Program fow swipping values in vector and array" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Initialized values:" << std::endl;
    showVector(a);
    showArray(b);  
    
    swapvec(a, b);

    std::cout << "Swapped values:" << std::endl;
    showVector(a);
    showArray(b);

    return 0;
}
