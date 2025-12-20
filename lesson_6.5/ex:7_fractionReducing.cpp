#include <iostream>

using namespace std;

int main() {

	int m, n;                        //вводимые переменные
	int numerator, denominator;      //перемнные для расчета
	int division, divisionResidue;   //переменные промежуточных расечтов

	cout << "---- Программа для сокращения дробей ----" << endl << endl;
	cout << "Введите числитель: ";
	cin >> m;
	cout << "Введите знаменатель: ";
	cin >> n;

	//Проверяем, что не введен ноль
	if (m == 0 || n == 0) cout << "Ноль не имеет делителя" << endl;
	else {
		//используем алгоритм Евклида
        
		//избавляемся от минуса в поиске НОД
		numerator = abs(m);
		denominator = abs(n);

		do {
			//проверяем налчиие остатка от деления
			division = denominator / numerator;
			divisionResidue = denominator % numerator;
			//в случае нахождения его сразу же
			if (divisionResidue == 0) {
				break;
			} else {
				//если есть остаток, то продолжаем дальше
				denominator = numerator;
				numerator = divisionResidue;
			}
		} while(divisionResidue > 0);

		//сокращем дробь
		m /= numerator;
		n /= numerator;
        
		cout << "Результат: " << m << "/" << n << endl;
	}
}
