#include <iostream>

using namespace std;

int main() {

	int bacteriaAmount;
	int antibioticAmount;

	cout << "Программа для девонстарции работы антибиотика" << endl << endl;
	cout << "Введите количество бактерий: ";
	cin >> bacteriaAmount;
	cout << "Введите количество антибиоткиа: ";
	cin >> antibioticAmount;

	// проверяем введенные данные
	if (bacteriaAmount == 0) cout << "У вас уже нет бактерий" << endl;
	else if (antibioticAmount == 0 ) cout << "Упс, Вы забыли про антибиотк" << endl;
	else if (bacteriaAmount < 0 || antibioticAmount < 0) cout << "Ввели отрицательные значения" << endl;
	else {

		// инициализируем переменные счетчики часов и силы действия антибиотика
		int hourCounter = 1;
		int antibioticActivity = 10;

		// начинаем эксперимент
		// ограничиваемся нулевым значением бактерий или воздейтсвия антибиотика
		while (bacteriaAmount != 0 && antibioticActivity != 0) {

			// производим рост бактерий
			bacteriaAmount *= 2;
			// убиваем бактерии
			bacteriaAmount -= (antibioticAmount * antibioticActivity);
			/* в случае изменения порядка следования, то есть
			 * сначала убиваем батерии
			 * затем происходит их рост
			 * необходимо сменить местами строки вычсления
			 */

			// избавляемся от отрицательного числа бактерий
			if (bacteriaAmount < 0) bacteriaAmount = 0;

			cout << "После " << hourCounter << " часа бактерий осталось " << bacteriaAmount << endl;

			// сдвигаем час
			hourCounter++;
			// уменьшаем силу антибиотика
			antibioticActivity--;

		}

		//подводим итоки
		cout << "**** Итог ****" << endl;
		if (antibioticActivity == 0) cout << "К сожалению, мы не смогли спасти мир..." << endl;
		else if(bacteriaAmount == 0) cout << "Поздравляю! Мы сможем побороть эпидемию!" << endl;

	}

}

