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
    std::vector<int> queue;
    int num = 0;
  
    while (true) {
        std::cout << "Input your number: ";
        std::cin >> num;
        if (num == -1) {
            break;
        } else {
            addInVector(queue, num);
        }
    }
  
    int sum = 0;
    for (int i = 0; i < queue.size(); i++) {
        sum += queue[i];
    }
  
    std::cout << "number of patients: " << queue.size() << std::endl;
    std::cout << "Arithmetic mean: " << (float) sum / queue.size() << std::endl;

    return 0;
}
