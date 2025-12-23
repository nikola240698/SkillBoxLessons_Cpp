#include <iostream>

using namespace std;

int main () {
  
    float posX, posY;

    cout << "Программа для определения положения шахматной фигуры" << endl;
    cout << "Вы имеете доску размером 0.8х0.8м, с размером квадрата 10х10см" << endl;

    while (true) {
        cout << "Введите координаты положения вашей фигуры (м): ";
        cin >> posX >> posY;

        if (posX < 0 || posX > 0.8f || posY < 0 || posY > 0.8f) {
            cout << "Ошибка ввода данных" << endl;
        } else {
            posX *= 10;
            posY *= 10;

            cout << "Ваша фигура находится на клетке (" << (int) posX << ", "
                    << (int) posY << ")" << endl;
        }
    }
}
