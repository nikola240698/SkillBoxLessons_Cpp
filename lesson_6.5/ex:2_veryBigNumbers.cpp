#include <iostream>

using namespace std;

int main() {

	int numberCheck;
	int count = 0;

	cout << "------ Программа-счетчик цифр введенного числа ------" << endl << endl;
	cout << "Введите проверяемое число: ";
	cin >> numberCheck;

	do {
		numberCheck /= 10;
		++count;
	} while (numberCheck != 0);

	cout << "Цифр в числе: " << count;

