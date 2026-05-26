#include <iostream>
#include <string>
#include <ctime>
#include <limits>
#include <fstream>

// поток для записи лог-файла (сделал для себя, контролировать параметры
std::ofstream logStream ("log.txt");

// счетчик ходов
int step = 0;

// структура координат положения
struct Position {
    int x;
    int y;
};

// структура персонажа
struct Character {
    std::string name;
    int health;
    int armor;
    int damage;
    bool isAlive = false;
    Position position;
};

// вывод подсказки на экран
void showHelp() {
    std::cout << "Input the following commands to play the game:" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "HELP \t- show a list of available commands" << std::endl;
    std::cout << "SAVE \t- save the game" << std::endl;
    std::cout << "LOAD \t- load the game" << std::endl;
    std::cout << "L \t- move your hero LEFT one cell" << std::endl;
    std::cout << "R \t- move your hero RIGHT one cell" << std::endl;
    std::cout << "U \t- move your hero UP one cell" << std::endl;
    std::cout << "D \t- move your hero DOWN one cell" << std::endl;
    std::cout << "QUIT\t- exit the game" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}


// создаем врагов
void createEnemy(Character enemy[], char field[][20]) {
    for (int i = 1; i <= 5; i++) {
        enemy[i].name = "Enemy #" + std::to_string(i);
        enemy[i].health = 50 + std::rand() % 100;
        enemy[i].armor = std::rand() % 50;
        enemy[i].damage = 15 + std::rand() % 15;
        // рандомное расположение с контролем свободной позиции
        while (true) {
            enemy[i].position.x = std::rand() % 20;
            enemy[i].position.y = std::rand() % 20;
            if (field[enemy[i].position.y][enemy[i].position.x] == '.') {
                field[enemy[i].position.y][enemy[i].position.x] = 'E';
                break;
            }
        }
        // присваиваем статус "живца"
        enemy[i].isAlive = true;
        //--------------------------------Запись в лог--------------------------------
        logStream << enemy[i].name << "| Health = " << enemy[i].health << " | Armor = "
            << enemy[i].armor << " | Damage = " << enemy[i].damage << std::endl;
        //--------------------------------Запись в лог--------------------------------
    }
}

// вывод на экран поля
void showField(char filed[][20], Character players[]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout << filed[i][j] << " ";
        }
        // данные игрока
        if (i == 2) {
            std::cout << "\tPlayer: \t" << players[0].name;
        }
        if (i == 4) {
            std::cout << "\tHealth: \t" << players[0].health;
        }
        if (i == 5) {
            std::cout << "\tArmor:  \t" << players[0].armor;
        }
        // данные хода
        if (i == 7) {
            std::cout << "\tStep:  \t" << step;
        }

        std::cout << std::endl;
    }
}

// функция ввода и проверки целых чисел
int inputInt() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Incorrect data! Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "-> ";
            continue;
                }
        return value;
    }
}

// создание героя
void createHero(Character hero[], char field[][20]) {
    // вводим имя героя
    std::string name;
    std::cout << "Input the Name of your Hero -> ";
    std::cin >> name;
    hero[0].name = name;

    // вводим остальные данные
    std::cout << "Input the Health of the " << hero[0].name << " (recommended 50-150)-> ";
    hero[0].health = inputInt();
    std::cout << "Input the Armor of the " << hero[0].name << " (recommended 0-50)-> ";
    hero[0].armor = inputInt();
    std::cout << "Input the Damage of the " << hero[0].name << " (recommended 15-30)-> ";
    hero[0].damage = inputInt();
    // рандомно располагаем героя
    while (true) {
        hero[0].position.x = std::rand() % 20;
        hero[0].position.y = std::rand() % 20;
        if (field[hero[0].position.y][hero[0].position.x] == '.') {
            field[hero[0].position.y][hero[0].position.x] = 'P';
            break;
        }
    }
    // "оживляем" героя
    hero[0].isAlive = true;
}

//функция нанесения урона
void takeDamage(Character player[], const int &ind, const int &posX, const int &posY) {
    // если атакующий - противник
    if (ind) {
        std::cout << player[0].name << " took damage " << player[ind].damage << std::endl;
        player[0].armor -= player[ind].damage;
        if (player[0].armor < 0)
        {
            player[0].health += player[0].armor;
            player[0].armor = 0;
        }

        //--------------------------------Запись в лог--------------------------------
        logStream << player[0].name << " took damage " << player[ind].damage << " from "
            << player[ind].name << " (Remaind: Health = " << player[0].health << " | Armor = "
            << player[0].armor << ")" << std::endl;
        //--------------------------------Запись в лог--------------------------------

        // проверяем, что ещё жив
        if (player[0].health <= 0) {
            player[0].isAlive = false;
        }

    // если атакующий - игрок
    } else {
        // определяем индекс врага
        int enInd = 1;
        for (; enInd < 6; enInd++) {
            if (player[enInd].position.x == posX && player[enInd].position.y == posY) {
                break;
            }
        }
        // наносим урон выбранному врагу
        std::cout << player[enInd].name << " took damage " << player[0].damage << std::endl;
        player[enInd].armor -= player[0].damage;
        if (player[enInd].armor < 0)
        {
            player[enInd].health += player[enInd].armor;
            player[enInd].armor = 0;
        }

        //--------------------------------Запись в лог--------------------------------
        logStream << player[enInd].name << " took damage " << player[0].damage << " from "
            << player[0].name << " (Remaind: Health = " << player[enInd].health << " | Armor = "
            << player[enInd].armor << ")" << std::endl;
        //--------------------------------Запись в лог--------------------------------


        // проверяем, что ещё жив
        if (player[enInd].health <= 0) {
            player[enInd].isAlive = false;
            // Заносим в лог "извещение о гибели"
            logStream << player[enInd].name << " killed" << std::endl;
        }

    }
}

// функция отображения текущего положения героев на карте
void fieldFill(Character player[], char field[][20]) {
    // заполняем точками всё поле
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            field[i][j] = '.';
        }
    }
    // заполняем именами героев поля
    for (int i = 0; i < 6; i++) {
        if (player[i].isAlive) {
            const char name = i ? 'E' : 'P';
            field[player[i].position.y][player[i].position.x] = name;
        }
    }
}

// движение персонажа с контролем границ и других игроков
void moveSelect(Character player[], char field[][20], const int &mov, const int &ind) {

    // определяем инициал игрока и противника
    char name, enemy;
    if (ind == 0) {
        name = 'P';
        enemy = 'E';
    }  else {
        name = 'E';
        enemy = 'P';
    }

    // переменные содержащие координаты игрока
    int posX = player[ind].position.x;
    int posY = player[ind].position.y;

    // двигаемся согласно выбранному движению
    switch (mov) {
        // условие "L"
        case 0: {
            // проверяем что не на границе и нет союзника на пути
            if (posX == 0 || field[posY][posX - 1] == name) {
                break;
            }
            // проверяем, что есть соперник на пути
            if (field[posY][posX - 1] == enemy) {
                takeDamage(player, ind, posX - 1, posY);
                break;
            }
            // перемещаем персонажа
            player[ind].position.x -= 1;
            break;
        }
        // условие "R"
        case 1: {
            if (posX == 19 || field[posY][posX + 1] == name) {
                break;
            }
            // проверяем, что есть соперник на пути
            if (field[posY][posX + 1] == enemy) {
                takeDamage(player, ind, posX + 1, posY);
                break;
            }
            // перемещаем персонажа
            player[ind].position.x += 1;
            break;
        }
        // условие "U"
        case 2: {
            if (posY == 0 || field[posY - 1][posX] == name) {
                break;
            }
            // проверяем, что есть соперник на пути
            if (field[posY - 1][posX] == enemy) {
                takeDamage(player, ind, posX, posY - 1);
                break;
            }
            // перемещаем персонажа
            player[ind].position.y -= 1;
            break;
        }
        // условие "D"
        case 3: {
            if (posY == 19 || field[posY + 1][posX] == name) {
                break;
            }
            // проверяем, что есть соперник на пути
            if (field[posY + 1][posX] == enemy) {
                takeDamage(player, ind, posX, posY + 1);
                break;
            }
            // перемещаем персонажа
            player[ind].position.y += 1;
            break;
        }
    }
    // переписываем на поле положение персонажа
    fieldFill(player, field);

    //--------------------------------Запись в лог--------------------------------
    logStream << player[ind].name << " moved from (" << posX << ";" << posY << ")"
        << " to (" << player[ind].position.x << ";" << player[ind].position.y
        << ")" << std::endl;
    //--------------------------------Запись в лог--------------------------------

}

// движение противника
void enemyMove(Character enemy[], char field[][20]) {
    for (int i = 1; i < 6; i++) {
        // проверяем, что противник всё еще жив
        if (enemy[i].isAlive) {
            // выбираем произвольное направление
            int mov = std::rand() % 4;
            moveSelect(enemy, field, mov, i);
        }
    }
}

// функция проверки вводимого значения движения героя
std::string inputTurn() {
    std::string mov;
    while (true) {
        std::cin >> mov;
        if (std::cin.fail() || std::cin.peek() != '\n'
                || (mov != "L" && mov != "R" && mov != "U" && mov != "D"
                && mov != "LOAD" && mov != "SAVE" && mov != "HELP" && mov != "help"
                && mov != "QUIT")) {
            std::cout << "Incorrect data! Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "-> ";
            continue;
            }
        return mov;
    }
}

bool checkGame(Character player[]) {
    // проверяем, что герой жив
    if (!player[0].isAlive) {
        std::cout << "Oops, you lost... Game over" << std::endl;
        std::cout << "Don't worry, you can always start over!" << std::endl;
        return false;
    }

    // проверяем всех врагов
    for (int i = 1; i < 6; i++) {
        // если хоть один враг жив, то получим true
        if (player[i].isAlive) {
            return true;
        }
    }
    // если нет живых врагов
    std::cout << "Congratulation! You Win this game!" << std::endl;
    std::cout << "Excellent result, you did a great job!" << std::endl;
    return false;
}

// запись игры
void saveGame(Character player[]) {
    // создаем поток на запись бинарный
    std::ofstream file("save.bin", std::ios::binary);

    // записываем параметры персонажей
    for (int i = 0; i < 6; i++) {
        int len = player[i].name.length();
        file.write((char*) &len, sizeof(len));
        file.write(player[i].name.c_str(), len);
        file.write((char*) &player[i].health, sizeof(player[i].health));
        file.write((char*) &player[i].armor, sizeof(player[i].armor));
        file.write((char*) &player[i].damage, sizeof(player[i].damage));
        file.write((char*) &player[i].position.x, sizeof(player[i].position.x));
        file.write((char*) &player[i].position.y, sizeof(player[i].position.y));
        file.write((char*) &player[i].isAlive, sizeof(player[i].isAlive));
    }
    // записываем текущий номер хода
    file.write((char*) &step, sizeof(step));

    file.close();
}

// загрузка игры
bool loadGame(Character player[], char field[][20]) {
    // создаем поток на чтение
    std::ifstream file("save.bin", std::ios::binary);
    if (file.is_open()) {
        // для указания длины строки
        int len;
        for (int i = 0; i < 6; i++) {
            file.read((char*)&len, sizeof(len));
            // увеличиваем размер длины строки на прочитанную длину
            player[i].name.resize(len);
            file.read((char*)player[i].name.c_str(), len);
            file.read((char*)&player[i].health, sizeof(player[i].health));
            file.read((char*)&player[i].armor, sizeof(player[i].armor));
            file.read((char*) &player[i].damage, sizeof(player[i].damage));
            file.read((char*) &player[i].position.x, sizeof(player[i].position.x));
            file.read((char*) &player[i].position.y, sizeof(player[i].position.y));
            file.read((char*) &player[i].isAlive, sizeof(player[i].isAlive));
        }
        // читаем номер хода в фале сохранения
        file.read((char*) &step, sizeof(step));

        // заполнение поля и выводим
        fieldFill(player, field);
        showField(field, player);

        // закрываем файл с меткой о результате
        file.close();
        return true;
    }
    return false;
}

// движение героя
void playerMove(Character player[], char field[][20]) {
    while (true) {
        std::cout << "Input your turn -> ";
        std::string mov = inputTurn();

        // действия после ввода
        if (mov == "HELP" || mov == "help") {
            showHelp();
        } else if (mov == "LOAD") {
            if (loadGame(player, field)) {
                std::cout << "The game loaded successfully" << std::endl << std::endl;
            } else {
                std::cout << "The save file is not in the system" << std::endl << std::endl;
            }
        } else if (mov == "SAVE") {
            saveGame(player);
            std::cout << "The game is saved" << std::endl;
        } else if (mov == "L") {
            moveSelect(player, field, 0, 0);
            break;
        } else if (mov == "R") {
            moveSelect(player, field, 1, 0);
            break;
        } else if (mov == "U") {
            moveSelect(player, field, 2, 0);
            break;
        } else if (mov == "D") {
            moveSelect(player, field, 3, 0);
            break;
        } else if (mov == "QUIT") {
            exit(0);
        }
    }

}

// функция хода
void makeMove(Character players[], char field[][20]) {

    //--------------------------------Запись в лог--------------------------------
    logStream << "Step " << step++ << std::endl;
    //--------------------------------Запись в лог--------------------------------

    // ход игрока
    playerMove(players, field);
    // ход врагов
    enemyMove(players, field);
    // отображаем поле
    showField(field, players);
}

// функция главного меню при запуске игры
void mainMenu(Character players[], char field[][20]) {
    while (true) {
        std::cout << "----- MAIN MENU -----" << std::endl;
        std::cout << "Select an action:" << std::endl;
        std::cout << "1\t- NEW game" << std::endl;
        std::cout << "2\t- LOAD game" << std::endl;
        std::cout << "3\t- get a hint" << std::endl;
        std::cout << "-> ";
        // переменная для определния выбора игрока
        int choice = inputInt();
        // пункт начала новой игры
        if (choice == 1) {
            // заполняем поле точками
            fieldFill(players, field);
            // создаем противников
            createEnemy(players, field);
            // создаем персонажа
            createHero(players, field);
            // отображаем поле
            showField(field, players);
            break;
        // пункт выбора загрузки игры
        } else if (choice == 2) {
            if (loadGame(players, field)) {
                std::cout << "The save loaded successful!" << std::endl;
                break;
            }
            std::cout << "File save not found" << std::endl;
        // пункт выбора вызова помощи
        } else if (choice == 3) {
            showHelp();
        } else {
            std::cout << "Incorrect data" <<std::endl;
        }
    }
}

int main() {

    // для работы рандома
    std::srand(std::time(nullptr));

    // создаем массив игроков
    Character players[6];

    // создаем игровое поле
    char field[20][20];

    std::cout << "This is a Turn-based role-playing game!" << std::endl << std::endl;
    std::cout << "You play as a warrior on a 20x20 field" << std::endl;
    std::cout << "Your task is to defeat all enemies on the field" << std::endl;
    std::cout << "and stay alive! Of course." << std::endl << std::endl;

    // запуск главного меню
    mainMenu(players, field);

    // основной цикл игры
    do {
        makeMove(players, field);
    } while (checkGame(players));

    // закрываем файл лога
    logStream.close();

    return 0;
}
