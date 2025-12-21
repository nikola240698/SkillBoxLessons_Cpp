#include <iostream>

using namespace std;

int main() {

	float proteins, carbohydrates, weight;
  
	cout << "Программа для расчета белков и углеводов в продукте" << endl << endl;

	cout << "Введите колчиество белков на 100г продукта: ";
	cin >> proteins;
	cout << "Введите колчиество углевовдов на 100г продукта: ";
	cin >> carbohydrates;
	cout << "Введите массу нетто товара (г): ";
	cin >> weight;

	if (proteins <= 0 || carbohydrates <= 0 || weight <= 0) cout << "Не верно введены данные" << endl;
	else {

		cout << "----- Считаем -----" << endl;

		proteins = proteins / 100 * weight;
		carbohydrates = carbohydrates / 100 * weight;

		cout << "В продукте содержится " << proteins << "г белка и " << carbohydrates << "г углеводов" << endl;

	}

}
