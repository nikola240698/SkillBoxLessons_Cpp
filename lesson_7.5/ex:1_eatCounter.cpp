#include <iostream>

using namespace std;

int main() {
  
	int monthCounter = 1;
	int eatCounter = 100;
  
	cout << "Программа для отображения вашего остатка продовольствия" << endl;
	cout << "Вы - пилот, корабль которого потерпел крушение!" << endl;
	cout << "Из запасов у Вас только мешок гречки на 100 кг" << endl;
	cout << "И в месяц вы потребляете 4 кг гречки" << endl;
	cout << "Ожидая пмощи, получается такой расклад: " << endl;

	for (; eatCounter > 0;) {
		eatCounter -= 4;
		cout << "После " << monthCounter << " месяца у Вас в запасе останется " << eatCounter << " кг гречки" << endl;
		monthCounter++;
	}

}

