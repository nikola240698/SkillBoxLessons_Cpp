#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <string>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    string hidNum;
    string checkNum;
    int bullsAmount, cowsAmount;

    cout << "Program simulating the game \"Bulls and Cows\"" << endl;
    cout << endl;

    // контроль вводимых данных заданного числа
    while (true) {
        cout << "Input the hidden number (4 number): ";
        cin >> hidNum;

        // флаг правильного значения
        bool rightNum = true;

        // проверяем длину числа
        if (hidNum.length() != 4) {
            cout << "Need 4 number" << endl;
            rightNum = false;
        }

        // проверяем, что введены цифры
        for (int i = 0; i < hidNum.length(); i++) {
            if (hidNum[i] < '0' || hidNum[i] > '9') {
                cout << "Incorrect input data" << endl;
                rightNum = false;
                break;
            }
        }

        if (rightNum) {
            break;
        }
    }

    // начинаем цикл вычисления загаданного числа
    do {
        // контроль вводимых данных проверяемого числа
        while (true) {
            cout << "Input the number to be checked (4 number): ";
            cin >> checkNum;

            // флаг правильного значения
            bool rightNum = true;

            // проверяем длину числа
            if (checkNum.length() != 4) {
                cout << "Need 4 number" << endl;
                rightNum = false;
            }

            // проверяем, что введены цифры
            for (int i = 0; i < checkNum.length(); i++) {
                if (checkNum[i] < '0' || checkNum[i] > '9') {
                    cout << "Incorrect input data" << endl;
                    rightNum = false;
                    break;
                }
            }

            if (rightNum) {
                break;
            }
        }

        /*
         * Используем следующий алгоритм поиска:
         * (т.к. в данных правилах разрешено повторение цифр)
         * Определяем количество быков в числах читая оба числа синхронно
         * Если числа не являются быками, то записываем их в новую строку
         * Далее читаем асинхронно строки в поисках коров, причем:
         * Ищем относительно символов введенного числа
         * Если обнаружили одну корову, то обрываем цикл чтения данной позиции,
         * дабы не встретить "вторую такую же корову"
         * Повторяем пока не найдем всех коров
         */

        // сбрасываем счетчики быков и коров
        bullsAmount = 0;
        cowsAmount = 0;

        // создаем новые строки для записи оставшихся чисел не являющихся быком
        string hidCows = "", checkCows = "";

        // цикл проверки быков и перезаписи чисел
        for (int i = 0; i < hidNum.length(); i++) {
            if (hidNum[i] == checkNum[i]) {
                bullsAmount++;
            } else {
                hidCows += hidNum[i];
                checkCows += checkNum[i];
            }
        }

        // ищем оставшихся коров
        for (int i = 0; i < checkCows.length(); i++) {

            for (int j = 0; j < hidCows.length(); j++) {

                if (checkCows[i] == hidCows[j]) {
                    cowsAmount++;
                    break;
                }
            }
        }

        // выводим результат поиска
        cout << "Bulls are " << bullsAmount << ", cows are " << cowsAmount << endl;
        
    } while (bullsAmount != 4);

    // выводим итоговый результат
    cout << "Congratulation! Hidden number was " << checkNum << endl;
}
