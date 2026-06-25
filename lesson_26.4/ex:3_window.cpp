#include <iostream>
#include <limits>

// параметры окна монитора
#define MAX_WIDTH 49
#define MAX_HEIGHT 79

class Window {

    struct Coordinates{
        int x;
        int y;
    };

    Coordinates startPoint{0, 0};   // верхняя левая координата
    Coordinates endPoint{0, 0};     // нижняя правая координата
    int scaleX = 0;                 // ширина окна
    int scaleY = 0;                 // длина окна

    // установка крайней правой точки при изменении размера или положения
    void setEnd(const int& x, const int& y) {
        endPoint.x = startPoint.x + x;
        endPoint.y = startPoint.y + y;
    }

public:

    // метод ввода начальных координат окна с проверкой
    bool setStart(const int& startX, const int& startY) {
        if (startX > MAX_WIDTH || startY > MAX_HEIGHT) {
            return false;
        }
        // если координаты нормальные, то вводим их в параметры окна
        startPoint.x = startX;
        startPoint.y = startY;
        // заполняем координаты нижней точки
        setEnd(scaleX, scaleY);
        return true;
    }

    // метод ввода размеров окна с проверкой
    bool setScale(const int& x, const int& y) {
        if (x < 0 || y < 0) {
            return false;
        }
        // если нормально, то изменяем параметры окна
        scaleX = x;
        scaleY = y;
        // сразу меняем нижнюю правую точку окна
        setEnd(scaleX, scaleY);
        return true;
    }

    Coordinates getStart() const {
        return startPoint;
    }

    Coordinates getEnd() const {
        return endPoint;
    }
};

class Monitor {

    // создаем "карту" монитора
    int monitor[MAX_WIDTH][MAX_HEIGHT] = {0};

public:

    // метод заполнения "карты" монитора и вывода сразу на экран
    void setMonitor(const Window* window) {
        for (int i = 0; i < MAX_WIDTH; ++i) {
            for (int j = 0; j < MAX_HEIGHT; ++j) {
                if (i >= window->getStart().x && i < window->getEnd().x
                    && j >= window->getStart().y && j < window->getEnd().y) {
                    monitor[i][j] = 1;
                } else {
                    monitor[i][j] = 0;
                }
                std::cout << monitor[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

};

// ввод инта с проверкой ввода
int inputInt() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    return value;
}

void commandList() {
    std::cout << "--------- Command list: ---------" << std::endl;
    std::cout << "list\t- show command list" << std::endl;
    std::cout << "move\t- change window position" << std::endl;
    std::cout << "resize\t- change window size" << std::endl;
    std::cout << "display\t- display the monitor" << std::endl;
    std::cout << "close\t- program exit" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << std::endl;
}

int main() {

    Monitor* monitor = new Monitor;
    Window* window = new Window;
    std::string command;

    commandList();

    while (true) {
        std::cout << "Input command -> ";

        std::cin >> command;

        if (command == "list") {
            commandList();
        } else if (command == "move") {
            int x, y;
            std::cout << "Input new coordinates X of the window ->";
            x = inputInt();
            std::cout << "Input new coordinates Y of the window ->";
            y = inputInt();
            if (!window->setStart(x, y)) {
                std::cout << "Incorrect data" << std::endl;
            };
        } else if (command == "resize") {
            int x, y;
            std::cout << "Input new width of the window ->";
            x = inputInt();
            std::cout << "Input new height of the window ->";
            y = inputInt();
            if (!window->setScale(x, y)) {
                std::cout << "Incorrect data" << std::endl;
            }
        } else if (command == "display") {
            monitor->setMonitor(window);
        } else if (command == "close") {
            break;
        } else {
            std::cout << "Incorrect command" << std::endl;
        }
    }

    delete monitor;
    delete window;
  
    return 0;
}
