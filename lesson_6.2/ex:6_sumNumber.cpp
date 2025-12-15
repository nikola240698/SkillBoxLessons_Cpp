#include <iostream>

int main() {

	int number = 0;
	int sum = 0;
	int sumCount;

	std::cout << "Сколько чисел Вы хотите сложить?: ";
	std::cin >> sumCount;

	do {
		std::cout << "Введите число: ";
		std::cin >> number;
		sum += number;
		sumCount--;

	} while(sumCount > 0);

	std::cout << "Сумма чисел равна " << sum << std::endl;

}
