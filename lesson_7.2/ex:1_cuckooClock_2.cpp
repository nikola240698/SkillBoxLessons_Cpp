#include <iostream>

using namespace std;

int main() {

	int currentHour;

	cout << "Программа иммитатор часов с кукушкой" << endl << endl;

	cout << "Укажите, который час? ";
	cin >> currentHour;
	cout << "Кукушка прокричала: " << endl;

	if (currentHour <= 0 || currentHour > 24) cout << "Не верное значение часа" << endl;
	else {
		if (currentHour > 12) currentHour -= 12;
		for (int i = 0; i < currentHour; i++) {
			cout << "Ку-ку!" << endl;
		}
	}
}

