#include <iostream>
#include <vector>

void addInVector(std::vector<int> &vec, int &element) {
    std::vector<int> newVec(vec.size() + 1);
    for (int i = 0; i < vec.size(); i++) {
        newVec[i] = vec[i];
    }
    newVec[vec.size()] = element;
    vec = newVec;
}

void addToPosition(std::vector<int> &vec, int &val, int &position) {
    if (position > vec.size()) {
        position = vec.size();
        addInVector(vec, val);
    } else {
        std::vector<int> newVecPos(vec.size() + 1);
        bool pos = false;

        for (int i = 0; i < newVecPos.size(); i++) {

            if (i == position) {
                pos = true;
                newVecPos[i] = val;
            } else if (pos) {
                newVecPos[i] = vec[i - 1];
            } else {
                newVecPos[i] = vec[i];
            }
        }
        vec = newVecPos;
    }
}

int main() {
    std::vector<int> queue;
    int num = 0;
    int pos;
  
    while (true) {
        std::cout << "Input your number and position: ";
        std::cin >> num >> pos;
        if (num == -1 || pos == -1) {
            break;
        } else {
            addToPosition(queue, num, pos);
        }
    }

    std::cout << "Current queue:" << std::endl;
    for (int i = 0; i < queue.size(); i++) {
        std::cout << queue[i] << " ";
    }

    return 0;
}
