#include <iostream>
#include <fstream>
#include <vector>

int maxValue (std::vector<int> &vec) {
    int max = vec[0];
    int position = 0;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] > max) {
            max = vec[i];
            position = i;
        }
    }
    return position;
}

int main() {

    std::vector<std::string> firstName;
    std::vector<std::string> lastName;
    std::vector<int> payment;
    std::vector<std::string> date;

    std::string nameF;
    std::string nameL;
    int money;
    std::string when;

    int payemntsAmount = 0;

    std::cout << "Program for reading information from a payroll statement" << std::endl;
    std::cout << std::endl;

    std::ifstream statement;

    while (true) {

        std::string path;
        std::cout << "Input the path of the file: ";
        std::cin >> path;


        statement.open(path);

        if (statement.is_open()) {
            std::cout << "The file was opened successfully." << std::endl;
            break;
        }
        std::cout << "Failed to open file" << std::endl;

    }

    std::cout << "Reading the file..." << std::endl << std::endl;

    while (!statement.eof()) {
        statement >> nameF >> nameL >> money >> when;
        firstName.push_back(nameF);
        lastName.push_back(nameL);
        payment.push_back(money);
        date.push_back(when);
        payemntsAmount += money;
    }
  
    statement.close();

    int position = maxValue(payment);

    std::cout << "Amount of payments = " << payemntsAmount << std::endl;
    std::cout << "Made the largest payments:" << std::endl;
    std::cout << firstName[position] << " " << lastName[position] << " = "
        << payment[position] << std::endl;

    return 0;
}
