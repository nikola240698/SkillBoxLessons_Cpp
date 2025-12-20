#include <iostream>

using namespace std;

int main() {

	int counter;
	string answer;

	cout << "Программа напоминания выполнения задания" << endl << endl;

	for (counter = 1; true; counter++) {
		cout << "Выполнил задание, которое я дал тебе вчера? ";
		getline(cin, answer);
		if (answer == "Да, конечно сделал") break;
	}
  
	cout << "Ну почему тебя нужно спрашивать " << counter << " раз" << endl;

}

