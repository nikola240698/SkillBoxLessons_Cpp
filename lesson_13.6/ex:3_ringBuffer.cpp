#include <iostream>
#include <limits>
#include <vector>

#define BUFFER_SIZE (10)

void addToBuffer(std::vector<int> &vec, const int &value, int pos) {
    if (pos > BUFFER_SIZE - 1) {
        pos = (BUFFER_SIZE - 1);
        for (int i = 0; i < BUFFER_SIZE - 1; i++) {
            vec[i] = vec[i + 1];
        }
    }
    vec[pos] = value;
}

void showBuffer(const std::vector<int> &vec) {
    std::cout << "{ ";
    for (int i = 0; i < vec.capacity(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "}" << std::endl;
}

int inputNum() {
    while(true)
    {
        int value;
        std::cout << "Input number: ";
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return value;
    }
}

int main() {

    int n;
    int count = 0;
    std::vector<int> buffer(BUFFER_SIZE);
    buffer.clear();

    while (true) {
        n = inputNum();
        if (n == -1)
            showBuffer(buffer);
        else {
            addToBuffer(buffer, n, count);
            count++;
        }
    }
    return 0;
}
