#include <iostream>

using namespace std;

int main() {
  
	int plotArea;
	int area = 1;

	cout << "Программа для проверки квадратных площадей" << endl << endl;

	cout << "Введите площадь участка: ";
	cin >> plotArea;

	if (plotArea <= 0 || plotArea > 1000000) cout << "Введенные данные не врспринимаются программой" << endl;
	else {
    
		for (; area * area < plotArea; area++) {
		}

		if (area * area == plotArea) cout << "Участок является точным квадратом" << endl;
		else cout << "Участок не является точным квадратом" << endl;

	}
}

