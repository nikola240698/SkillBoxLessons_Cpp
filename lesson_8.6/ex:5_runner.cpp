#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float totalDistance, currentPace;

    cout << "Программа для бегуна, помогающая определить средний темп бега" << endl;
    cout << "привет, Сэм! Сколько километров ты сегодня пробежал? ";
    cin >> totalDistance;
    if (totalDistance <= 0) {
        cout << "Не верно введено значение!" << endl;
        exit(5);
    }

    int distanceCounter = 1;
    float pace = 0;

    // высчитваем темп на каждом километре
    do {
        cout << "Какой у тебя был темп на километре " << distanceCounter << "? ";
        cin >> currentPace;
        // проверяем условие ввода данных
        if (currentPace <= 0 || cin.fail() || cin.peek() != '\n') {
            cerr << "Ошибка! Не верно введены данные" << endl;
            // очищаем консоль ввода данных
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        // складываем темп
        pace += currentPace;
        distanceCounter++;
        
    } while (distanceCounter <= totalDistance);

    // высчитываем минуты
    float averagePaceMinute = floor(pace / totalDistance / 60.0f);
    // досчитываем секунды
    float averagePaceSecond = round((pace / totalDistance / 60.0f - averagePaceMinute) * 60.0f);

    // выводим результат
    cout << "Твой средний темп за тренировку: " << averagePaceMinute << " минуты "
        << averagePaceSecond << " секунд" << endl;
}
