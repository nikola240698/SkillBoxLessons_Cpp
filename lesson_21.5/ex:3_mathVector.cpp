#include <iostream>
#include <cmath>

// структура вектора
struct VectorSc {
    double x;
    double y;
};

// функция контроля ввода координат вектора
VectorSc inputCoord(VectorSc &vec) {
    double a, b;
    while (true) {
        std::cin >> a >> b;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            return {vec.x = a, vec.y = b};
        }
    }
}

// функция контроля ввода вещественных чисел
double inputDouble() {
    double num;
    while (true) {
        std::cin >> num;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            return num;
        }
    }
}

// функция сложения векторов
VectorSc add(const VectorSc &a, const VectorSc &b) {
    return {a.x + b.x, a.y + b.y};
}

// функция вычитания двух векторов
VectorSc subtract(const VectorSc &a, const VectorSc &b) {
    return {a.x - b.x, a.y - b.y};
}

// функция умножения вектора на скаляр
VectorSc scale(const VectorSc &a, const double &scal) {
    return {a.x * scal, a.y * scal};
}

// функция нахождения длины вектора
double length(const VectorSc &a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

// функция нормализации вектора
VectorSc normalize(const VectorSc &a) {
    const double len = length(a);

    // проверяем на нулевую длину вектора
    if (len == 0) {
        std::cout << "The zero vector cannot be normalized!" << std::endl;
        return {0, 0};
    }
    return {a.x / len, a.y / len};
}

// функция произведения векторов
double product(const VectorSc &a, const VectorSc &b) {
    return a.x * b.x + a.y + b.y;
}

// функция печати вектора
void printVec(const VectorSc &a) {
    std::cout << "(" << a.x << ";" << a.y << ")";
}

// вывод списка операций
void printList() {
    std::cout << "List of operations:" << std::endl;
    std::cout << "add \t- vector addition" << std::endl;
    std::cout << "subt \t- vector subtraction" << std::endl;
    std::cout << "scale \t- multiplying a vector by a scalar" << std::endl;
    std::cout << "length \t- finding the length of a vector" << std::endl;
    std::cout << "norm \t- normalizing a vector" << std::endl;
    std::cout << "help \t- show list of commands" << std::endl;
    std::cout << "exit \t- exit the program" << std::endl;
    std::cout << std::endl;
}

// основная функция выбора
void selectOperation() {
    std::string select;
    while (true) {
        std::cout << "Input the comand -> ";
        std::cin >> select;

        if (select == "add") {
            VectorSc a, b;
            std::cout << "Input the coordinates of the first vector ->";
            inputCoord(a);
            std::cout << "Input the coordinates of the second vector ->";
            inputCoord(b);
            std::cout << "Resulting vector ";
            printVec(add(a, b));
            std::cout << std::endl;
        } else if (select == "subt") {
            VectorSc a, b;
            std::cout << "Input the coordinates of the first vector ->";
            inputCoord(a);
            std::cout << "Input the coordinates of the second vector ->";
            inputCoord(b);
            std::cout << "Resulting vector ";
            printVec(subtract(a, b));
            std::cout << std::endl;
        } else if (select == "scale") {
            VectorSc a;
            double b;
            std::cout << "Input the coordinates of the first vector ->";
            inputCoord(a);
            std::cout << "Input the real number ->";
            b = inputDouble();
            std::cout << "Resulting vector ";
            printVec(scale(a, b));
            std::cout << std::endl;
        } else if (select == "length") {
            VectorSc a;
            std::cout << "Input the coordinates of the vector ->";
            inputCoord(a);
            std::cout << "Length of the vector = " << length(a) << std::endl;
        } else if (select == "norm") {
            VectorSc a, b;
            std::cout << "Input the coordinates of the vector ->";
            inputCoord(a);
            std::cout << "Resulting vector ";
            printVec(normalize(a));
            std::cout << std::endl;
        } else if (select == "help") {
            printList();
        } else if (select == "exit") {
            break;
        } else {
            std::cout << "Incorrect command!" << std::endl;
        }
    }
}


int main() {
    std::cout << "A program for working with scalar vectors" << std::endl << std::endl;
  
    std::cout << "For starting you need select an operation" << std::endl;
    printList();
  
    selectOperation();

    return 0;
}
