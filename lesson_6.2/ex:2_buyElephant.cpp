#include <iostream>

int main() {

	std::string userName;
	std::string answer;

	std::cout << "Как к Вам обращаться?" << std::endl;
	std::getline(std::cin, userName);
	std::cout << userName << ", купи слона!" << std::endl;	

	while (true) {
		std::getline(std::cin, answer);
		std::cout << "Все говорят " << answer << ", а ты купи слона!" << std::endl;
	}
  
}
