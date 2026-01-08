#include <iostream>
#include <vector>

int main() {
    int N;

    std::cout << "Input the amount of elements:";
    std::cin >> N;
    std::vector<int> vec(N);

    int sum = 0;

    for (int i = 0; i < N; i++) {
        std::cout << "Input " << i << " element" << std::endl;
        std::cin >> vec[i];
        sum += vec[i];
    }

    std::cout << "The arithmetic mean is equal " << (float) sum / N << std::endl;

    return 0;
}
