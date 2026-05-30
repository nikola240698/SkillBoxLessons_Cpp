#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

// структура задачи
struct Task {
    std::time_t startT = 0;
    std::time_t endT = 0;
    std::string name;
    bool start = false;
    bool done = false;
};

// структура рабочего дня
struct WorkDay {
    std::vector<Task> tasks;
};

// функция завершения задачи
void stopTask(Task &task, WorkDay &workDay) {
    // убеждаемся, что задача была начата
    if (task.start && !task.done) {
        task.endT = std::time(nullptr);
        task.done = true;
        workDay.tasks.push_back(task);
        std::cout << "The current task is completed" << std::endl;
    } else {
        // если нет начатых задач
        std::cout << "There is no current task" << std::endl;
    }
}

// функция начала задачи
Task startTask(Task &task, WorkDay &workDay) {
    // проверяем, что задача уже запущена
    if (task.start && !task.done) {
        stopTask(task,workDay);
    }
    // начинаем новую задачу
    Task newTask;
    std::cout << "Input the name of the task -> ";
    std::cin >> newTask.name;
    newTask.startT = std::time(nullptr);
    newTask.start = true;
    std::cout << "The current task is created" << std::endl;
    return newTask;
}

// функция вывода статуса задач
void statusTask(WorkDay &workDay, Task &task) {
    // проверяем, что задач нет вообще
    if (workDay.tasks.size() == 0 && !task.start) {
        std::cout << "There is no task" << std::endl;
    } else {
        // если есть завершенные задачи, то выводим их список
        std::cout << "List of all tasks:" << std::endl;
        if (workDay.tasks.size() > 0) {
            // читаем вектор по порядку
            for (int i = 0; i < workDay.tasks.size(); ++i) {
                std::cout << "Task " << i + 1 << ": " << workDay.tasks[i].name << std::endl;
                // вычисляем время выполнения задачи
                time_t timeLeft = (time_t)std::difftime(workDay.tasks[i].endT, workDay.tasks[i].startT);
                std::tm* time = std::gmtime(&timeLeft);
                std::cout << "Time left: " << std::put_time(time, "%H:%M:%S") << std::endl;
            }
        }
        // если есть начатая задача
        if (!task.done) {
            std::cout << "Current task - " << task.name << std::endl;
            std::tm* startT = std::localtime(&task.startT);
            std::cout << "Start time - ";
            std::cout << asctime(startT) << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {

    std::cout << "A time tracking program" << std::endl;
    std::cout << "List of commands:" << std::endl;
    std::cout << "begin\t- start task" << std::endl;
    std::cout << "end\t- end task" << std::endl;
    std::cout << "status\t- status all tasks" << std::endl;
    std::cout << "exit\t- exit program" << std::endl;
    std::cout << std::endl;

    // строка для ввода команды
    std::string command;

    // рабочий день
    WorkDay workDay;
    // текущая задача
    Task task;

    // рабочий цикл
    while (true) {

        std::cout << "Input your command -> ";
        std::cin >> command;

        if(command == "begin") {
            task = startTask(task, workDay);
        } else if (command == "end") {
            stopTask(task, workDay);
        } else if (command == "status") {
            statusTask(workDay, task);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Incorrect command!" << std::endl;
        }
    }
    return 0;
}
