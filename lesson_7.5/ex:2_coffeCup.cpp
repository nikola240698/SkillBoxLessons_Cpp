#include <iostream>

using namespace std;

int main() {

	int waterAmount, milkAmount;
	int choice;
	int americanoCup = 0;
	int latteCup = 0;

	bool ingredients = false;

	cout << "Добро пожаловать. Давайте приготовим кофе" << endl;

	// проверяем, что пользователь ввел количество больше минимума одной кружки
	while (!ingredients) {

		cout << "Введите количество воды: ";
		cin >> waterAmount;
		cout << "Введите количество молока: ";
		cin >> milkAmount;

		ingredients = waterAmount >= 30 && milkAmount >= 270;

		if (ingredients) break;
		cout << "Вы ввели малое количество ингредиентов" << endl;

	}

	// процесс приготовления
	while (ingredients) {
		//прверяем, что выбран один из варинтов напитка
		while (true) {
			cout << "Выберите напиток (1 - Американо, 2 - Латте): ";
			cin >> choice;
			if (choice == 1 || choice == 2) break;
			cout << "Выберите один из предложенных вариантов" << endl;
		}

		// производим расход ингридиентов в соостветсвии с выбором
		if (choice == 1 && waterAmount >= 300) {
			americanoCup++;
			waterAmount -= 300;
			cout << "Ваш напиток готов." << endl;
		} else if (choice == 2 && milkAmount >= 270 && waterAmount >=30) {
			latteCup++;
			waterAmount -= 30;
			milkAmount -= 270;
			cout << "Ваш напиток готов." << endl;
		} else cout << "Не хватает ингредиентов на этот напиток" << endl;
	
    // проверяем, что еще остались ингридиенты
		ingredients = waterAmount >= 30 && milkAmount >= 270;
	}
  
	// выводим отчет
	cout << " *** Отчет *** " << endl;
	cout << "Ингридиентов осталось: " << endl;
	cout << "\t\tВода: " << waterAmount << " мл" << endl;
	cout << "\t\tМолоко: " << milkAmount << " мл" << endl;
	cout << "Кружек Американо приготовлено: " << americanoCup << endl;
	cout << "Кружек Латте приготовлено: " << latteCup << endl;

}

