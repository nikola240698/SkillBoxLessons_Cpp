#include <iostream>

using namespace std;

int main() {

	int numberBorder;
	int sum = 0;

	cout << "Программа суммирования нечетных чисел до указанного" << endl << endl;

	cout << "Укажите, какое число будет границей? ";
	cin >> numberBorder;
	cout << "Выводим сумму: " << endl;

	for (int i = 1; i <= numberBorder; i++) {
		if (i % 2 != 0) sum += i;
	}
  
	cout << "Сумма нечетых чисел равна " << sum << endl;
  
}

