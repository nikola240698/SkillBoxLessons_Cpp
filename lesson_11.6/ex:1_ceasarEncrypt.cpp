#include <iostream>
#include <string>

using namespace std;

bool is_letter(char c) {
    return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

bool is_upper (char c) {
    return (is_letter(c) && c >= 'A' && c <= 'Z');
}

string encrypt_ceasar(string text, int shift) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {

        if (is_letter(text[i])) {
            int letterPos = is_upper(text[i]) ? text[i] - 'A' : text[i] - 'a';
            int letterCrypt = (letterPos + shift) % 26;
            result += (is_upper(text[i])) ? (char) (letterCrypt + 'A'): (char) (letterCrypt + 'a');
        } else {
            result += text[i];
        }
    }
    return result;
}

int main () {

    string text;
    int shiftCode;

    cout << "Program for demonctration \"Ceasar Cipher\"" << endl;
    cout << endl;
    cout << "Input the text: ";
    getline(cin, text);
    cout << "Input the shift code: ";
    cin >> shiftCode;

    cout << "Encrypted text:" << endl;
    cout << encrypt_ceasar(text, shiftCode);

    return 0;
}
