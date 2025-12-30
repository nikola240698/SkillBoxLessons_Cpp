#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    char firstX, firstY;
    char secondX, secondY;
  
    // вводим данные
    while (true) {
        cout << "Input the first cell: ";
        cin >> firstX >> firstY;

        // проверяем корректность вводимых данных
        if (firstX < 'a' || firstX > 'h' || firstY < '1' || firstY > '8') {
            cout << "Incorrect data!" << endl;
            continue;
        }
        cout << "Input the second cell: ";
        cin >> secondX >> secondY;
        // проверяем корректность вводимых данных
        if (secondX < 'a' || secondX > 'h' || secondY < '1' || secondY > '8') {
            cout << "Incorrect data!" << endl;
            continue;
        }
        break;
    }

    // убеждаемся, что не стоим на месте
    if (firstX == secondX && firstY == secondY) {
        cout << "You are standing still" << endl;
    } else {
        // флаги возможности движения слона и ладьи
        bool elephantMove = false;
        bool rookMove = false;


        // проверяем врзможность движения ладьи
        if (firstX == secondX || firstY == secondY) {
            cout << "Rook can move" << endl;
            rookMove = true;
        }
        
        // определяем дистанцию перемещения фигуры
        int distanceX = abs((secondX - '`') - (firstX - '`'));
        int distanceY = abs((secondY - '0') - (firstY - '0'));

        // проверяем возможность движения слона
        if (distanceX == distanceY) {
            cout << "Elephant can move" << endl;
            elephantMove = true;
        }

        // проверяем возможность движение ферзя и короля
        if (rookMove || elephantMove) {
            cout << "Queen can move" << endl;

            // проверяем условие движения короля
            if (distanceX == 1 || distanceY == 1) {
                cout << "King can move" << endl;
            }
        }

        bool horseMove = false;

        // проверяем возможность движения коня
        if (distanceX == 2 && distanceY == 1 || distanceX == 1 && distanceY == 2) {
            cout << "Horse can move" << endl;
            horseMove = true;
        }

        // если ни одна фигура не может перемещаться
        if (!rookMove && !elephantMove && !horseMove) {
            cout << "No one can move" << endl;
        }
    }
}
