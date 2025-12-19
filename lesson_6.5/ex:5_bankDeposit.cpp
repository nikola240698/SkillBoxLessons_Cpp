#include <iostream>

using namespace std;

int main() {

	int bankDeposit;					//начальный вклад
	int interestRate;					//процентная ставка
	int bankDepositExpected;			//ожидаемый рещультат
	int yearWaiting = 0;				//прогноз ожидания

	string yearDeclension;			

	cout << "---- Программа для расчета ожидания вклада в банке ----" << endl;
	cout << "Введите размер вклада: ";
	cin >> bankDeposit;
	cout << "Введите процентную ставку: ";
	cin >> interestRate;
	cout << "Введите желаемую сумму: ";
	cin >> bankDepositExpected;

	if (bankDeposit <= 0 || interestRate <= 0 || bankDepositExpected < bankDeposit) {
		cout << "Не верно введенны данные!" << endl;
	} else {
    
		while (bankDeposit < bankDepositExpected) {
			bankDeposit += (bankDeposit * 10 / 100);
			++yearWaiting;
		}

    //определяем, как правильно склонять слово "год"
		if (yearWaiting % 100 >= 11 && yearWaiting % 100 <=14) yearDeclension = " лет";
		else if (yearWaiting % 10 == 1) yearDeclension = " год";
		else if (yearWaiting % 10 >= 2 && yearWaiting <= 4) yearDeclension = " года";
		else yearDeclension = " лет";

		cout << "Придется подождать " << yearWaiting << yearDeclension << endl;;
	}
}
