#include <iostream>

int main() {

	int a, b, c, x, y;
	int minBlockSide, middleBlockSide;

	std::cout << "Программа для помощи Винни-Пуха, сравнивающая отверстие и кирпич" << std::endl;
	std::cout << std::endl;
	std::cout << "Введите параметры кирпича: ";
	std:: cin >> a >> b >> c;
	std::cout << "Введите параметры отверстия в стене";
	std::cin >> x >> y;

	if (a < b && a < c) {
		minBlockSide = a;
		if (b < c) middleBlockSide = b;
		else middleBlockSide = c;
	} else if (b < a && b <c) {
		minBlockSide = b;
		if (a < c) middleBlockSide = a;
		else middleBlockSide = c;
	} else {
		minBlockSide = c;
		if (a < b) middleBlockSide = a;
		else middleBlockSide = b;
	}

	if (middleBlockSide <= std::max(x, y) && minBlockSide <= std::min(x, y)) {
		std::cout << "Кирпич входит!" << std::endl;
	} else std::cout << "Кирпич не входит!" << std::endl;

}
