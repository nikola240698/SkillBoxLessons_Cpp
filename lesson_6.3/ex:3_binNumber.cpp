#include <iostream>

int main() {

	int numberCheck;
	int calcArea = 0;
	int count = 1;

	std::cout << "Введите число: ";
	std::cin >> numberCheck;

	while (numberCheck > 0){
		if (numberCheck % 10 == 0 || numberCheck % 10 == 1) {}
		else {
			std::cout << "Введенное число не является бинарным" << std::endl;
			break;
		}
		numberCheck /= 10;
	}

	if (numberCheck == 0 ) std::cout << "Введенное число является бинарным" << std::endl;

}
