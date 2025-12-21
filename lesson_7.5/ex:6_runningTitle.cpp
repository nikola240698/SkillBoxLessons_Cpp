#include <iostream>

using namespace std;

int main() {

	int exclamationAmount;
	int symbolAmount;

	cout << "Программа для отображения заголовка колонтитула" << endl << endl;
	cout << "Введите общую длину колонтитула: ";
	cin >> symbolAmount;
	cout << "Введите количество восклицательных знаков: ";
	cin >> exclamationAmount;

	// проверяем, что введенные данные корректны
	if (symbolAmount <= 0 || exclamationAmount <= 0) cout << "Значения не могут быть отрицательными или равны 0";
	else if (exclamationAmount > symbolAmount) cout << "Количество восклицательных занков превышает общую длину";
	else {

		//опеределим положение начала отображения "!"
		int exclamationStart = symbolAmount / 2 - exclamationAmount / 2;

		// отображаем
		for(int i = 1; i <= symbolAmount; i++) {
			if (i > exclamationStart && i <= exclamationStart + exclamationAmount) cout << "!";
			else cout << "~";
		}

	}

}

