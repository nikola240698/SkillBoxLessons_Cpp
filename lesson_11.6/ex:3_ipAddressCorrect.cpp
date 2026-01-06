#include <iostream>
#include <string>

using namespace std;

string get_address_part(string address, int octaNum) {
    int pointCount = 0;
    string result = "";
    // ищем определенные окту по счетчику точек
    for (int i = 0; i < address.length(); i++) {
        if (address[i] == '.') {
            if (pointCount == octaNum) {
                break;
            } else {
                result = "";
                pointCount++;
                continue;
            }
        }
        result += address[i];
    }
    return result;
}

bool is_correct_octa(string address) {
    // проверяем длину окты и наличие ведущих нулей
    if (address.length() == 0 || address.length() > 1 && address[0] == '0') {
        return false;
    }
    int octaNum = 0;
    // переводим строку окты в число
    for (int i = 0; i < address.length(); i++) {
        if (address[i] < '0' || address[i] > '9') {
            return false;
        } else {
            if (octaNum) {
                octaNum *= 10;
                octaNum += address[i] - '0';
            } else {
                octaNum += address[i] - '0';
            }
        }
    }
    // проверяем значение числа
    if (octaNum < 0 || octaNum > 255) {
        return false;
    } else {
        return true;
    }
}

bool check_ip_address (string address) {
    int pointCount = 0;
    // проверяем количество точек
    for (int j = 0; j < address.length(); j++) {
        if (address[j] == '.') {
            pointCount++;
        }
    }
    if (pointCount != 3) {
        return false;
    }
    // проверяем каждую окту на корректность
    for (int i = 0; i < 4; i++) {
        if (!is_correct_octa(get_address_part(address, i))) {
            return false;
        }
    }
    return true;
}

int main () {

    string ipAddress;

    cout << "Program for checking correctness IP address" << endl;
    cout << endl;

    cout << "Input your IP address: ";
    getline(cin, ipAddress);

    cout << (check_ip_address(ipAddress) ? "Valid" : "Invalid") << endl;

    return 0;
}
