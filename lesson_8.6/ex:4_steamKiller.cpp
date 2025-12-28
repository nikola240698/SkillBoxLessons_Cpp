#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float fileSize, downloadSpeed;
    
    // вводим данные
    while (true) {
        cout << "Введите размер файла [МБ] ";
        cin >> fileSize;
        cout << "Введите скорость Вашего интерент-соединения [МБ/сек] ";
        cin >> downloadSpeed;
        // проверяем условие ввода данных
        if (fileSize < 0 || downloadSpeed < 0 || cin.fail() || cin.peek() != '\n') {
            // выводим сообщение об ошибке
            cout << "Ошибка ввода данных" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // дополнительные перменне
    float downloadSize;
    int timeCounter = 0;
    
    // качаем файл как минимум одну секунду
    do {
        timeCounter++;
        downloadSize += downloadSpeed;
        if (downloadSize > fileSize) {
            downloadSize = fileSize;
        }
        cout << "Прошло " << timeCounter << " сек. Скачано " << downloadSize << " из "
            << fileSize << " МБ (" << (int) (downloadSize / fileSize * 100.f) << "%)" << endl;
    } while (downloadSize < fileSize);

    // результат
    cout << "Ваш файл успешно скачан! Прошло " << timeCounter << " сек." << endl;

}
