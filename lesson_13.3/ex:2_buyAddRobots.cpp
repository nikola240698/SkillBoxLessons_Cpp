#include <iostream>
#include <vector>

void showRobots (const std::vector<int> &vec, int s) {
    std::string still = "";
    if (s == 1) {
        still = "still ";
    }
    std::cout << "There are " << still << "robots on showcase { ";

    for (int j = 0; j < vec.size(); j++) {
        std::cout << vec[j] << " ";
    }
    std::cout << "}" << std::endl;
}

void deleteInPosition (std::vector<int> &vec, int position) {

    std::vector<int> newVec(vec.size() - 1);
    bool pos = false;
    for (int i = 0; i < vec.size(); i++) {

        if (i == position) {
            pos = true;
        } else if (pos) {
            newVec[i - 1] = vec[i];
        } else {
            newVec[i] = vec[i];
        }
    }
    vec = newVec;

    showRobots(vec, 1);
}

void addRobotInEnd (std::vector<int> &vec) {

    int value;

    std::cout << "Input the robot number: ";
    std::cin >> value;

    vec.resize(vec.size() + 1);
    vec[vec.size() - 1] = value;

    showRobots(vec, 0);

}

void deleteRobot (std::vector<int> &vec) {

    int buyInd;

    std::cout << "Input the robot's index for purchase: ";
    std::cin >> buyInd;

    deleteInPosition(vec, buyInd);

}



int main() {

    int n, k = 0;

    std::cout << "Input the number of robots: ";
    std::cin >> n;
    std::vector<int> robots(n);

    for (int i = 0; i < n; i++) {
        std::cout << "Input the number of robot " << (i + 1) << ": ";
        std::cin >> robots[i];
        std::cout << std::endl;
    }

    showRobots(robots, 0);

    while (true) {
        std::cout << "Input the number K :";
        std::cin >> k;

        if (k == -1) {
            break;
        }
        if (k < 1) {
            std::cout << "Incorrect number" << std::endl;
        } else {

            for (int l = 0; l < k; l++) {
                addRobotInEnd(robots);
                deleteRobot(robots);
            }
        }
    }

    showRobots(robots, 1);
    return 0;
}
