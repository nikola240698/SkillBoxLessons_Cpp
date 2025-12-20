#include <iostream>

using namespace std;

int main() {
	int numberCheck;

	cout << "Программа-шпаргалка таблицы умножения" << endl << endl;

	cout << "Укажите, какое число преверяем? ";
	cin >> numberCheck;
	cout << "Выводим таблицу: " << endl;

	for (int i = 1; i <= 9; i++) {
		cout << numberCheck << "х" << i << "=" << numberCheck * i << endl;
	}
  
}

