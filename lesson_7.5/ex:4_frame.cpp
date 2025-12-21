#include <iostream>

using namespace std;

int main() {

	int width, height;

	cout << "Программа для отображения символьной рамки проивольного размера" << endl << endl;
	cout << "Введите ширину и высоту рамки: ";
	cin >> width >> height;

	for (int y = 1; y <= height; y++) {
		for(int x = 1; x <= width; x++){

			if (x == 1 || x == width) cout << "|";
			else if (y == 1 || y == height) cout << "-";
			else cout << " ";
		
    }
		cout << endl;
	}

}

