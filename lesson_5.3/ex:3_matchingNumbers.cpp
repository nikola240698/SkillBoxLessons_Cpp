#include <iostream>

int main() {

	int a, b, c;

	std::cout << "Программа для определения всовпадающих чисел" << std::endl << std::endl;
	std::cout << "Введите три числа: ";
	std::cin >> a >> b >> c;

	if (a == b && b == c) std::cout << "3 совпадающих";
	else if (a == b || b == c || a == c) std::cout << "2 совпадающих";
	else std::cout << "Нет совпадающих";

}
