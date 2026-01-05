#include <iostream>
#include <string>

using namespace std;

// проверяем, что у нас один знак @
bool is_atSign(string eMail) {
    bool atSign = false;
    for (int i = 0; i < eMail.length(); i++) {
        if (atSign && eMail[i] == '@') {
            return false;
        } else if (eMail[i] == '@') {
            atSign = true;
        }
    }
    return atSign;
}

// определяем первую часть
string firstPart(string eMail) {
    string result = "";
    for (int i = 0; i < eMail.length(); i++) {
        if (eMail[i] != '@') {
            result += eMail[i];
        } else {
            break;
        }
    }
    return result;
}

// определяем вторую часть
string secondPart(string eMail) {
    string result = "";
    bool atSign = false;
    for (int i = 0; i < eMail.length(); i++) {
        if (atSign) {
            result += eMail[i];
        }
        if (eMail[i] == '@') {
            atSign = true;
        }
    }
    return result;
}

// проверка на правило точек и словаря
bool is_correct(string text, string dictonary, int length) {
    // проверяем длину и точку в начале или конце
    if (text.length() > length || text.length() < 1 || text[0] == '.' || text[text.length()- 1] == '.') {
        return false;
    }
    // читаем строку проверяя на наличие двух точек и совпадению со словарем
    for (int i = 0; i < text.length(); i++) {
        if (i != 1 && text[i] == '.' && text[i + 1] == '.') {
            return false;
        }
        for (int j = 0; j < dictonary.length(); j++) {
            if (text[i] == dictonary[j]) {
                break;
            }
            if (j == dictonary.length() - 1) {
                return false;
            }
        }
    }
    return true;
}

bool is_nickname(string text) {
    text = firstPart(text);
    string dictonary = ".ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&'*+-/=?^_`{|}~";
    return is_correct(text, dictonary, 64);
}

bool is_domain(string text) {
    text = secondPart(text);
    string dictonary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-.";
    return is_correct(text, dictonary, 63);
}

int main () {

    string text;

    cout << "Program for check correctness of e-mail recording" << endl;
    cout << endl;

    cout << "Input your e-mail: ";
    getline(cin, text);

    // надеюсь такое длинное применение тернарного оператора позволимо
    cout << (is_atSign(text) ? (is_nickname(text) ? (is_domain(text) ? "Yes" : "No") : "No") : "No") << endl;

    return 0;
}
