#include <iostream>
#include <vector>

int main() {

    std::vector<int> queueRobot;
    int value = 0;

    while (value != -1) {
        std::cout << "Input the robot's serial number: ";
        std::cin >> value;
        queueRobot.push_back(value);
    }

    for (int i = 0; i < queueRobot.size(); i++) {
        std::cout << queueRobot[i] << " ";
    }

    return 0;
}
