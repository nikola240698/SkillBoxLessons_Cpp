#include <iostream>

int main() {

	int plotArea = 0;
	int calcArea = 0;
	int count = 1;

	std::cout << "Введите площадь участка: ";
	std::cin >> plotArea;

	while (calcArea < plotArea){
    
		calcArea = count * count;
		
    if (calcArea == plotArea) {
			std::cout << "Площадь участка является точным квадратом" << std::endl;
			break;
		} else if (calcArea > plotArea || calcArea > 1000000) {
			std::cout << "Площадь участка не является точным квадратом" << std::endl;
			break;
		}
    
		++count;
	}

}
