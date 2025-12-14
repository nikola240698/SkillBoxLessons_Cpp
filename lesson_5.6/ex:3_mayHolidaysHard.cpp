#include <iostream>

int main() {

	int day, weekDay;

	std::cout << "Для оперделения рабочий или выходной введеный день мая\n\n";
  
	std::cout << "Введите интересующий день и день недели первого числа: ";
	std::cin >> day >> weekDay;
	std::cout << "------------ Проверяем ------------" << std::endl;;

	if ((day > 0 && day <=31) && (weekDay > 0 && weekDay <= 7)) {
		if (day <=5 || (day >=8 && day <= 10) || (day + weekDay) % 7 == 0 || (day + weekDay - 1) % 7 == 0) {
			std::cout << "Выходной день!" << std::endl;
		} else {
			std::cout << "Рабочий день!" << std::endl;
		}
	} else std::cout << "Не верно введен номер дня!" << std::endl;
  
}
