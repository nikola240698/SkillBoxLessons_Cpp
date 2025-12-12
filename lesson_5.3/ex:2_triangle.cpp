#include <iostream>

int main() {

	int a, b, c;
	int sumTwoSide, maxNum;

	std::cout << "Программа для определения возможности построениятреугольника" << std::endl << std::endl;
	std::cout << "Введите три стороны треугольника: ";
	std::cin >> a >> b >> c;

	if (a >= b && a>= c) {
		sumTwoSide = b + c;
		maxNum = a;
	}
	else if (b >= a && b >= c) {
		sumTwoSide = a + c;
		maxNum = a;
	}
	else {
		sumTwoSide = a + b;
		maxNum = a;
	}

	if (maxNum < sumTwoSide) std::cout << "Треугольник возможен" << std::endl;
	else std::cout << "Треугольник не возможен" << std::endl;

}
