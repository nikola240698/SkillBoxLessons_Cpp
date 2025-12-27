#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float angleRad, angleGrad;

    cout << "Программа для определения безопасного угла тангажа вашего самолета" << endl << endl;
    cout << "Введите угол тангажа в градусах: ";
    cin >> angleGrad;

    while (angleGrad >= 360) {
        angleGrad -= 360;
    }

    angleRad = angleGrad * 3.14f / 180.f;

    if (angleRad < -0.28f || angleRad > 0.28f) {
        cout << "Угол небезопасен!" << endl;
    } else {
        cout << "Угол безопасен!" << endl;
    }   

}
