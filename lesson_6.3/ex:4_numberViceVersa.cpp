#include <iostream>

int main() {

	int numberViceVersa;

	std::cout << "Введите число: ";
	std::cin >> numberViceVersa;

	std::cout << "Получаем число в обратном порядке: ";

	while (numberViceVersa > 0){
		std::cout << numberViceVersa % 10;
		numberViceVersa /= 10;
	}
}
