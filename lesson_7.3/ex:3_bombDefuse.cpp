#include <iostream>

using namespace std;

int main() {

	int timeLeft = 10;
	string answer;
  
	cout << "Программа обезвреживания бмобы" << endl;
	cout << "Вы - герой, который спасет мир!" << endl;
	cout << "Необходимо лишь обезвредить бмобу!" << endl;
	cout << "Берите кусачки в руки, и вперед действовать!" << endl << endl;

	for (; timeLeft > 0; timeLeft--) {
		cout << "Хотите ли перерезать провод сейчас? ";
		getline(cin, answer);
		if (answer == "да" || answer == "Да") break;
	}
  
	if (timeLeft > 0) {
		cout << "Вы обезвредили бомбу!" << endl;
		cout << "До взрыва оставалось " << timeLeft << endl;
	} else cout << "Увы, вы не спасли Мир и взорвались..." << endl;

}

