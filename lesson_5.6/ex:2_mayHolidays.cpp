#include <iostream>

int main() {

	int day;

	std::cout << "Для оперделения рабочий или выходной введеный день мая\n\n";
	std::cout << "Введите интересующий день:";
	std::cin >> day;
	std::cout << "------------ Проверяем ------------" << std::endl;
  
	if (day > 0 && day <=31) {
		if (day <=5 || (day >=8 && day <= 10) || (day++) % 7 == 0 || day % 7 == 0) {
			std::cout << "Выходной день!" << std::endl;
		} else {
			std::cout << "Рабочий день!" << std::endl;
		}
	} else std::cout << "Не верно введен номер дня!" << std::endl;
  
}
