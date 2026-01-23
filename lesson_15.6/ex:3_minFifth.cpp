#include <iostream>
#include <vector>
#include <limits>

std::vector<int> vec(0);

int inputNum() {
    while(true)
    {
        int value;
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

void addInVector(int &value) {

    // если размер вектора меньше 5, то вставляем число и сортируем
    if (vec.size() < 5) {
        vec.push_back(value);
        for (int i = vec.size() - 1; i > 0; i--) {
            if (vec[i] < vec[i - 1]) {
                std::swap(vec[i], vec[i - 1]);
            }
        }
        return;
    }
    // проверяем что значение не больше максимального
    if (value > vec[4]) {
        return;
    }
    // вставляем число совместно сортируя вектор
    int tmp;
    bool found = false;
    for (int i = 0; i < vec.size(); i++) {
        if (value < vec[i] && !found) {
            tmp = vec[i];
            vec[i] = value;
            found = true;
            continue;
        }
        if (found) {
            tmp += vec[i];
            vec[i] = tmp - vec[i];
            tmp -= vec[i];
        }
    }
}

int main() {

    int num;

    while (true) {
        std::cout << "Input the number: " << std::endl;
        num = inputNum();

        if (num == -1) {
            std::cout << vec[vec.size() - 1] << std::endl;
        } else if (num == -2) {
            return 0;
        } else {
            addInVector(num);
        }
    }

}
