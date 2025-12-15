#include <iostream>

int main() {

	int n;
	int count = 0;
	std::string reminderText;

	std::cout << "Что должно быть в тексте напоминания?: ";
	std::getline(std::cin, reminderText);

	std::cout << "Сколько раз Вам необходимо напомнить?: ";
	std::cin >> n;

	while (count < n) {
		std::cout << reminderText << std::endl;
		count++;
	}

}
