#include <iostream>

using namespace std;

int main() {

	int posX = 0, posY = 0;
	int maxX = 15;
	int maxY = 20;
	string mov;

	cout << "Программа управления движением марсохода" << endl;
	cout << "Для передвижения используйте команды W, A, S, D" << endl;


	// бесконечный цик передвижения
	while (true) {

		cout << "[Программа]: Марсоход находится на позиции " << posX << ", " << posY << ". Введите команду: " << endl;
		// проверяем, что ввели правильную команду
		while (true) {
			cout << "[Оператор]: ";
			cin >> mov;
			if (mov == "W" || mov == "A" || mov == "S" || mov == "D") break;
			cout << "Введена неверная команда" << endl;
		}

    // делаем шаги марсоходом  проверкой его крайних положений
		if (mov == "W") {
			if (posY == 20) {}
			else posY++;
		} else if (mov == "A") {
			if (posX == 0) {}
			else posX--;
		} else if (mov == "S") {
			if (posY == 0) {}
			else posY--;
		} else {
			if (posX == 15) {}
			else posX++;
		}

	}

}

