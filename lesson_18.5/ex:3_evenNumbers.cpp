#include <iostream>
#include <limits>

bool inputValue(long long &val) {
    long long tryVal;
    std::cin >> tryVal;

    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect data" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    val = tryVal;
    return true;
}

void evenNumber(long long &n, int &ans) {
    if (n % 2 == 0) {
        ++ans;
    }
    n /= 10;
    while (n > 0) {
        evenNumber(n, ans);
    }
}

int main() {
    long long n;
    int ans = 0;

    std::cout << "Program for counting even digits in a number" << std::endl;
    std::cout << std::endl;
    std::cout << "Input the long long number: ";
    while (!inputValue(n)) {
        std::cout << "Try again: ";
    }

    evenNumber(n, ans);

    std::cout << "Number of even digits: " << ans;

    return 0;
}
