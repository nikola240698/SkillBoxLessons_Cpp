#include <iostream>
#include <vector>

int main() {
  
    int N;

    std::cout << "Input the amount of elements:";
    std::cin >> N;
    std::vector<float> vec(N);

    for (int i = 0; i < N; i++) {
        std::cout << "Input " << i << " element" << std::endl;
        std::cin >> vec[i];

    }

    std::cout << "Revers vector view:" << std::endl;
    for (int i = (N - 1); i >= 0; i--) {
        std::cout << vec[i] << " ";
    }
  
    return 0;
}
