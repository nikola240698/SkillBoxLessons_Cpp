#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <string>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    string realNumber;

    cout << "Program for checking correct real number" << endl;
    cout << endl;

    // вводим данные
    cout << "Input real number: ";
    cin >> realNumber;

    // флаг вещетсвенного числа
    bool real = false;    

    // счетчики точек и цифр
    int pointNum = 0, numberNum = 0;

    // читаем строку
    for (int i = 0; i < realNumber.length(); i++) {

        // проверяем, что состоит из разрешенных знаков
        if (realNumber[i] != '-' && realNumber[i] != '.'
        && (realNumber[i] < '0' || realNumber[i] > '9')) {
            real = false;
            break;
        }

        // считаем количество точек
        if (realNumber[i] == '.') {
            pointNum++;
        }
        
        // считаем количество цифр
        if (realNumber[i] >= '0' && realNumber[i] <= '9') {
            numberNum++;
        }

        // проверяем что одна или нет точек и цифр больше нуля
        if (pointNum <= 1 && numberNum != 0) {
            real = true;
        } else {
            real = false;

        }
    }

    // выводим результат
    if (real) {
        cout << "Number is real" << endl;
    } else {
        cout << "Numer isn't real" << endl;
    }
}
