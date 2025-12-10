#include <iostream>

int main() {

	int shiftDuration;
	int orderTime;
	int orderCollect;
	int clientsNumber;

	shiftDuration = 480;
	orderTime = 2;
	orderCollect = 4;
	clientsNumber = shiftDuration/(orderTime+orderCollect);

	std::cout << "Эта программа рассчитает, сколько клиентов успеет обслужить кассир за смену." << std::endl;
	std::cout << "Введите длительность смены в минутах :" << shiftDuration << std::endl;
	std::cout << "Сколько минут клиент делает заказ? " << orderTime << std::endl;
	std::cout << "Сколько минут кассир собирает заказ? " << orderCollect << std::endl;
	std::cout << "------Считаем------" << std::endl;
	std::cout << "За смену длиной " << shiftDuration << " минут кассир успеет обслужить " << clientsNumber << " клиентов." << std::endl;

	std::cout << std::endl;

	shiftDuration = 10*60;
	orderTime = 3;
	orderCollect = 20;
	clientsNumber = shiftDuration/(orderTime+orderCollect);

	std::cout << "Эта программа рассчитает, сколько клиентов успеет обслужить кассир за смену." << std::endl;
	std::cout << "Введите длительность смены в минутах :" << shiftDuration << std::endl;
	std::cout << "Сколько минут клиент делает заказ? " << orderTime << std::endl;
	std::cout << "Сколько минут кассир собирает заказ? " << orderCollect << std::endl;
	std::cout << "------Считаем------" << std::endl;
	std::cout << "За смену длиной " << shiftDuration << " минут кассир успеет обслужить " << clientsNumber << " клиентов." << std::endl;
}
