#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float timeMove, weight, engineForce;
    float resultDistnace;

    cout << "Программа для расчета пройденного расстояния космического корабля" << endl;
    cout << endl;

    while (true) {
        cout << "Укажите массу корабля [кг]: ";
        cin >> weight;
        cout << "Укажите силу тяги двигателя корабля [Н]: ";
        cin >> engineForce;
        cout << "Укажите время работы двигателя [сек]: ";
        cin >> timeMove;
        cout << endl;

        // проверяем условие ввода данных
        if (weight < 0 || engineForce < 0 || timeMove < 0
            || cin.fail() || cin.peek() != '\n') {
            // выводим сообщение об ошибке
            cout << "Ошибка ввода данных" << endl;
            // очищаем консоль ввода данных
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        } else {
            break;
        }

    }

    // определяем пройденное расстояние в метрах
    resultDistnace = (engineForce / weight) * pow(timeMove, 2) / 2.0f;

    // переводим в километры
    resultDistnace /= 1000;

    cout << "Через " << timeMove << " секунд  корабль окажется на расстоянии в "
        << resultDistnace << " км" << endl;

}
