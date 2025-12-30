#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <cmath>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    char a, b, c;

    cout << "Program for multiplying numbers" << endl << endl;
    cout << "Input a multiplication example: " << endl;
    cin >> a >> b >> c;

    if (a < '0' || a > '9' || c < '0' || c > '9' || b != '*') {
        cout << "Incoterrect data" << endl;
    } else {
        cout << "Result = " << (a - '0') * (c - '0') << endl;
    }

}
