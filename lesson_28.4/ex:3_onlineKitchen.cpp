#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <ctime>

// вектор списка еды на доставку
std::vector<std::string> readyFood;
// вектор записи онлайн заказов
std::vector<std::string> onlineOrder;
// мютекс занятости кухни
std::mutex kitchenMutex;
// мютекс записи в вектора заказов
std::mutex orderMutex;
// мютекс вывода в консоль
std::mutex consoleMutex;

// перечисления еды
enum Food {
    PIZZA,
    SOUP,
    STEAK,
    SALAD,
    SUSHI
};

// метод получения названия еды (только сейчас понял, что \" можно было тут вставить
std::string getFood(const int index) {
    switch (index) {
        case PIZZA: return "pizza";
        case SOUP: return "soup";
        case STEAK: return "steak";
        case SALAD: return "salad";
        case SUSHI: return "sushi";
            default: return "";
    }
}

// метод создания онлайн заказа
void createOrder() {
    std::srand(std::time(nullptr));
    // переменная времени заказа
    int orderTime = 0;
    // переменная рандомного выбора еды
    int foodInd = 0;
    // цикл работы онлайн заказов
    while (true) {
        // рандомно выбираем название блюда
        foodInd = std::rand() % 5;
        // блокируем консоль и запись в вектор
        orderMutex.lock();
        // записываем заказ в веткор заказов
        onlineOrder.push_back(getFood(foodInd));
        // выводим информацию
        consoleMutex.lock();
        std::cout << "There is new online order - \"" << getFood(foodInd) << "\"" << std::endl;
        consoleMutex.unlock();
        // снимаем блокировку
        orderMutex.unlock();
        // рандомно создаем время появления заказа
        orderTime = 5 + std::rand() % 6;         // 5 + rand() % (10 - 5 + 1)
        // ожидаем заказа
        std::this_thread::sleep_for(std::chrono::seconds(orderTime));
    }
}

// метод работы официанта
void officiantWork() {
    std::srand(std::time(nullptr));
    int kitchenTime = 0;
    // цикл работы официанта
    while (true) {
        // проверяем, что есть онлайн заказ
        if (!onlineOrder.empty()) {
            // проверяем, что кухня свободная
            if (kitchenMutex.try_lock()) {
                // сообщаем в консоль
                consoleMutex.lock();
                std::cout << "The waiter took the order - \"" << onlineOrder[0]
                    << "\" and passed it on to the kitchen" << std::endl;
                consoleMutex.unlock();
                // создаем время работы кухни
                kitchenTime = 5 + std::rand() % 11;
                // кухня работает
                std::this_thread::sleep_for(std::chrono::seconds(kitchenTime));
                // по готовности выдаем блюдо на доставку
                orderMutex.lock();
                readyFood.push_back(onlineOrder[0]);
                orderMutex.unlock();
                // выводим информацию в консоль
                consoleMutex.lock();
                std::cout << "The \"" << onlineOrder[0] <<"\" has been sent for delivery" << std::endl;
                consoleMutex.unlock();
                // удаляем с онлайн заказа блюдо
                onlineOrder.erase(onlineOrder.begin());
                // говорим о свободности кухни
                kitchenMutex.unlock();
            } else {
                // иначе ждем секунду
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        } else {
            // иначе ждем секунду
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

// функция работы курьера
void courierWork() {
    // общее число доставок
    int totalDeliver = 0;
    // цикл работы курьера
    while (true) {
        // его ожидание в 30 секунд
        std::this_thread::sleep_for(std::chrono::seconds(30));
        // переменная разовых доставок
        int deliverCount = 0;
        // забираем все доступные зказы
        orderMutex.lock();
        for (int i = 0; i < readyFood.size(); ++i) {
            ++deliverCount;
        }
        // удаляем из списка их
        readyFood.clear();
        orderMutex.unlock();
        // суммируем к общим доставкам
        totalDeliver +=deliverCount;
        // и выводим информацию в консоль
        consoleMutex.lock();
        std::cout << "The courier delivered " << deliverCount << " orders" << std::endl;
        consoleMutex.unlock();
        // условие завершения программы
        if (totalDeliver >= 10) {
            std::cout << "Work is Done!" << std::endl;
            return;
        }
    }
}

int main() {

    std::srand(std::time(nullptr));
    // создаем потоки работы кухни ресторана
    std::thread order(createOrder);
    std::thread officiant(officiantWork);
    std::thread courier(courierWork);

    // ставим на очередь ожидание выполнения потока курьера
    // так как условие выхода из программы только у него
    courier.join();
    // при завершении программы отвязываем остальные потоки, ибо иначе будет ошибка
    if (order.joinable()) {
        order.detach();
    }
    if (officiant.joinable()) {
        officiant.detach();
    }
    return 0;
}
