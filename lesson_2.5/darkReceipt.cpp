#include <iostream>

int main() {

	int receiptPrise = 4000000;
	int entranceNumber = 10;
	int apartmentNumber = 40;
	int apartmentPayment = receiptPrise/(entranceNumber*apartmentNumber);

	std::cout << "Приветсвуем Вас в калькуляторе квартплаты!" << std::endl;
	std::cout << std::endl;
	std::cout << "Введите сумму указанную в квитанции: " << receiptPrise << std::endl;
	std::cout << "Сколько подъездов в Вашем доме? " << entranceNumber << std::endl;
	std::cout << "Сколько квартир в каждом подъезде? " << apartmentNumber << std::endl;
	std::cout << "-------Считаем-------" << std::endl;
	std::cout << "Каждая квартира должна платить по " << apartmentPayment << " руб." << std::endl;
}
