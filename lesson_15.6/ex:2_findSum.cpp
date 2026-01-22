#include <iostream>
#include <vector>

int main() {

    std::vector<int> vec = {2, 7, 11, 15};
    int res;

    std::cout << "Input the result: ";
    std::cin >> res;

    for (int i = 0; i < vec.size(); i++) {
        int tmp = res - vec[i];
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] == tmp) {
                std::cout << "In array found numbers " << vec[i] << " and " << vec[j] << std::endl;
                return 0;
            }
        }
    }

    std::cout << "No matches found" << std::endl;

    return 0;
}
