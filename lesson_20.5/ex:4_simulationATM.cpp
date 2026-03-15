#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <limits>

// контроль вводимых данных
bool checkInput(int &value) {
    // вводим данные
    std::cin >> value;
    // проверяем, что введены числа
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cerr << "Incorrect data" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    // проверяем, что введено число кратное 100
    if (value % 100 != 0) {
        std::cout << "The ATM dispenses amounts in multiples of 100" <<std::endl;
        return false;
    }
    return true;
}

// контроль ввода действия пользователя
bool checkAction(char &action) {
    // вводим данные
    std::cin >> action;
    // проверяем, что введены числа
    if (std::cin.fail() || std::cin.peek() != '\n') {
        std::cerr << "Incorrect data" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}


// функция расчета общей суммы в банкомате
int currSummBanknote(const std::vector<int> &banknote, const std::vector<int> &nominal) {
    int sum = 0;

    for (int i = 0; i < banknote.size(); ++i) {
        sum += banknote[i] * nominal[i];
    }

    return sum;
}

// функция расчета количества купюр в банкомате
int currAmountBanknote(const std::vector<int> &banknote) {
    int currentSum = 0;
    for (int i = 0; i < banknote.size(); ++i) {
        currentSum += banknote[i];
    }
    return currentSum;
}

// заполняем рандомными числами банкноты банкомата
void refillATM(std::vector<int> &banknote) {
    // пополняем каждую купюру рандомной долей от свободного места в банкомате
    if (currAmountBanknote(banknote) < 1000) {
        for (int i = 0; i < banknote.size() - 1; ++i) {
            banknote[i] += std::rand() % (1001 - currAmountBanknote(banknote));
            /* идея хорошая, но может уменьшить уже имеющееся количество купюр
            // исключаем вероятность переполнения одной купюрой свыше 400
            if (banknote[i] > 400) {
                banknote[i] = 200 + std::rand() % 200;
            }
            */
        }
        // для выравнивания суммы последнему номиналу "отдаем" всё оставшееся место
        banknote[5] += 1000 - currAmountBanknote(banknote);
    } else {
        std::cout << "The ATM is full!" << std::endl;
    }
}

// функция снятия наличных из банкомата
bool withdrawCash(std::vector<int> &banknote, const std::vector<int> &nominal, int &sum) {
    // для определения количества выдаваемых купюр
    int amount[6] = {0};

    std::cout << "Issuance of banknotes:" << std::endl;

    // цикл выдачи купюр
    for (int i = 0; sum > 0 && i < banknote.size(); ++i) {
        // определяем нужное количество
        amount[i] = sum / nominal[i];
        // проверяем необходимость выдачи такого номинала и его наличие
        if (amount[i] > 0) {
            if (banknote[i] != 0) {
                // последний рубеж. Если купюры по 100 не смогут выдать, значит - неудача
                if (i == 5 && amount[i] > banknote[i]) {
                    return false;
                }
                // проверяем, что сможем выдать столько купюр
                // если требуемое количество больше, то уменьшаем его выдачу
                while (amount[i] > banknote[i]) {
                    amount[i] -= 1;
                }
                // вычитаем запланированное на выдачу из суммы
                sum -= amount[i] * nominal[i];

            } else {
                // сбрасываем счетчик необходимого количества купюр
                amount[i] = 0;
            }
        }
    }

    //выводим в консоль количество выданных купюр
    for (int i = 0; i < banknote.size(); ++i) {
        // выдаем купюры
        banknote[i] -= amount[i];
        std::cout << nominal[i] << " RUB -> " << amount[i] << " pieces" << std::endl;

    }


    return true;
}

// функция вывода имеющихся средств в консоль
void showCashes(const std::vector<int> &banknote, const std::vector<int> &nominal) {
    // украшения и вывод имеющихся средств на экран
    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Amount of money in an ATM: " << currSummBanknote(banknote, nominal) << " RUB" << std::endl;
    std::cout << std::endl;
    std::cout << "Banknotes left in the ATM:" << std::endl;
    for (int i = 0; i < banknote.size(); ++i) {
        std::cout <<  nominal[i] << " RUB -> " << banknote[i] << " pieces" << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;
}

// функция чтения данных из файла
bool readBinFile(const std::string &path, std::vector<int> &banknote) {
    // создаем поток на чтение
    std::ifstream file(path, std::ios::binary);
    // проверяем, что файл существует
    if (!file.is_open()) {
        // если нет, то просто выходим
        return false;
    }

    // если существует, то начинаем читать из него данные
    for (int i = 0; i < banknote.size(); ++i) {
        file.read((char *) &banknote[i], sizeof(banknote[i]));
    }
    file.close();
    // завершаем успехом
    return true;
}

// функция записи данных в бинарный файл
void writeBinFile(const std::string &path, std::vector<int> &banknote) {
    // создаем поток на запись
    std::ofstream file(path, std::ios::binary);
    // записываем данные
    for (int i = 0; i < banknote.size(); ++i) {
        file.write((char *) &banknote[i], sizeof(banknote[i]));
    }
    file.close();
}

int main() {
    // для правильной работы std::rand()
    std::srand(std::time(nullptr));

    // путь к файлу
    std::string path = "C:\\tutorial-data\\bank.bin";

    // вектор хранения номиналов банкнот
    std::vector<int> nominal = {5000, 2000, 1000, 500, 200, 100};
    // вектор хранения количества купюр в банкомате
    std::vector<int> banknote(6);

    // приветствие
    std::cout << "--->> This is a demonstration program of how an ATM works <<---" << std::endl;
    std::cout << std::endl;
    std::cout << "The program can work with old data and create new ones" << std::endl;
    std::cout << "Initializing the ATM... " << std::endl;
    std::cout << std::endl;

    // проверяем и читаем файл
    if (readBinFile(path, banknote)) {
        std::cout << "Data loaded successfully";
    } else {
        std::cout << "No recorded data found. Refill the ATM" << std::endl;
        // заполняем заново банкомат если пусто
        refillATM(banknote);
    }

    // основной цикл работы
    while (true) {
        // показываем содержимое банкомата
        showCashes(banknote, nominal);

        // символ на чтение действия
        char action;

        // краткая инструкция
        std::cout << "Input, what you want to do? " << std::endl;
        std::cout << "(\"+\" - refill ATM, \"-\" withdraw cash, \"0\" - exit)" << std::endl;
        std::cout << "-> ";
        if (!checkAction(action)) {
            continue;
        }

        // проверяем что выбрал пользователь
        if (action == '+') {
            // заполняем банкомат и по новой
            refillATM(banknote);
        } else if (action == '-') {
            // создаем переменную для ввода снимаемой суммы
            int sum;
            // проверяем возможность снятия суммы с контролем ввода данных
            do {
                std::cout << "Input the sum: " << std::endl;
            } while (!checkInput(sum));
            // пробуем снять введенную сумму
            if (!withdrawCash(banknote, nominal, sum)) {
                std::cout << "Sorry, the ATM can't withdraw such an amount" << std::endl;
            }
        } else if (action == '0') {
            // если ввели ноль, то выходим из цикла
            break;
        }
    }

    // записываем данные в файл
    writeBinFile(path, banknote);
    // рассказываем об успехе
    std::cout << "Data written successfully" << std::endl;
  
    return 0;
}
