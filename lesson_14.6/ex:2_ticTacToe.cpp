#include <iostream>

void showBoard(char arr[][3]) {
    for (int k = 0; k < 13; k++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << arr[i][j] << " | ";
        }
        std::cout << std::endl;
        for (int k = 0; k < 13; k++) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}

bool checkVictory(char arr[][3]) {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr [i][0] == arr [i][2]) {
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (arr[0][j] != ' ' && arr[0][j] == arr[1][j] && arr[0][j] == arr[2][j]) {
            return true;
        }
    }
    // костыльная проверка диагонали
    if (arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) {
        return true;
    }
    if (arr[0][2] != ' ' && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) {
        return true;
    }
    return false;
}

int main() {

    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
    int move = 3 * 3;
    int x, y;
    char player = 'X';
    bool freeMove[3][3] = {{true, true, true},
                           {true, true, true},
                           {true, true, true}};
    bool victory = false;

    std::cout << "Let's play in \"Tic-Tac-Toe\"!" << std::endl;
    showBoard(board);

    while (move > 0) {
        std::cout << "Your move - " << player << std::endl;
        std::cin >> x >> y;
        if (x < 0 || x > 2 || y < 0 || y > 2) {
            std::cout << "Incorrect position!" << std::endl;
            continue;
        }
        if (freeMove[x][y]) {
            freeMove[x][y] = false;
            board[x][y] = player;
            showBoard(board);
            if (move < 6 && checkVictory(board)) {
                victory = true;
                break;
            }
        } else {
            std::cout << "The place is taken!" << std::endl;
            continue;
        }
        if (player == 'X') player = 'O';
        else player = 'X';

        move--;
    }

    if (victory) {
        std::cout << "Congratulation! The " << player << " win!" << std::endl;
    } else {
        std::cout << "Oops, it was a draw" << std::endl;
    }

    return 0;
}
