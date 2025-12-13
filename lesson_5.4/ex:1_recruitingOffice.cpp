#include <iostream>

int main() {

	int height, weight, experience;
	int leg, hand;
	std::string eyeColor;

	std::cout << "Программа для определения призывника в летчики" << std::endl << std::endl;
	std::cout << "Введите рост и вес призывника: ";
	std::cin >> height >> weight;
	std::cout << "Введите количество ног и рук призывника: ";
	std::cin >> leg >> hand;
	std::cout << "Укажите количество налетавших часов призывника: ";
	std::cin >> experience;
	std::cout << "Укажите цвет глаз призывника: ";
	std::cin >> eyeColor;
	std::cout << "----------------- Оперделяем -----------------" << std::endl;

	if ((height > 165 || height < 145) || (weight > 65 || weight < 45) || !(leg == 2 && hand == 2)
			|| experience < 100 || !(eyeColor == "зеленые" || eyeColor == "зелёные")) {
		std::cout << "Не годен!" << std::endl;
	} else {
		std::cout << "Годен!" << std::endl;
	}

}
