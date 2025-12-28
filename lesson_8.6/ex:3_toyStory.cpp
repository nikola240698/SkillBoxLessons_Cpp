#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float barLength, barWidth, barThickness;

    cout << "Программа для правильного подбора бруска при изготовлении кубиков" << endl;
    cout << "В производстве используются кубики размером 5х5х5" << endl;
    cout << "Из которых после собирается набор большого кубика" << endl;
    cout << endl;
    
    while (true) {
        cout << "Введите параметры бруска (д/ш/в): ";
        cin >> barLength >> barWidth >> barThickness;
        // проверяем условие ввода данных
        if (barLength < 5 || barWidth < 5 || barThickness < 5 || cin.fail() || cin.peek() != '\n') {
            // выводим сообщение об ошибке
            cout << "Ошибка ввода данных, создание кубиков не возможно" << endl;
            // очищаем консоль ввода данных
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // "отбрасываем" части бруска из которых не получатся кубики
    // для удобства заведем новые целочисленные переменные
    int barLengthInt = (int) barLength;
    int barWidthInt = (int) barWidth;
    int barThicknessInt = (int) barThickness;
    // приводим стороны бруска кратными 5
    while (barLengthInt % 10 !=0 && barLengthInt % 10 != 5) {
        barLengthInt--;
    }
    while (barWidthInt % 10 !=0 && barWidthInt % 10 != 5) {
        barWidthInt--;
    }
    while (barThicknessInt % 10 !=0 && barThicknessInt % 10 != 5) {
        barThicknessInt--;
    }

    // высчитываем возможное количество кубиков из бруска
    float cubeAmount = (barLengthInt * barWidthInt * barThicknessInt) / 125.0f;
    cout << "Из бруска " << barLength << "x" << barWidth << "x" << barThickness
        << " можно изготовить " << cubeAmount << " кубиков" << endl;

    // определяем количество кубиков в стороне собранного куба
    float cubeBuildSide = floor(cbrt(cubeAmount));

    // выдаем результат, проверив минимально возможный куб
    if (cubeBuildSide < 2) {
        cout << "Кубиков не хватает на сборку большого куба" << endl;
    } else {
        cout << "Из " << cubeAmount << " кубиков можно собрать набор из "
            << pow(cubeBuildSide, 3) << " кубиков" << endl;
    }
}
