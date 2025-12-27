#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float liftHeight;
    int floorNumber;

    cout << "Программа для расчета этажа," << endl;
    cout << "на котором застряла большая" << endl;
    cout << "часть лифта башни \"Бурш-Халифа\"" << endl;

    while (true) {
        cout << "Кажите высоту между полом лифта и землей: ";
        cin >> liftHeight;

        if (liftHeight < 0 || liftHeight > (162 * 3.975f)) {
            cout << "Обишибка! Не верные данные" << endl;
        } else {
            break;
        }
    }

    floorNumber = round(liftHeight / 3.975f + 1);

    cout << "Для спасения людей поднимитесь на " << floorNumber << " этаж" << endl;

}
