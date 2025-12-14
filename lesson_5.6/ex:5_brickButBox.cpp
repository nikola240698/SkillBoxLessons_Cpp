#include <iostream>
#include <algorithm>

int main() {

	int a, b, c, x, y, z;
  
	std::cout << "Программа для проверки возможности поместить \n";
	std::cout << "первую коробку во вторую \n";

	std::cout << "Введите размеры первой коробки: ";
	std::cin >> a >> b >> c;
	std::cout << "Введите размеры второй коробки: ";
	std::cin >> x >> y >> z;
  std::cout << "---------- Проверяем ----------" << std::endl;

	int minBoxSmall = std::min ({a, b, c});          //определяем меньшую сторону маленькой коробки
	int maxBoxSmall = std::max ({a, b, c});          //определяем большую сторону маленькой коробки

	int minBoxBig 	= std::min({x, y ,z});           //определяем меньшую сторону большой коробки
	int maxBoxBig 	= std::max({x, y, z});           //определяем большую сторону большой коробки

	if (minBoxSmall < minBoxBig && maxBoxSmall < maxBoxBig                                        //при условии, что меньшая и большая сторона маленькой коробки меньше, чем у больгой
			&& (a + b + c - (minBoxSmall + maxBoxSmall)) < (x + y + z - (minBoxBig + maxBoxBig))) {   //при условии, что сторона средней величины у маленькой коробки меньше
		std::cout << "Вы можете сделать это\n";

	} else std::cout << "Увы, коробка не поместится\n";

}
