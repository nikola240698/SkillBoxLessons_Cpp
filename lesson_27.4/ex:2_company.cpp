#include <iostream>
#include <limits>
#include <vector>

enum Task {
    A,
    B,
    C
};

std::string taskToString(const Task task) {
    switch (task) {
        case A: return "A";
        case B: return "B";
        case C: return "C";

        default: return "";
    }
}

// класс рабочего
class Worker {
    // переменные класса
    std::string name = "unknow";
    bool isBusy = false;
    Task task;

public:
    // инициализация переменных
    Worker(const std::string& inName) : name(inName) {}

    // геттер занятости рабочего
    bool getIsBusy() const {
        return isBusy;
    }

    // сеттер задачи рабочему
    void setTask(const Task inTask) {
        this->task = inTask;
        isBusy = true;

        std::cout << name << " received a task " << taskToString(inTask) << std::endl;
    }
};

// класс менеджера
class Manager {
    // переменные класса
    std::string name = "Unknown";
    int number = 0;
    std::vector<Worker> workers;

    // метод счетчика свободных рабочих в команде
    int freeWorkers() const {
        int count = 0;
        for (int i = 0; i < workers.size(); ++i) {
            if (!workers[i].getIsBusy()) {
                ++count;
            }
        }
        return count;
    }

public:
    // инициализация переменных класса
    Manager(const std::string& inName, const int inNumber, const int workerCount)
        : name(inName), number(inNumber) {
        for (int i = 0; i < workerCount; ++i) {
            workers.push_back("Worker " + std::to_string(i + 1));
        }
    }

    // метод выдачи команды рабочим
    void setCommand(const int commandNumber) {
        std::cout << std::endl;
        std::cout << name << " received a command from director" << std::endl;
        // проверяем наличие свободных рабочих
        if (!freeWorkers()) {
            std::cout << "There are not free workers" << std::endl;
            return;
        }
        // генерируем рандом
        std::srand(commandNumber + number);
        // рандомно выбираем количество задач в зависимости от количества свободных рабочих
        int taskCount = std::rand() % freeWorkers() + 1;
        // выдаем задачи рабочим
        std::cout << name << " distributes tasks " << taskCount << std::endl;
        Task giveTask = {};
        for (int i = 0; i < taskCount; ++i) {
            // получаем рандомно задачу
            int taskNum = std::rand() % 3;
            switch (taskNum) {
                case 0: giveTask = A;
                    break;
                case 1: giveTask = B;
                    break;
                case 2: giveTask = C;
                    break;
            }
            // выдаем её рабочему
            for (int j = 0; j < workers.size(); ++j) {
                if (!workers[j].getIsBusy()) {
                    workers[j].setTask(giveTask);
                    break;
                }
            }
        }
    }

    // метод проверки занятости рабочих
    bool allWorkersBusy() const {
        for (int i = 0; i < workers.size(); ++i) {
            if (!workers[i].getIsBusy()) {
                return false;
            }
        }
        return true;
    }
};

// Класс директора компании
class Company {
    // поля класса
    std::string name = "Unknown";
    std::vector<Manager> managers;

public:
    // инициализация полей класса
    Company(const std::string& inName, const int inTeamCount, const int inWorkersInTeam)
        : name(inName) {
        for (int i = 0; i < inTeamCount; ++i) {
            managers.emplace_back("Manager " + std::to_string(i + 1), (i + 1), inWorkersInTeam);
        }
        std::cout << "The company have been created" << std::endl;
    }

    // метод выдачи задания менеджеру
    void giveCommand(const int command) {
        std::cout  << name << ",  company's director give the command " << command << std::endl;
        for (int i = 0; i < managers.size(); ++i) {
            managers[i].setCommand(command);
        }
    }

    // метод получения всех занятых работников
    bool allIsBusy() const {
        for (int i = 0; i < managers.size(); ++i) {
            if (!managers[i].allWorkersBusy()) {
                return false;
            }
        }
        return true;
    }
};

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
        break;
    }
    return value;
}

int main() {
    // запрашиваем начальные данные
    std::cout << "Input the number of team ->";
    int teamCount = inputInt();
    std::cout << "Input the number of workers in team ->";
    int workerPerTeam = inputInt();
    // создаем компанию
    Company* company = new Company("Mr. Lu", teamCount, workerPerTeam);
    // цикл выдачи задач
    while (!company->allIsBusy()) {
        // вводим идентификатор задачи
        std::cout << "Input the task ->";
        int task = inputInt();
        // выдаем задачу
        company->giveCommand(task);
    }
    // если все работники заняты
    std::cout << std::endl;
    std::cout << "All workers is busy" << std::endl;
    // удаляем компанию
    delete company;
    return 0;
}
