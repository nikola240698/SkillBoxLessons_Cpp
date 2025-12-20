#include <iostream>

using namespace std;

int main() {

	int startNumber = 63;
	int division;
	// заранее принимаем ответ "нет", для первого деления участка в меньшую сторону
	string answer = "нет";		

	cout << "Программа, способная угадать загаданное Вами число!" << endl;
	cout << "Загадайте число от 0 до 63 включительно" << endl;
	cout << "И отвечайте да/нет на всего лишь один вопрос" << endl << endl;

	// используем перменную для деления участка поиска
	division = startNumber;

	do {
    
		// каждый раз разбиваем участок поиска пополам
		division /= 2;
		// если число больше, то берем участок выше
		if (answer == "да") startNumber += (1 + division);
		// если чиссло меньше, то берем участок ниже
		else startNumber -= (1 + division);
		//узнаем у пользователя следующий шаг
		cout << "Ваше число больше чем " << startNumber << "? ";
		cin >> answer;
	
  } while (division > 0);
  
	// последняя коррекция, для выбора числа правой границы последнего участка
	if (answer == "да") startNumber += 1;

	cout << "Вы загадали число " << startNumber << endl;

}

