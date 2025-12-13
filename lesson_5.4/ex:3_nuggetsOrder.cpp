#include <iostream>

int main() {

	int orderSize;
	int boxSixSize 	= 0;
	int boxNineSize = 0;

	std::cout << "Программа длля опеределения возможности выполнения " << std::endl;
	std::cout << "заказа нагетсов в Макдональдсе" << std::endl;
	std::cout << "Учтите, что мы продаем нагетсы в коробках по 6 и 9 штук!" << std::endl;
	std::cout << std::endl;
	std::cout << "Введите желаемое колчиество нагетсов: ";
	std:: cin >> orderSize;

	if (orderSize % 6 == 3 && orderSize != 9) {
				boxSixSize = (orderSize / 6) - 1;
				boxNineSize = 1;
				std::cout << "Предлагаем Вам взять " << boxSixSize << " коробки по 6 штук и " << boxNineSize
							<< " коробки по 9 шутк" << std::endl;
	} else if (orderSize % 9 == 0) {
				boxNineSize = orderSize / 9;
				std::cout << "Предлагаем Вам взять "  << boxNineSize << " коробки по 9 шутк" << std::endl;
	} else if (orderSize % 6 == 0) {
					boxSixSize = orderSize / 6;
					std::cout << "Предлагаем Вам взять " << boxSixSize << " коробки по 6 штук" << std::endl;
	} else std::cout << "Заказ не может быть выполнен!" << std::endl;

}
