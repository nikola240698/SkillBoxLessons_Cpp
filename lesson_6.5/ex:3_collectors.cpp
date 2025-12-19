#include <iostream>

using namespace std;

int main() {

	int debtAmount, debtPayment;
	string debtorName;
	bool debtPresence = true;			//считаем, что уже есть долг, иначе зачем это всё

	cout << "---------- Программа-робот для коллекторов ----------" << endl;
	cout << "Данная программа указывает, какой у Вас текущий долг" << endl << endl;
	cout << "Представьтесь, пожалуйста: ";
	getline(cin, debtorName);
	cout << "Укажите Ваш долг: ";
	cin >> debtAmount;
	
	if (debtAmount == 0) cout << "Уважаемый " << debtorName << ", Ваш долг погашен!" << endl;		
	else if (debtAmount < 0) cout << "Не тратье попусту наше время!" << endl;
	else {
		while (debtPresence) {
			cout << debtorName << ", Ваш долг составляет " << debtAmount << " руб" <<endl;
			cout << "Сколько вносите оплаты? ";
			cin >> debtPayment;

			debtAmount -= debtPayment;								//вычисляем остаток долга
			debtPresence = debtAmount > 0;							//проверяем, что долг еще остался

			if (!debtPresence) {
				cout << "Уважаемый " << debtorName << ", Ваш долг погашен!" << endl;
				if (debtAmount != 0) {
					cout << "Остаток на Вашем счету составляет " << debtAmount * (-1) << " руб" << endl;
				}
				break;
			}
		}
	}
}
