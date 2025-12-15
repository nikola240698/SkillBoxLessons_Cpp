#include <iostream>
#include <cmath>

int main() {

	int n, k;
	int count = 0;

	std::cout << "Ввведите число К: ";
	std::cin >> k;
	std::cout << "Введите число N: ";
	std::cin >> n;

	while (count <= n) {
		std::cout << "2 ^ " << count << " = " << std::pow(k, count) << std::endl;;
		count++;
	}

}
