#include <iostream>
#include <ctime>
// подключаем заголовочный файл базового класса
#include "circle.h"
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"

// функция рандомного создания третьей стороны треугольника с проверкой
double checkSide(const double a, const double b) {
    double c;
    do {
        c = static_cast<double>(std::rand() % 1000) / 100;
    } while ((a + b <= c) || (a + c <= b) || (b + c <= a));
    return c;
}

int main() {

    std::srand(std::time(nullptr));

    Shape* shape = nullptr;

    for (int i = 0; i < 3; ++i) {
        switch (i) {
            case 0: {
                double sideA = static_cast<double>(std::rand() % 1000) / 100;
                double sideB = static_cast<double>(std::rand() % 1000) / 100;
                double sideC = checkSide(sideA, sideB);
                shape = new Triangle(sideA, sideB, sideC);
                break;
            }
            case 1: {
                double sideA = static_cast<double>(std::rand() % 1000) / 100;
                double sideB = static_cast<double>(std::rand() % 1000) / 100;
                shape = new Rectangle(sideA, sideB);
                break;
            }
            case 2: {
                double radius = static_cast<double>(std::rand() % 1000) / 100;
                shape = new Circle(radius);
                break;
            }
            default: shape = nullptr;
        }

        shape->printParams(shape);
        std::cout << "Square: " << shape->square() << std::endl;
        std::cout << "Bounding box dimension: " << std::endl;
        std::cout << "\tWidth: " << shape->dimension().width << std::endl;
        std::cout << "\tHeight: " << shape->dimension().height << std::endl;

        delete shape;
    }


    return 0;



}

