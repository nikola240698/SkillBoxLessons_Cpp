#include <iostream>

using namespace std;

int main() {
	
	int maxX, maxY;

	cout << "Программа для отображения осей системы координат" << endl << endl;
	cout << "Введите ширину и высоту системы: ";
	cin >> maxX >> maxY;

	if (maxX < 3 || maxY < 3) cout << "Введены некорректные значния" << endl;
	else {

		for (int y = 0; y < maxY; y++) {
			for(int x = 0; x < maxX; x++){

				if (y == maxY / 2 && x == maxX / 2) cout << "+";
				else if (y == maxY / 2 && x == maxX - 1) cout << ">";
				else if (y == maxY / 2) cout << "-";
				else if (x == maxX / 2 && y == 0) cout << "^";
				else if (x == maxX / 2) cout << "|";
				else cout << " ";

			}
			cout << endl;
		}

	}

}

