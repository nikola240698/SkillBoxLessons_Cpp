#include <iostream>

int main() {

	int a, b, c, d;

	std::cout << "Введите 4 числа: ";
	std::cin >> a >> b >> c >> d;

	while ((a + b + c + d) != 42) {
		std::cout << "Ввод некорректный" << std::endl;
		std::cout << "Введите 4 числа: ";
		std::cin >> a >> b >> c >> d;
	}

	std::cout << "Ввод корректный" << std::endl;

}
