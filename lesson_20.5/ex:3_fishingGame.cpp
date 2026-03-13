#include <iostream>
#include <fstream>

// проверяем, что выбранная рыба есть в данном водоеме
bool checkFish(std::ifstream &stream, const std::string &haul) {
    // для записи рыбы из списка
    std::string fish;
    // перемещаемся в начало файла
    stream.seekg(0);
    // проверяем наличие выбранной рыбы
    while (!stream.eof()) {
        stream >> fish;
        if (fish == haul) {
            return true;
        }
    }
    // ругаемся
    std::cout << "There are no " << haul << " in this river" << std::endl;
    return false;
}

// функция ловли определенной рыбы
int catchFish(std::ifstream &river, std::ofstream &basket, const std::string &haul) {
    // счетчик пойманной рыбы
    int counter = 0;
    // для записи рыбы из списка
    std::string fish;
    // перемещаемся в начало файла для чтения рыб
    river.seekg(0);
    // "ловим" выбранную рыбу
    while (!river.eof()) {
        river >> fish;
        if (fish == haul) {
            basket << fish << std::endl;
            counter += 1;
        }
    }
    return counter;
}

int main() {
    // потоки списка рыб и корзины
    std::ifstream river;
    std::ofstream basket;

    // путь к файлу
    std::string path;

    std::cout << "--<<<-- This is a mini-game \"Fishing\"! -->>>--" << std::endl;
    std::cout << std::endl;
    std::cout << "You will be in the role of a fisherman" << std::endl;
    std::cout << "who catches a certain type of fish!" << std::endl;
    std::cout << std::endl;

    // цикл проверки правильного ввода пути к файлам
    while (true) {
        std::cout << "Input the path to the folder with files:" << std::endl;
        std::cout << "-> ";
        std::cin >> path;

        river.open(path + "river.txt");
        if (river.is_open()) {
            break;
        }
        std::cout << "Incorrect path!" << std::endl;
    }

    // вводимое название рыбы для ловли
    std::string haul;

    // цикл проверки наличия рыбы в реке
    while (true) {
        std::cout << "Input what type of fish you are going to catch?" << std::endl;
        std::cout << "-> ";
        std::cin >> haul;
        if (checkFish(river, haul)) {
            break;
        }
        std::cout << std::endl;
    }
    
    // открываем файл для записи корзины
    basket.open(path + "basket.txt", std::ios::app);

    // ловим рыбу
    std::cout << "The fishing is over!" << std::endl;
    std::cout << "You caught " << catchFish(river, basket, haul) << " fish" << std::endl;

    // закрываем файлы
    river.close();
    basket.close();

    return 0;
}
