#include <iostream>
#include <vector>

void showRobots (std::vector<int> &vec, int s) {
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
}

int main() {

    int n, m, buyInd;

    std::cout << "Input the number of robots: ";
    std::cin >> n;
    std::vector<int> robots(n);

    for (int i = 0; i < n; i++) {
        std::cout << "Input the number of robot " << (i + 1) << ": ";
        std::cin >> robots[i];
        std::cout << std::endl;
    }

    showRobots(robots, 0);

    std::cout << "Input the number M :";
    std::cin >> m;

    if (m <= robots.size() && m >= 0) {
        for (int i = 0; i < m; ) {
            std::cout << "Input the robot's index for purchase: ";
            std::cin >> buyInd;
            std::cout << std::endl;

            if (buyInd < robots.size() && buyInd >= 0) {
                deleteInPosition(robots, buyInd);
                i++;
            } else {
                std::cout << "Incorrect index" << std::endl;
                continue;
            }

            showRobots(robots, 1);

        }
    } else {
        std::cout << "Incorrect number" << std::endl;
    }

    return 0;
}
