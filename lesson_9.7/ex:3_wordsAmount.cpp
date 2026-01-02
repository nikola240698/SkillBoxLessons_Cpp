#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <string>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    string text;
    int wordCounter = 0;

    cout << "Program for calculating amount of word in the text" << endl;
    cout << endl;
    cout << "Input the text: ";
    getline(cin, text);

    // проверяем что текст начинается со слова
    if (text[0] != ' ') {
        wordCounter++;
    }
    
    // читаем строку
    for (int i = 0; i < text.length() - 1; i++) {
        // при каждом новом слове после пробела увеличиваем счетчик
        if (text[i] == ' ' && text[i + 1] != ' ') {
            wordCounter++;
        }
    }

    // выводим результат
    cout << wordCounter << endl;

}
