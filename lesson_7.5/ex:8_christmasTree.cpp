#include <iostream>

using namespace std;

int main() {

	int treeHeight;
	int sharpAmount = 1;

	cout << "Программа для отображения ёлочки" << endl << endl;
	cout << "Введите высоту ёлочки: ";
	cin >> treeHeight;

	if (treeHeight <= 0) cout << "Ввели некорректные данные высоты" << endl;
	else {	
		
		// цикл отображения
		for (int row = 1; row <= treeHeight; row++) {
	
			// отображаем пустые пробелы
			for (int space = 0; space < (treeHeight - row); space++) cout << " ";
	
			// тображаем решетки
			for (int sharp = 0; sharp < sharpAmount; sharp++) cout << "#";
	
			// на каждой строке увеличиваем на 2 кол-во решеток
			sharpAmount += 2;
	
			cout << endl;
	
		}

	}
}
