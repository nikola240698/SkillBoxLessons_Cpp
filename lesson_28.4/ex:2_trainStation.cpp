#include <iostream>
#include <mutex>
#include <thread>

// мютекс блокировки консоли
std::mutex consoleMutex;
// мютекс блокировки станции
std::mutex stationMutex;

// функция запуска поезда
void trainMovement(char name, int speed) {
    // блочим консоль
    consoleMutex.lock();
    // отправляем поезд на станцию
    std::cout << "The train " << name << " departed for the next station" << std::endl;
    // снимаем блок консоли
    consoleMutex.unlock();
    // запускаем в путь поезд с задержкой времени прибытия
    std::this_thread::sleep_for(std::chrono::seconds(speed));
    // цикл проверки прибытия и свободного места
    while (true) {
        // проверяем, что станция свободна
        if (stationMutex.try_lock()) {
            // если свободно, то блокируем станцию и консоль
            consoleMutex.lock();
            // выводим информацию о поезде в консоль
            std::cout << "The train "<< name << " has arrived and is awaiting departure" << std::endl;
            std::cout << "Input \"depart\" to send the train on its way" << std::endl;
            // снимаем блок консоли
            consoleMutex.unlock();
            // строка для команды отправки
            std::string command;
            // цикл ожидания ввода правильной команды
            do {
                std::cout << "->";
                std::cin >> command;
            } while (command != "depart");
            // в случае отправки поезда снимаем блокировку станции и прерываем цикл
            stationMutex.unlock();
            break;
        } else {
            // если место занято, то каждые 3 секунды присылаем сообщение, что поезд ждет места свободного
            consoleMutex.lock();
            std::cout << "The train " << name << " has arrived and is waiting for a free seat" << std::endl;
            consoleMutex.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    }
    // если поезд отправился, то сообщаем об этом
    consoleMutex.lock();
    std::cout << "The " << name << " train departed from the station" << std::endl;
    consoleMutex.unlock();
}

// функция ввода Int с проверкой
int inputInt() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Incorrect data. Try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}

int main() {
    // вводим параметры от пользователя
    std::cout << "Input the travel time for train A ->";
    int timeA = inputInt();
    std::cout << "Input the travel time for train B ->";
    int timeB = inputInt();
    std::cout << "Input the travel time for train C ->";
    int timeC = inputInt();
    // запускаем поезда
    std::thread trainA(trainMovement, 'A', timeA);
    std::thread trainB(trainMovement, 'B', timeB);
    std::thread trainC(trainMovement, 'C', timeC);
    // подключаем наши потоки
    trainA.join();
    trainB.join();
    trainC.join();
    // финальна фраза
    std::cout << "All trains is departed from the station" << std::endl;

    return 0;
}
