#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    float health, magicResisnatce, dmgFireBall;

    cout << "---------- Immolate Improved! ----------" << endl << endl;
    cout << "На пути у Вас повстречался ОРК!" << endl;
    cout << "Давайте атакуем его огненными шарами!" << endl;
    cout << "Но учтите, что у него есть сопротивлении Магиии" << endl;

    while (true) {
        cout << "Подскажите, какое количество здоровья у него Вы видите? ";
        cin >> health;
        cout << "Рядом со здоровьем виднеется его сопротивление магии, укажите тоже: ";
        cin >> magicResisnatce;
        if (cin.fail() || cin.peek() != '\n') {
            // выводим сообщение об ошибке
            cerr << "Ошибка ввода данных" << endl;
        }else if (health < 0 || magicResisnatce < 0) {
            cout << "Вы ввели очень маленькое значение" << endl;
        } else if (health > 1 || magicResisnatce > 1 || cin.fail() || cin.peek() != '\n') {
            cout << "Вы ввели очень большое значение" << endl;
        } else {
            break;
        }
        // очищаем консоль ввода данных
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (health > 0) {
        cout << "Каким уроном будет наш огненный шар? ";
        cin >> dmgFireBall;
        // проверяем условие ввода
        if (dmgFireBall < 0 || dmgFireBall > 1 || cin.fail() || cin.peek() != '\n') {
            cout << "Введено не верное значение" << endl;
            // очищаем консоль ввода данных
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // начинаем цикл заново
            continue;
        }
       
        // "наносим урон"
        health -= (dmgFireBall - (dmgFireBall * magicResisnatce));

        // избавляемся от отрицательного значения здоровья
        if (health < 0) {
            health = 0;
        }

        // выводим результат сражения
        cout << "У орка осталось " << health << " здоровья" << endl;
    }

    // поздравляем игрока
    cout << "Поздравляем! Орк побежден" << endl;
}
