#include <iostream>
#include "surgeon.h"
#include <limits>

// структруа самой операции
struct Operation {
    Coordinates start;
    Coordinates end;
    bool isStarted = false;
    bool isClosed = false;
};

// ввод выбора команды с проверкой
int inputInt(const int lLimit = 1, const int rLimit = 4) {
    int val;
    while (true) {
        std::cout << "-> ";
        std::cin>> val;
        if(std::cin.fail() || std::cin.peek() != '\n' || val < lLimit || val > rLimit) {
            std::cout << "Incorrect data, try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return val;
    }
}

// ввод координат с проверкой
void inputDouble(double &val1, double &val2) {
    while (true) {
        std::cout << "-> ";
        std::cin >> val1 >> val2;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Incorrect data, try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
}

// ради интереса, функция проверяющая, что введенная точка
// принадлежит отрезку, для проверки попадания операция на место разреза
bool isIntersect(const Operation &operation, const Coordinates &coord) {
    // проверяем на коллинеарность
    bool collinear = false;
    double sum = (coord.x - operation.start.x) * (operation.end.y - operation.start.y)
        - (coord.y - operation.start.y) * (operation.end.x - operation.start.x);
    if (!sum) {
        collinear = true;
    }
    if (collinear) {
        // проверяем, что точка не выходит за пределы отрезка
        return coord.x >= std::min(operation.start.x, operation.end.x) &&
                coord.x <= std::max(operation.start.x, operation.end.x) &&
                coord.y >= std::min(operation.start.y, operation.end.y) &&
                coord.y <= std::max(operation.start.y, operation.end.y);
    }
    return false;
}

// функция создания разреза
void doScalpel(Operation &operation) {
    if (!operation.isStarted) {
        std::cout << "Input the coordinates of the beginning of the cut (in format X Y)" << std::endl;
        inputDouble(operation.start.x, operation.start.y);
        std::cout << "Input the coordinates of the ending of the cut (in format X Y)" << std::endl;
        inputDouble(operation.end.x, operation.end.y);
        operation.isStarted = true;
        scalpel(operation.start, operation.end);
    } else {
        std::cout << "You have already made the cut" << std::endl;
     }
}

// функция наложения зажима
void doHemostat(const Operation &operation) {
    if (operation.isStarted) {
        Coordinates tmp{};
        std::cout << "Specify the point of application of the hemostat (in format X Y)" << std::endl;
        inputDouble(tmp.x, tmp.y);
        hemostat(tmp);
        if (!isIntersect(operation, tmp)) {
            std::cout << "But you missed the cut line..." << std::endl;
        }
    } else {
        std::cout << "Operation is not started!" << std::endl;
    }
}

// функция наложения пинцета 
void doTweezers(const Operation &operation) {
    if (operation.isStarted) {
        Coordinates tmp{};
        std::cout << "Specify the point of application of the tweezer (in format X Y)" << std::endl;
        inputDouble(tmp.x, tmp.y);
        hemostat(tmp);
        if (!isIntersect(operation, tmp)) {
            std::cout << "But you missed the cut line..." << std::endl;
        }
    } else {
        std::cout << "Operation is not started!" << std::endl;
    }
}

// функция создания шва 
void doSuture(Operation &operation) {
    if (operation.isStarted) {
        Coordinates startSut, endSut;
        std::cout << "Input the coordinates of the beginning of the suture (in format X Y)" << std::endl;
        inputDouble(startSut.x, startSut.y);
        std::cout << "Input the coordinates of the ending of the suture (in format X Y)" << std::endl;
        inputDouble(endSut.x, endSut.y);
        suture(startSut, endSut);
        if (!isIntersect(operation, startSut) || !isIntersect(operation,endSut)) {
            std::cout << "But you're stitching past the cut..." << std::endl;
        }
        if (startSut.x == operation.start.x && startSut.y == operation.start.y
            && endSut.x == operation.end.x && endSut.y == operation.end.y) {
            operation.isClosed = true;
        }
    } else {
        std::cout << "Operation is not started!" << std::endl;
    }
}

int main() {

    std::cout << "Today you are a real surgeon!" << std::endl;
    std::cout << "You will have to perform an operation." << std::endl;
    std::cout << "The main thing is not to kill the patient and watch your movements." << std::endl;
    std::cout << "Good luck! The operation begins..." << std::endl;
    std::cout << std::endl;

    Operation operation;

    while (true) {
        comandList();
        int command = inputInt();

        switch (command) {
            case 1: doScalpel(operation);
                break;
            case 2: doHemostat(operation);
                break;
            case 3: doTweezers(operation);
                break;
            case 4: doSuture(operation);
                break;
        }
        if (operation.isStarted && operation.isClosed) {
            std::cout << "The operation was successful!" << std::endl;
            break;
        }
    }
  
    return 0;
}
