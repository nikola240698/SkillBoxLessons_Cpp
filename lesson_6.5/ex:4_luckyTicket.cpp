#include <iostream>

using namespace std;

int main() {

	int ticketNumberLength = 6; 		//выбранная длина номера билета
	int ticketNumber;
	int numberCount = 0;
	int firstHalfValue = 0, secondHalfValue = 0;

	cout << "------ Программа для проверки счастливого билета -------" << endl;
	cout << "Номер билета должен состоять из " << ticketNumberLength << " цифр" << endl;
	cout << "Введите номер билета: ";
	cin >> ticketNumber;

	//проверяем длину введенного номера билета
	int ticketNumberCheck = ticketNumber;
	int countCheck = 0;
	while (ticketNumberCheck > 0) {
		ticketNumberCheck /= 10;
		++countCheck;
	}

	//проверим правильность длины введенного номера
	if (countCheck == ticketNumberLength) {

		//считаем сумму первой половины числа
		while (numberCount < (ticketNumberLength / 2)) {
			firstHalfValue += ticketNumber % 10;
			++numberCount;
			ticketNumber /= 10;
		}

		//считаем сумму ворой половины числа
		while (numberCount < ticketNumberLength) {
			secondHalfValue += ticketNumber % 10;
			++numberCount;
			ticketNumber /= 10;
		}

		if (firstHalfValue == secondHalfValue) cout << "Билет счастливый!";
		else cout << "Билет не счасливый!";
	} else cout << "Введен неверный формат номера билета";

}
