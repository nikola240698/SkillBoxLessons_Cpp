#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float leftBorder, rightBorder, pointPosition;
    float pointBrightness;

    cout << "Программа для определения яркости точки гардиента" << endl;
    cout << "по заданным границам и положению точки" << endl << endl;

    while (true) {
        cout << "Введите яркость левой границы градиента: ";
        cin >> leftBorder;
        cout << "Введите яркость правой границы градиента: ";
        cin >> rightBorder;
        cout << "Введите положение точки между границами (0.0-1.0): ";
        cin >> pointPosition;

        if (leftBorder < 0 || rightBorder > 255) {
            cout << "Ошибка! Вышли за пределы возможных границ градиента!" << endl;
        } else if (leftBorder >= rightBorder) {
            cout << "Ошибка! Левая граница должна быть левой!" << endl;
        } else if (pointPosition < 0.f || pointPosition > 1.0f) {
            cout << "Ошибка! Положение точки указано не верно!" << endl;
        } else {
            break;
        }
    }

    pointBrightness = (rightBorder - leftBorder) * pointPosition + leftBorder;

    cout << "Яркость точки: " << pointBrightness << endl;

}
