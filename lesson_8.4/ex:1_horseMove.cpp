#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float startX, startY, moveX, moveY;

    cout << "Программа для опеределения влзможности совершить ход конем" << endl;
    cout << "в выбранную вами позицию на поле 0.8х0.8 см" << endl << endl;

    while (true) {
        cout << "Введите координаты расположения фигуры: ";
        cin >> startX >> startY;
        cout << "Введите координаты передвижения фигуры: ";
        cin >> moveX >> moveY;

        if (startX < 0 || startX >= 0.9
            || startY < 0 || startY >= 0.9
            || moveX < 0 || moveX >= 0.9
            || moveY < 0 || moveY >= 0.9) cout << "Ошибка ввода даных!" << endl;
        else break;
    }

    float distance = sqrt(
            pow(floor(startX * 10) - floor(moveX * 10), 2)
            + pow(floor(startY * 10) - floor(moveY * 10), 2));


    if ((distance * distance) == 5)
    cout << "Конь может ходить на эту позицию" << endl;
    else cout << "Конь не сможет ходить на эту позицию" << endl;
}
