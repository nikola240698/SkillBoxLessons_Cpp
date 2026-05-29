#include <iostream>
#include <string>
#include <map>

int main() {
    
    // так как std::map не может хранить одинаковые копии
    // то будем в значениях ключей-фамилий будем хранить их количество в очереди
    // и либо уменьшать значение при вызове, либо удалять запись если она одна

    std::cout << "A queue simulator program at the reception desk" << std::endl;
    std::cout << "Enter your last name to be added to the queue" << std::endl;
    std::cout << "Or the word Next to display the first person in the queue" << std::endl;
    std::cout << "Input -1 to exit the program" << std::endl;
    std::cout << std::endl;

    std::map<std::string, int> registry;
    std::string request;

    while (true) {
        std::cout << "-> ";
        std::cin >> request;

        // условие выхода из программы
        if (request == "-1") {
            break;
        }

        // проверяем что ввел пользователь      
        if (request == "Next") {
            // проверяем, что не пустая очередь
            if (registry.empty()) {
                std::cout<< "The queue is empty" << std::endl;
            } else {
                // итератор на первый элемент
                std::map<std::string, int>::iterator it = registry.begin();
                std::cout << it->first << std::endl;
                // проверяем, что фамилий несколько
                if (it->second > 1) {
                    // уменьшаем значение
                    registry[it->first] = it->second - 1;
                } else {
                    // удаляем запись, если она одна
                    registry.erase(it->first);
                }
            }
        } else {
            // проверяем, что фамилия уже есть
            if (registry.find(request) != registry.end()) {
                registry[request] = registry.find(request)->second + 1;
            } else {
                registry.insert(std::pair<std::string, int>(request, 1));
            }
        }
    }

    return 0;
}
