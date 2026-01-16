#include <iostream>
#include <limits>
#include <cmath>

// функция контроля вводимых данных
void inputNum(int arr[], const int &lBor, const int &rBor) {
    while(true)
    {
        std::cin >> arr[0] >> arr[1];
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Incorrect data. Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (arr[0] < lBor || arr[0] > rBor || arr[1] < lBor || arr[1] > rBor) {
            std::cout << "Incorrect range. Try again" << std::endl;
        } else {
            break;
        }
    }
}

// функция отображения полей игроков
void showArr(char arr_1[][10], char arr_2[][10]) {
    std::cout << "\tPlayer_1\t\t\tPlayer_2" << std::endl;
    std::cout << "======================\t\t======================" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "|";
        for (int j = 0; j < 24; j++) {
            if (j < 10) {
                std::cout << arr_1[i][j] << " ";
            } else if (j == 10 || j == 13) {
                std::cout << "|";
            }  else if (j > 10 && j < 13) {
                std::cout << "\t";
            } else {
                std::cout << arr_2[i][j - 14] << " ";
            }
        }
        std::cout << "|";
        std::cout << std::endl;
    }
    std::cout << "======================\t\t======================" << std::endl;
}

// функция автономного заполнения двухмерного массива заданным значением
void createField(auto arr[][10], auto value) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = value;
        }
    }
}

// функция размещения одиночного корабля с проверкой на занятое место
bool placeShip(bool field[][10],int x, int y) {
    if (!field[x][y]) {
        field[x][y] = true;
        return true;
    }
    std::cout << "Place is taken!" << std::endl;
    return false;
}

// функция размещения кораблей размером более единицы
void placeBigShip(bool field[][10], char map[][10],const int &size) {

    int count = 0;
    int shipAmount = (size == 2 ? 3 : (size == 3 ? 2 : 1));
    int coordX[2], coordY[2];

    while (count < shipAmount) {
        std::cout << "Input coordinates " << (count + 1) << " ship:" << std::endl;
        std::cout << "Start point: ";
        inputNum(coordX, 0, 9);
        std::cout << "End point: ";
        inputNum(coordY, 0, 9);

        // если ввели корабль вертикально
        if (coordX[0] == coordY[0] && abs(coordX[1] - coordY[1]) == (size - 1)) {
            // в случае вода координат корабля наоборот
            coordX[1] = (coordY[1] > coordX[1]) ? coordX[1] : coordY[1];

            // проверяем, что вводимые поля свободны
            bool free = true;
            for (int i = 0; i < size; i++) {
                if (field[coordX[0]][coordX[1] + i])
                    free = false;
            }
            if (!free) {
                std::cout << "The place is taken" << std::endl;
                continue;
            }
            // расставляем корабли
            for (int i = 0; i < size; i++) {
                placeShip(field, coordX[0], coordX[1] + i);
                map[coordX[0]][coordX[1] + i] = (char) (48 + size);
            }

        // если корабль ввели горизонтально
        } else if (coordX[1] == coordY[1] && abs(coordX[0] - coordY[0]) == (size - 1)) {
            // в случае вода координат корабля наоборот
            coordX[0] = (coordY[0] > coordX[0]) ? coordX[0] : coordY[0];
            // проверяем, что вводимые поля свободны
            bool free = true;
            for (int i = 0; i < size; i++) {
                if (field[coordX[0] + i][coordX[1]])
                    free = false;
            }
            if (!free) {
                std::cout << "The place is taken" << std::endl;
                continue;
            }
            // расставляем корабли
            for (int i = 0; i < size; i++) {
                placeShip(field, coordX[0] + i, coordX[1]);
                map[coordX[0] + i][coordX[1]] = (char) (48 + size);
            }

        } else {
            std::cout << "Incorrect ship coordinates" << std::endl;
            continue;
        }
        count++;
    }
}

void shipArrangement(bool field[][10], char map[][10]) {

    int shipCo = 0;     // счетчик кораблей
    // размещаем одинарный корабль
    int coordX[2];      // координаты корабля

    while (shipCo < 4) {
        std::cout << "Input coordinates " << (shipCo + 1) << " single ship:";
        inputNum(coordX, 0, 9);
        if (placeShip(field, coordX[0], coordX[1])) {
            map[coordX[0]][coordX[1]] = (char) (48 + 1);
            shipCo++;
        }
    }

    // размещаем двойной корабль
    std::cout << "Input coordinates double ship:" << std::endl;
    placeBigShip(field, map, 2);

    // размещаем тройной корабль
    std::cout << "Input coordinates triple ship:" << std::endl;
    placeBigShip(field, map, 3);

    // размещаем четверной корабль
    std::cout << "Input coordinates quadruple ship:" << std::endl;
    placeBigShip(field, map, 4);
}

bool shot(bool field[][10], char map[][10], const int target[2], int &life) {

    // если уже стреляли в эту точку
    if (map[target[0]][target[1]] == 'x' || map[target[0]][target[1]] == '0') {
        std::cout << "You already shoot here. Try again." << std::endl;
        return true;
    }
    // если попали в корабль даем еще ход
    if (field[target[0]][target[1]]) {
        std::cout << "The ship is wounded! You have one more try." << std::endl;
        field[target[0]][target[1]] = false;
        map[target[0]][target[1]] = '0';
        life--;
        return true;
    }
    // если промахнулись
    std::cout << "You missed..." << std::endl;
    map[target[0]][target[1]] = 'x';
    return false;
}

int main() {

    std::cout << "======== Playing sea battle! ======== " << std::endl;
    std::cout << "Try yourself in the role of captain of a naval armada" << std::endl;
    std::cout << "P.S. All coordinates are entered separated by spaces," << std::endl;
    std::cout << "in the range from 0 to 9, for example: 2 5" << std::endl;
    std::cout << "Let's get started!" << std::endl;
    std::cout << std::endl;

    // массивы полей размещения корабля
    bool field_1[10][10];
    bool field_2[10][10];
    // массив отображения карт игры
    char shipMap_1[10][10];
    char shipMap_2[10][10];

    // создаем поля и карты заполняя по дефолту
    createField(field_1, false);
    createField(field_2, false);
    createField(shipMap_1, '-');
    createField(shipMap_2, '-');

    // расставляем корабли
    // первый игрок
    std::cout << "Player 1. Input the coordinates of your ships " << std::endl;
    shipArrangement(field_1, shipMap_1);
    // второй игрок
    std::cout << "Player 2. Input the coordinates of your ships" << std::endl;
    shipArrangement(field_2, shipMap_2);

    // начинаем бой
    // счетчик жизни кораблей
    int shipLife_1 = 20;
    int shipLife_2 = 20;
    // координаты удара
    int target[2];
    // ход игрока
    bool player1 = true;

    std::cout << "Let's start the battle!" <<std::endl;
    while (true) {
        if (shipLife_1 == 0 || shipLife_2 == 0) {
            break;
        }
        // отображаем карту
        showArr(shipMap_1, shipMap_2);

        std::cout << "Player " << (player1 ? 1 : 2) << ", input the shot coordinates:";
        inputNum(target, 0, 9);

        // ход первого игрока
        if (player1) {
            if (shot(field_2, shipMap_2, target, shipLife_2)) {
                continue;
            }
            // меняем ход игрока
            player1 = false;
        // ход второго игрока
        } else {
            if (shot(field_1, shipMap_1, target, shipLife_1)) {
                continue;
            }
            // меняем ход игрока
            player1 = true;
        }
    }

    std::cout << "Player " << (player1 ? 1 : 2) << " win!" << std::endl;

    return 0;
}
