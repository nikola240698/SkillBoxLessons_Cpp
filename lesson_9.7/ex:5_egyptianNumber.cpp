#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <string>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    /*Принцип перевода цифр
     *1     - I
     *5     - V
     *10    - x
     *50    - L
     *100   - C
     *500   - D
     *1000  - M
    */

    string inputNum;
    string egyptNum;

    cout << "Program for converting Arabic numerals to Egyptian numerals" << endl;
    cout << endl;

    cout << "Input the arabic number: ";
    cin >> inputNum;

    if (inputNum.length() < 0 || inputNum.length() > 4) {
        cout << "Incorrect input data" << endl;
    } else {
        for (int i = 0; i < inputNum.length(); i++) {

            // проверяем вводимые значения
            if (inputNum[i] < '0' || inputNum[i] > '9') {
                cout << "Incorrect input data" << endl;
                exit(1);
            } else {

                // начинаем записывать тысячи (если имеются)
                if (inputNum.length() - i == 4) {
                    int numcheck = inputNum[i] - '0';
                    if (numcheck < 4) {
                        for (int j = 0; j < numcheck; j++) {
                            egyptNum += "M";
                        }
                    }

                // начинаем записывать сотни (если имеются)
                } else if (inputNum.length() - i == 3) {
                    int numcheck = inputNum[i] - '0';
                    if (numcheck < 4) {
                        for (int j = 0; j < numcheck; j++) {
                            egyptNum += "C";
                        }
                    } else if (numcheck == 4) {
                        egyptNum += "CD";
                    } else if (numcheck > 4 && numcheck < 9) {
                        egyptNum += "D";
                        for (int j = 5; j < numcheck; j++) {
                            egyptNum += "C";
                        }
                    } else {
                        egyptNum += "CM";
                    }
                  
                // начинаем записывать сотни (если имеются)
                } else if (inputNum.length() - i == 2) {
                    int numcheck = inputNum[i] - '0';
                    if (numcheck < 4) {
                        for (int j = 0; j < numcheck; j++) {
                            egyptNum += "X";
                        }
                    } else if (numcheck == 4) {
                        egyptNum += "XL";
                    } else if (numcheck > 4 && numcheck < 9) {
                        egyptNum += "L";
                        for (int j = 5; j < numcheck; j++) {
                            egyptNum += "X";
                        }
                    } else {
                        egyptNum += "XC";
                    }

                // начинаем записывать единицы
                } else {
                    int numcheck = inputNum[i] - '0';
                    if (numcheck < 4) {
                        for (int j = 0; j < numcheck; j++) {
                            egyptNum += "I";
                        }
                    } else if (numcheck == 4) {
                        egyptNum += "IV";
                    } else if (numcheck > 4 && numcheck < 9) {
                        egyptNum += "V";
                        for (int j = 5; j < numcheck; j++) {
                            egyptNum += "I";
                        }
                    } else {
                        egyptNum += "IX";
                    }
                }
            }
        }
    }

    cout << egyptNum << endl;
}
