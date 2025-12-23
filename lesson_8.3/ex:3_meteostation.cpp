#include <iostream>

using namespace std;

int main () {

    int lowLevel, highLevel, stepLevel;
    float tempF, tempC;

    cout << "Программа для отображения таблицы температуры" << endl;
    cout << "Для удобства используем две шкалы измерения" << endl;

    cout << "Введите нижнюю границу: ";
    cin >> lowLevel;
    cout << "Введите верхнюю границу: ";
    cin >> highLevel;
    cout << "Введите шаг измерения: ";
    cin >> stepLevel;

    cout << endl;
    cout << "C\tF" << endl << endl;

    tempC = lowLevel;
    tempF = (float) tempC * 9.0f / 5.0f + 32.0f;

    cout << (int) tempC << "\t" << (int) tempF << endl;

    do {
        tempC += stepLevel;
        tempF = (float) tempC * 9.0f / 5.0f + 32.0f;
        cout << (int) tempC << "\t" << (int) tempF << endl;
    } while (tempC <= highLevel);

}
