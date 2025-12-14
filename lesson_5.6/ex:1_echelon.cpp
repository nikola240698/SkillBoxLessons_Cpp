#include <iostream>

int main() {

	int speed, hight;

	std::cout << "Программа для аэропорта, проверяющая \n"
			"правильным ли эшелоном летит самолет \n\n";

	std::cout << "Введите скорость и высоту самолета:";
	std::cin >> speed >> hight;

	if ((speed < 750 || speed > 850) || (hight < 9000 || hight > 9500)) {
		std::cout << "Смените эшелон!" << std::endl;
	} else {
		std::cout << "Держитесь этого эшелона" << std::endl;
	}
}
