#include <iostream>

int main() {

	int number;
  int sum = 0;
  
	std::cout << "Введите число: ";
	std::cin >> number;

	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}

	if (sum == 42) std::cout << "Ввод корректный";
	else std::cout << "Ввод некорректный";

}
