#include <iostream>

int main() {

	int itemPrise;
	int itemDelivery;
	int itemDiscount;
	std::string item;
	int totalPrise;

	item = "яблоки";
	itemPrise = 1500;
	itemDelivery = 400;
	itemDiscount = 200;
	totalPrise = itemPrise + itemDelivery - itemDiscount;

	std::cout << "Вами был выбран заказ: " << item << std::endl;
	std::cout << "Стоимость заказа " << itemPrise << "тг. + доставка " << itemDelivery << "тг." << std::endl;
	std::cout << "С учетом Вашей скидки " << itemDiscount << "тг., Ваш заказ обойдется Вам в " << totalPrise << "тг." << std::endl;

	std::cout << std::endl;

	item = "суши";
	itemPrise = 6400;
	itemDelivery = 800;
	itemDiscount = 320;
	totalPrise = itemPrise + itemDelivery - itemDiscount;

	std::cout << "Вами был выбран заказ: " << item << std::endl;
	std::cout << "Стоимость заказа " << itemPrise << "тг. + доставка " << itemDelivery << "тг." << std::endl;
	std::cout << "С учетом Вашей скидки " << itemDiscount << "тг., Ваш заказ обойдется Вам в " << totalPrise << "тг." << std::endl;

	


}
