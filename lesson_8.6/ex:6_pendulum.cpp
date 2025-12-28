#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float startAmp, endAmp;
    int counterAmp = 0;

    cout << "Программа для счета колебаний маятника до его остановки" << endl << endl;

    while (true) {
        cout << "Введите начальную и конечную амплитуду: ";
        cin >> startAmp >> endAmp;

        // проверяем условие ввода данных
        if ( endAmp < 0 || startAmp < endAmp || cin.fail() || cin.peek() != '\n') {
            cerr << "Ошибка! Не верно введены данные" << endl;
            // очищаем консоль ввода данных
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // производим расчет
    do {
        counterAmp++;
        // уменьшаем качание
        startAmp -= (startAmp * 0.084f);
        
        /*
        // для проверки
        cout << "Качание " << counterAmp << " Амплитуда " << startAmp << endl;
        */

    } while (startAmp > endAmp);

    cout << "Маятник остановится за " << counterAmp << " качаний" << endl;

}
