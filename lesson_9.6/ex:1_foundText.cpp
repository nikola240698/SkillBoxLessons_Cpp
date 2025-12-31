#include <iostream>
#include <windows.h>        // для корректной работы консоли в CLion
#include <string>

using namespace std;

int main () {

    // для корректной работы консоли в CLion
    SetConsoleOutputCP(CP_UTF8);

    string text;
    string word;

    // вводим данные
    cout << "Input the text: ";
    getline(cin, text);
    cout << "Input the word: ";
    cin >> word;

    int countMatches = 0;

    // перебираем текст посимвольно
    for (int startPos = 0; startPos < text.length(); startPos++) {

        // флаг нахождения совпадения слова
        bool match = true;

        // проверяем совпадение слова в тексте
        for (int i = 0; i < word.length(); i++) {

            // проверяем, что совпадений нет
            if (i + startPos >= text.length() || word[i] != text[i + startPos]) {
                match = false;
                break;
            }
        }

        // при условии нахождения совпадения
        if (match) {
            countMatches++;
        }
    }

    // выводим результат
    if (countMatches) {
        cout << "Found " << countMatches << " matches" << endl;
    } else {
        cout << "Don't found it" << endl;
    }
}
