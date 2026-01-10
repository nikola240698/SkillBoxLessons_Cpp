#include <iostream>
#include <vector>

int main() {

    std::vector<float> price = {2.5, 4.25, 3.0, 10.0};
    std::vector<int> goods = {1, 1, 0, 3};

    float  sum = 0;

    std::cout << "Program for calculating cost of goods sold" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < goods.size(); i++) {
        if (goods[i] < 0 || goods[i] > price.size() - 1) {
            std::cout << "Incorrect price index" <<std::endl;
            return -1;
        }
        sum += price[goods[i]];
    }

    std::cout << "Total price : " << sum << std::endl;

    return 0;
}
