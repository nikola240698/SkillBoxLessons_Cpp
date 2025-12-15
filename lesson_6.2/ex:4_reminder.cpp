#include <iostream>
#include <cmath>

int main() {

	int n;
	int count = 0;

	std::cout << "Сколько раз Вам необходимо напомнить?: ";
	std::cin >> n;

	while (count < n) {
		std::cout << "Вы хотели не забыть о чем-то" << std::endl;
		count++;
	}

}
