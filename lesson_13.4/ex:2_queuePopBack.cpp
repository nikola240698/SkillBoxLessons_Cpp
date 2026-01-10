#include <iostream>
#include <vector>

int main() {

    std::vector<int> queueRobot;
    int value = 0;

    while (true) {
        std::cout << "Input the robot's serial number: ";
        std::cin >> value;

        if (value == -1) break;

        //     !queueRobot.empty()
        while (queueRobot.size() != 0 && queueRobot[queueRobot.size() - 1] < value) {
            queueRobot.pop_back();
        }

        queueRobot.push_back(value);
    }

    for (int i = 0; i < queueRobot.size(); i++) {
        std::cout << queueRobot[i] << " ";
    }

    return 0;
}
