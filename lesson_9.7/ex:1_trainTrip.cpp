#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <string>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    string depTime;
    string arrTime;

    int depHour, depMinute;
    int arrHour, arrMinute;

    cout << "Programm for calculating train tavel time" << endl;
    cout << endl;

    // цикл проверки вводимых значений времени отправки
    while (true) {
        cout << "Input the train departure time [HH:MM]: ";
        cin >> depTime;

        // проверяем, что ввели время в нужном формате
        if (depTime.length() != 5 || depTime[2] != ':'
                || depTime[0] < '0' || depTime[0] > '9'
                || depTime[1] < '0' || depTime[1] > '9'
                || depTime[3] < '0' || depTime[3] > '9'
                || depTime[4] < '0' || depTime[4] > '9') {
            cout << "Incorrect format data!" << endl;
        } else {
            // переводим вводимые строки в числа
            depHour = 10 * (depTime[0] - '0') + (depTime[1] - '0');
            depMinute = 10 * (depTime[3] - '0') + (depTime[4] - '0');

            // проверяем на корректность время
            if (depHour < 0 || depHour > 24 || depMinute < 0
                    || depMinute > 60 ) {
                cout << "Incorrect time value" << endl;
            } else {
                break;
            }
        }
    }

    // цикл проверки вводимых значений времени прибытия
    while (true) {
        cout << "Input the train arrival time [HH:MM]: ";
        cin >> arrTime;

        // проверяем, что ввели время в нужном формате
        if (arrTime.length() != 5 || arrTime[2] != ':'
                || arrTime[0] < '0' || arrTime[0] > '9'
                || arrTime[1] < '0' || arrTime[1] > '9'
                || arrTime[3] < '0' || arrTime[3] > '9'
                || arrTime[4] < '0' || arrTime[4] > '9') {
            cout << "Incorrect format data!" << endl;
                } else {
                    // переводим вводимые строки в числа
                    arrHour = 10 * (arrTime[0] - '0') + (arrTime[1] - '0');
                    arrMinute = 10 * (arrTime[3] - '0') + (arrTime[4] - '0');

                    // проверяем на корректность время
                    if (arrHour < 0 || arrHour > 24 || arrMinute < 0
                            || arrMinute > 60 ) {
                        cout << "Incorrect time value" << endl;
                            } else {
                                break;
                            }
                }
    }

    int travelHour, travelMinute;

    // проверка, что час прибытия меньше чем отправки
    if (arrHour < depHour) {
        travelHour = 24 - depHour + arrHour;
    } else {
        travelHour = arrHour - depHour;
    }

    // проверка, что минуты прибытия меньше чем отправки
    if (arrMinute < depMinute) {
        travelMinute = 60 - depMinute + arrMinute;
        travelHour--;
    } else {
        travelMinute = arrMinute - depMinute;
    }

    // выводим резульат
    cout << "The trip took " << travelHour << " hour " << travelMinute << " minute" << endl;
}
