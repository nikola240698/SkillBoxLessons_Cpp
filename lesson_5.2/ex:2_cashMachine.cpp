#include <iostream>

int main() {
    
    int moneyWithdraw;

    std::cout << "Программа для определение возможности снятия наличных в банкомате" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите сумму снятия";
    std:: cin >> moneyWithdraw;

    if (moneyWithdraw > 100000) std::cout << "Нельзя снимать более 100 000 рублей" << std::endl;
    else {
        if (moneyWithdraw % 100 == 0) std::cout << "Можете снять деньги" << std::endl;
        else std::cout << "Банкомат не сможет выдасть Вашу сумму" << std::endl;
    }
}
