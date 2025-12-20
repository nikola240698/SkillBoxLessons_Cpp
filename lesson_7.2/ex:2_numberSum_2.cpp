#include <iostream>

using namespace std;

int main() {

	int numberAmount;
	int numberTerm;
	int sum = 0;

	cout << "Программа счета числе бухгалтера" << endl << endl;
  
	cout << "Укажите, сколько чисел надо сложить? ";
	cin >> numberAmount;
  
	for (int i = 1; i <= numberAmount; i++) {
		cout << "Введите " << i << " число: ";
		cin >> numberTerm;
		sum += numberTerm;
	}

	cout << "Сумма введенных чисел равна " << sum << endl;

}

