#include <iostream>
#include <sstream>

int main() {

    std::string buffer;

    double a, b;
    char operation;
    double result = 0.0;

    std::cout << "Input your expression (without spaces):" << std::endl;
    std::cin >> buffer;
  
    std::stringstream buffer_stream(buffer);

    buffer_stream >> a >> operation >> b;

    switch (operation) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
        default:
            std::cerr << "Incorrect data";
            return -1;
    }

    std::cout << "Calculating..." << std::endl;
    std::cout << buffer << "=" << result;

    return 0;
}
