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

int main() {

    std::vector<int> queue = {5, 13, 25, 45, 19};

    int num = 0;

    while (num != -1) {
        std::cout << "Input your number: ";
        std::cin >> num;
        add(queue, num);
    }

    for (int i = 0; i < queue.size(); i++) {
        std::cout << queue[i] << " ";
    }

    return 0;
}
