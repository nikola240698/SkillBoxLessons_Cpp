#include <iostream>

using namespace std;

int main() {

	float price, totalPrice, weight;

	cout << "Программа для расчета стоимости весового товара" << endl << endl;

	cout << "Введите стоимость товара за 100г : ";
	cin >> price;
	cout << "Введите вес товара (г): ";
	cin >> weight;

	if (price <= 0 || weight <= 0) cout << "Не верно введены данные" << endl;
	else {

		cout << "----- Считаем -----" << endl;

		totalPrice = price / 100 * weight;

		cout << "Итоговая сумма равна " << totalPrice << " руб" << endl;

	}

}
