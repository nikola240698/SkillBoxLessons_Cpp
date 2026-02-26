#include <iostream>
#include <fstream>
#include <vector>

// функция для поиска индекса строки с наибольшими выплатами
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

    std::vector<int> payment;    // вектор всех выплат

    // переменные для чтения данных с файла
    std::string nameF;
    std::string nameL;
    int money;
    std::string when;

    int payemntsAmount = 0;    // сумма всех выплат

    std::cout << "Program for reading information from a payroll statement" << std::endl;
    std::cout << std::endl;

    std::ifstream statement;    

    // пробуем открыть файл по введенному пути
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

    // читаем данные из файла
    while (!statement.eof()) {
        statement >> nameF >> nameL >> money >> when;
        payment.push_back(money);
        payemntsAmount += money;
    }

    // опеределяем индекс строки с максимальными выплатами
    int position = maxValue(payment);

    // перемещаемся в начало файла
    statement.seekg(0);

    // читаем до необходимой строки
    for (int i = 0; i <= position; ++i) {
        statement >> nameF >> nameL >> money >> when;
    }

    // выводим результат
    std::cout << "Amount of payments = " << payemntsAmount << std::endl;
    std::cout << "Made the largest payments:" << std::endl;
    std::cout << nameF << " " << nameL << " = "
        << money << std::endl;

    statement.close();    // закрываем файл
  
    return 0;
}
