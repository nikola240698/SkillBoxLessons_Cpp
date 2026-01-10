#include <iostream>
#include <vector>

int main() {

    std::vector<int> queueRobot;
    int value = 0;

    while (true) {
        std::cout << "Input the robot's serial number: ";
        std::cin >> value;

        if (value == -1) break;

        queueRobot.push_back(value);

        int seats = queueRobot.capacity() - queueRobot.size();
        if (seats <= 2) {
            std::cout << "There are " << seats << " seats left in the room" << std::endl;
        }
    }

    for (int i = 0; i < queueRobot.size(); i++) {
        std::cout << queueRobot[i] << " ";
    }

    return 0;
}
