#include <iostream>
#include <map>
#include <thread>
#include <mutex>
#include <vector>

// макрос колиества пловцов
#define SWIMMER_COUNT 6

// глобальный мультимап для лидеров
std::multimap<double, std::string> leaderboard;
// глобальный мьютекс для контроля вывода в консоль
std::mutex leaderboard_access;

// функция запуска потока каждого пловца
void swimmerRace(const std::string &name, const double speed) {
    // местные переменные
    double distance = 0;
    int time = 1;
    // цикл заплыва пловца
    while (true) {
        // секундная задержка
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // проплываем дистанцию согласно времени и проверяем условие финиша
        distance += speed;
        if (distance >= 100) break;
        // мютексом закрываем доступ к консоли для других потоков
        leaderboard_access.lock();
        // выводим информацию о пловце
        std::cout << name << " swam " << distance << " m" << std::endl;
        std::cout << "==================================" << std::endl;
        // возвращаем доступ
        leaderboard_access.unlock();
        // отсчитываем время
        ++time;
    }
    // закрываем доступ к мультимапу другим потокам
    leaderboard_access.lock();
    // сообщаем о финише
    std::cout << name << " finished the swim with time " << time << std::endl;
    // производим запись в списки лидеров
    leaderboard.insert(std::make_pair(time, name));
    // открываем обратно доступ другим потокам
    leaderboard_access.unlock();
}

int main() {

    // вектор потоков
    std::vector<std::thread> pool;
    // мультимап списка пловцов
    std::multimap<double, std::string> swimmers;

    // цикл инициализации пловца
    for (int i = 0; i < SWIMMER_COUNT; ++i) {
        std::string name;
        std::cout << "Input the " << i + 1 << " swimmer name -> ";
        std::cin >> name;
        double speed;
        std::cout << "Input speed of " << name << " [m/s]-> ";
        std::cin >> speed;
        swimmers.insert(std::make_pair(speed, name));
    }

    // приветствие на стартовой
    std::cout << "There is all swimmers on the start!" << std::endl;

    // цикл запуска потоков для каждого пловца
    for (auto it = swimmers.begin(); it != swimmers.end(); ++it) {
        pool.emplace_back(swimmerRace, it->second, it->first);
    }

    // цикл ожидания завершения всех действующих потоков
    for (int i = 0; i < SWIMMER_COUNT; ++i) {
        if (pool[i].joinable()) {
            pool[i].join();
        }
    }

    std::cout << std::endl << "All swimmers finished the race!" << std::endl << std::endl;
    std::cout << "=============LEADERBOARD=============" << std::endl;

    // выводим список лидеров
    int place = 1;
    for (auto it = leaderboard.begin(); it != leaderboard.end(); ++it) {
        std::cout << place << " place: \"" << it->second << "\" with time "
            << it->first << " second" << std::endl;
        ++place;
    }

    return 0;
}
