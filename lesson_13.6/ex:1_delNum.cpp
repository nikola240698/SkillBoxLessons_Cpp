#include <iostream>
#include <vector>
#include <limits>
#include <string>

// функция вывода вектора в консоль
void showBuffer(const std::vector<int> &vec) {
    std::cout << "{ ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "}" << std::endl;
}

// функция сдвига переменных в векторе по кругу (типа циклического буфера)
void shiftVector (std::vector<int> &vec) {
    int tmp = vec.back();
    for (int j = 0; j < vec.size(); j++) {
        if (j == vec.size() - 1) {
            vec[vec.size() - 1 - j] = tmp;
        } else {
            vec[vec.size() - 1 - j] = vec[vec.size() - 2 - j];
        }
    }
}

// функция ввода числа int с проверкой верного ввода
int inputNum(const std::string &str) {
    while(true)
    {
        int value;
        std::cout << str;
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

// функция добавления данных в вектор
void inputToVector (std::vector<int> &vec) {
    std::string str;
    for (int i = 0; i < vec.size(); i++) {
        str = "Input number " + std::to_string(i) + ": ";
        vec[i] = inputNum(str);
    }
}

int main() {

    std::cout << "Program for deleting repeating number in list" << std::endl;
    std::cout << std::endl;

    std::string numN = "Input vector size: ";
    int n = inputNum(numN);

    std::vector<int> vec(n);

    std::cout << "Input the list of number: " << std::endl;
    inputToVector(vec);

    std::string numX = "Input number to delete: ";
    int x = inputNum(numX);

    int sz = vec.size();

    for (int i = 0; i < sz; i++) {
        if (vec.back() == x) {
            vec.pop_back();
        } else {
            shiftVector(vec);
        }
    }

    std::cout << "Result - ";
    showBuffer(vec);

    return 0;
}
