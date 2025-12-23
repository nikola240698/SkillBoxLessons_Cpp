#include <iostream>

using namespace std;

int main () {

    int chatly, gravytsap;
    float kTs;

    cout << "---- Программа-конвертер валют ----" << endl;
    cout << "Введите количество Ваших чатлов: ";
    cin >> chatly;

    kTs = (float) chatly / 4400;

    gravytsap = kTs / 0.5f;

    cout << "Ваши " << chatly << " чатлов равны " << kTs << " КЦ" << endl;
    cout << "На " << chatly << " чатлов можно проиборести " << gravytsap << " гравицап" << endl;

}


