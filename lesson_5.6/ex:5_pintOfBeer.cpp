#include <iostream>
#include <algorithm>

int main() {

	int todayDay, todayMonth, todayYear;
	int birthDay, birthMonth, birthYear;
  
	std::cout << "Программа для проверки возможности продать кружку пива\n";
	std::cout << "посетителю, при условии что ему больше 18 лет  \n";

	std::cout << "День рождения посетителя (DD MM YYYY): ";
	std::cin >> birthDay >> birthMonth >> birthYear;
	std::cout << "Сегодняшняя дата (DD MM YYYY): ";
	std::cin >> todayDay >> todayMonth >> todayYear;	
	
	if (todayYear - birthYear > 18) {                //при условии, что ему больше 18 лет
		std::cout << "Можно" << std::endl;
	} else if (todayYear - birthYear == 18) {        //если разница между годами ровно 18
		if (todayMonth - birthMonth > 0) {             //убеждаемся, что сейчас месяц более "старший"
			std::cout << "Можно" << std::endl;
		} else if (todayMonth - birthMonth == 0) {     //если меясца равны
			if (todayDay - birthDay > 0) {               //проверяем, что день как минимум следующий после ДР 
				std::cout << "Можно" << std::endl;
			} else std::cout << "Нельзя" << std::endl;
		} else std::cout << "Нельзя" << std::endl;
	} else std::cout << "Нельзя" << std::endl;;







}
