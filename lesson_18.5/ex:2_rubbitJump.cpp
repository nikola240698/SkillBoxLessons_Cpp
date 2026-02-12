#include <iostream>
#include <limits>

bool inputValue(int &n, int &k) {
    int val1, val2;
    std::cin >> val1 >> val2;

    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect data" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    n = val1;
    k = val2;
    return true;
}

int jumpingCount(int n, int k = 3) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= k; ++i) {
        count += jumpingCount(n - i, k);
    }
    
    return count;
}


int main() {

    int n, k;

    std::cout << "Program for solve the hare and steps problem" << std::endl;
    std::cout << std::endl;

    std::cout << "Input the number of steps and maximum length of the jump: ";
    
    while (!inputValue(n, k)) {
        std::cout << std::endl;
        std::cout << "Try again: ";
    }
  
    std::cout << "Maximum number of ways - " << jumpingCount(n, k) << std::endl;

    return 0;
}
