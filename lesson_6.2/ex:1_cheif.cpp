#include <iostream>

int main() {

	std::string answer;

	do {
		std::cout << "Выполнили ли Вы задания, которое выдали Вам вчера?";
		std::getline(std::cin, answer);
	} while (answer != "Да, конечно сделал");

}
