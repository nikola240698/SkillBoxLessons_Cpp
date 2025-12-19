#include <iostream>

using namespace std;

int main() {

	int currentHour;
	bool rightHour = false;

	cout << "Программа-иммитатор часов с кукушкой" << endl << endl;;

	do {
		cout << "Скажите, который час?: ";
		cin >> currentHour;

		if (currentHour > 12 && currentHour < 25) currentHour -= 12;		//переводим 24-часовой формат в 12

		rightHour = currentHour >= 1 && currentHour <= 12;					//проверяем правильность введенного времени

		if (rightHour) break;											    //если введено вернео, то прерываем цикл

		cout << "Не верный формат часа!" << endl << endl;

	} while (!rightHour);													//повторяем пока не введут точное время

	cout << "Кукушка сообщает время:" << endl;

	do {
		cout << "Ку-Ку!" << endl;
		--currentHour;
	} while (currentHour > 0);

}
