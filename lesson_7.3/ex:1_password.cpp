#include <iostream>

using namespace std;

int main() {
  
	string answer;
  
	cout << "Программа-вымогатель пароля" << endl << endl;

	for (;;) {
		cout << "Введите пароль: ";
		getline(cin, answer);

		if (answer == "password") break;
		
    cout << "Вы ввели неверный пароль" << endl;
	}

	cout << "Добро пожаловать!" << endl;
  
}

