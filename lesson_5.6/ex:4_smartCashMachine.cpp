#include <iostream>

int main() {

	int cashPull;
  
	std::cout << "Программа для проверки возможности выдачи \n";
	std::cout << "наличных банкоматом оптимальными купюрами \n";

	std::cout << "Введите необходимую сумму снятия: ";
	std::cin >> cashPull;
	std::cout << "------------ Проверяем ------------" << std::endl;

	if (cashPull < 100 || cashPull >150000 || cashPull % 100 != 0 ) {
		std::cout << "Банкомат не сможет выдать деньги" << std::endl;
	} else {
		std::cout << "Банкомат может выдать вам ";
		if (cashPull >= 5000) {
		  int cashOnHand = cashPull / 5000;
			std::cout << cashOnHand << " по 5000, ";
			cashPull = cashPull - (cashOnHand * 5000);
		}

		if (cashPull >= 2000) {
				int cashOnHand = cashPull / 2000;
				std::cout << cashOnHand << " по 2000, ";
				cashPull = cashPull - (cashOnHand * 2000);
				}

		if (cashPull >= 1000) {
				int cashOnHand = cashPull / 1000;
				std::cout << cashOnHand << " по 1000, ";
				cashPull = cashPull - (cashOnHand * 1000);
				}

		if (cashPull >= 500) {
				int cashOnHand = cashPull / 500;
				std::cout << cashOnHand << " по 500, ";
				cashPull = cashPull - (cashOnHand * 500);
				}

		if (cashPull >= 200) {
				int cashOnHand = cashPull / 200;
				std::cout << cashOnHand << " по 200, ";
				cashPull = cashPull - (cashOnHand * 200);
				}

		if (cashPull >= 100) {
				int cashOnHand = cashPull / 100;
				std::cout << cashOnHand << " по 100, ";
				cashPull = cashPull - (cashOnHand * 100);
				}
	}

}
