#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

bool checkString(const std::string &str) {

    for (int i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void inputString(std::string &str, const std::string &name) {
    while (true) {
        std::cout << "Input the " << name << " part of a number: ";
        std::cin >> str;
        if (checkString(str)) {
            break;
        }
        std::cerr << "Incorrect data" << std::endl;
    }
}


int main() {

    std::string part1, part2;

    inputString(part1, "integer");
    inputString(part2, "fractional");

    double value = std::stod(part1) + (std::stod(part2)/(std::pow(10, part2.size())));

    std::cout << "The resulting number " << value << std::endl;
    
    return 0;
}




