#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    char first, second;

    cout << "Program for determining largest card" << endl << endl;
    cout << "Input your two card: ";
    cin >> first >> second;

    int firstInt;
    int secondInt;

    if (first >= '1' && first <= '9') {
        firstInt = first - '0';
    } else if (first == '0') {
        firstInt = 10;
    } else if (first == 'J') {
        firstInt = 11;
    } else if (first == 'Q') {
        firstInt = 12;
    } else if (first == 'K') {
        firstInt = 13;
    } else if (first == 'A') {
        firstInt = 14;
    } else {
        cout << "Incorrect data" << endl;
        exit(1);
    }

    if (second >= '1' && second <= '9') {
        secondInt = second - '0';
    } else if (second == '0') {
        secondInt = 10;
    } else if (second == 'J') {
        secondInt = 11;
    } else if (second == 'Q') {
        secondInt = 12;
    } else if (second == 'K') {
        secondInt = 13;
    } else if (second == 'A') {
        secondInt = 14;
    } else {
        cout << "Incorrect data" << endl;
        exit(1);
    }

    if (firstInt == secondInt) {
        cout << "The cards are equal" << endl;
    } else if (firstInt > secondInt || (firstInt == 6 && secondInt == 14)) {
        cout << "The First is bigger" << endl;
    } else {
        cout << "The Second is bigger" << endl;
    }

}
