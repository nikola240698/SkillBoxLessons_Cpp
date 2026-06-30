#include <iostream>
#include <cmath>

// цвета
enum Color {
    NONE = 0,
    RED,
    BLUE,
    GREEN
};

// функция получения названия цвета
std::string getColor(const int index) {
    switch (index) {
        case RED: return "red";
        case BLUE: return "blue";
        case GREEN: return "green";
            default: return "none";
    }

}

// базовый класс фигур
class Figure {
    // переменные класса
    double x = 0;
    double y = 0;
    int color = 0;
public:
    // инициализация переменных класса
    Figure(const double inX, const double inY, const int inColor)
        : x(inX), y(inY) {
        // проверяем что цвета введены в диапазоне
        if (inColor < 0 || inColor > 3) {
            color = 0;
        } else {
            color = inColor;
        }
    }
};

// дочерний клас Круг
class Circle: public Figure{
    // переменные класса
    double radius = 0;
public:
    // инициализируем поля класса
    Circle(double inX, double inY, int inColor, double inRadius)
        :  Figure(inX, inY, inColor), radius(inRadius) {}

    // метод определения площади фигуры
    double areaFigure() const {
        return std::numbers::pi * radius * radius;
    }

    // метод определения сторон описывающего треугольника
    std::pair<double, double> circumscribed() const {
        return {2 * radius, 2 * radius};
    }
};

// дочерний метод Квадрат
class Square: public Figure{
    // переменные класса
    double side = 0;
public:
    // инициализируем поля класса
    Square(double inX, double inY, int inColor, double inSide)
        :  Figure(inX, inY, inColor), side(inSide) {}

    // метод определения площади фигуры
    double areaFigure() const {
        return side * side;
    }

    // метод определения сторон описывающего треугольника
    std::pair<double, double> circumscribed() const {
        return {side, side};
    }
};

// дочерний метод Треугольник
class Triangle: public Figure{
    // переменные класса
    double side = 0;
public:
    // инициализируем поля класса
    Triangle(double inX, double inY, int inColor, double inSide)
        :  Figure(inX, inY, inColor), side(inSide) {}

    // метод определения площади фигуры
    double areaFigure() const {
        return side * side * std::sqrt(3) / 4;
    }

    // метод определения сторон описывающего треугольника
    std::pair<double, double> circumscribed() const {
        return {side, side};
    }
};

// дочерний метод Прямоугольник
class Rectangle: public Figure{
    // переменные класса
    double width = 0;
    double height = 0;
public:
    // инициализируем поля класса
    Rectangle(double inX, double inY, int inColor, double inWidth, double inHeight)
        :  Figure(inX, inY, inColor), width(inWidth), height(inHeight) {}

    // метод определения площади фигуры
    double areaFigure() const {
        return width * height;
    }

    // метод определения сторон описывающего треугольника
    std::pair<double, double> circumscribed() const {
        return {width, height};
    }
};

// функция проверки ввода Double
double inDouble() {
    double value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Incorrect data. Try again ->" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            return value;
        }
    }
}

// функция проверки ввода Int
int inInt() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Incorrect data. Try again ->" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}


int main() {

    std::string command;

    // заправшиваем координаты и цвет
    std::cout << "Input the coordinates [x] ->";
    double x = inDouble();
    std::cout << "Input the coordinates [y] ->";
    double y = inDouble();
    std::cout << "Input the color (0 - None, 1 - Red, 2 - Blue, 3 - Green) -> ";
    int color = inInt();
    // выбираем фигурур и выводим результаты
    while (true) {
        std::cout << "Input the type of the figure (circle, triangle, rectangle, square) ->";
        std::cin >> command;
        if (command == "circle") {
            // узнаем необходимые данные
            std::cout << "Input the radius ->";
            double radius = inDouble();
            // создаем объект
            Circle* circle = new Circle(x, y, color, radius);
            // выводим данные в консоль
            std::cout << "Area of the figure " << circle->areaFigure() << std::endl;
            std::cout << "The minimum size of the sides of the \ncircumscribed rectangle is equal to "
                << circle->circumscribed().first << " and " << circle->circumscribed().second << std::endl;
            delete circle;
            break;
        }
        if (command == "triangle") {
            // узнаем необходимые данные
            std::cout << "Input the side ->";
            double side = inDouble();
            // создаем объект
            Triangle* triangle = new Triangle(x, y, color, side);

            // выводим данные в консоль
            std::cout << "Area of the figure " << triangle->areaFigure() << std::endl;
            std::cout << "The minimum size of the sides of the \ncircumscribed rectangle is equal to "
                << triangle->circumscribed().first << " and " << triangle->circumscribed().second << std::endl;
            delete triangle;
            break;
        }
        if (command == "square") {
            // узнаем необходимые данные
            std::cout << "Input the side ->";
            double side = inDouble();
            // создаем объект
            Square* square = new Square(x, y, color, side);

            // выводим данные в консоль
            std::cout << "Area of the figure " << square->areaFigure() << std::endl;
            std::cout << "The minimum size of the sides of the \ncircumscribed rectangle is equal to "
                << square->circumscribed().first << " and " << square->circumscribed().second << std::endl;
            delete square;
            break;
        }
        if (command == "rectangle") {
            // узнаем необходимые данные
            std::cout << "Input the width ->";
            double width = inDouble();
            std::cout << "Input the height ->";
            double height = inDouble();
            // создаем объект
            Rectangle* rectangle = new Rectangle(x, y, color, width, height);

            // выводим данные в консоль
            std::cout << "Area of the figure " << rectangle->areaFigure() << std::endl;
            std::cout << "The minimum size of the sides of the \ncircumscribed rectangle is equal to "
                << rectangle->circumscribed().first << " and " << rectangle->circumscribed().second << std::endl;
            delete rectangle;
            break;
        }
        std::cout << "Incorrect comman. Try again" << std::endl;
    }

    return 0;
}
