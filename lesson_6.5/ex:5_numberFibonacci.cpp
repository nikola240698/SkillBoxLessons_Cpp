#include <iostream>

using namespace std;

int main() {

	int firstValue = 1;
	int secondValue = 0;
	int thirdValue = 0;
	int sequenceNumber;
	int count = 1;

	cout << "------ Программа вывода чисел Фибоначчи -------" << endl;
	cout << "Введите номер последовательности: ";
	cin >> sequenceNumber;

	if (sequenceNumber > 0 && sequenceNumber <= 46) {
		
    while (count < sequenceNumber){
			thirdValue = secondValue;
			secondValue = firstValue;
			firstValue = secondValue + thirdValue;
			++count;
		}
		cout << "Число в последовательности: " << firstValue;
    
	} else cout << "Указанная последовательность за рамками возможности порограммы, увы" << endl;
}
