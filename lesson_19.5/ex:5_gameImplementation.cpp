#include <iostream>
#include <fstream>
#include <limits>
#include <string>

// функция проверки введенных данных
int checkInput () {
    while (true) {
        int value;
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Incorrect data" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Try again ->";
        }
        else {
            return value;
        }
    }
}

// функция вывода инструкции
void showInstruction () {
    std::cout << ">>>> Short instructions <<<<" << std::endl;
    std::cout << std::endl;
    std::cout << "You need to prepare 13 questions and answers." << std::endl;
    std::cout << "Write the questions separately in the \"Q#.txt\" files." << std::endl;
    std::cout << "Add the answers in the \"A#.txt\" file." << std::endl;
    std::cout << "Where # is the question/answer number." << std::endl;
    std::cout << "For example: \"Q12.txt\", \"A12.txt\"" << std::endl;
    std::cout << "Answers should consist of only one word" << std::endl;
    std::cout << "And place them in one folder." << std::endl;
    std::cout << std::endl;
    std::cout << "I wish you a good game!" << std::endl;
    std::cout << std::endl;
}

// функция создания пути к вопросам/ответам
std::string createPath (const std::string &path, const char &type, const int &index) {
    return path + type + std::to_string(index) + ".txt";
}

// функция опробования открытия файла по введеному пути
bool checkFile (const std::string &path) {
    std::ifstream stream;
    stream.open(path);
    if (stream.is_open()) {
        stream.close();
        return true;
    }
    stream.close();
    return false;
}

// функция проверки наличия файлов по введенному пути
bool checkContent (const std::string &path) {
    std::string tmpPath;
    for (int i = 1; i <= 13; ++i) {
        tmpPath = createPath(path, 'Q', i);
        if (!checkFile(tmpPath)) {
            return false;
        }
    }
    for (int i = 1; i <= 13; ++i) {
        tmpPath = createPath(path, 'A', i);
        if (!checkFile(tmpPath)) {
            return false;
        }
    }
    std::cout << "LOG: Valid files and path to them" << std::endl << std::endl;
    return true;
}

// функция поиска играющего сектора
int createIndex (bool sector[], int &index,const int &offset) {
    // считаем наше смещение
    index += offset;

    // проверяем, что не вышли за рамки 13го сектора
    if (index > 13) {
        index %= 13;
        if (index == 0) {
            index = 1;
        }
    }

    // проверяем что указанный сектор не играл
    if (!sector[index - 1]) {
        sector[index-1] = true;
        return index;
    }

    // если сектор оказался пустым идем дальше по порядку
    for (int i = index; i <= 13; ++i ) {
        // в случае выхода за границы сектора возвращаемся к первому
        if (i >= 13) {
            i = 0;
        }
        if (!sector[i]) {
            sector[i] = true;
            return i + 1;
        }
    }
}

// функция игры по сектору
void playSector(const std::string &path, const int &index, int &scoreP, int &scoreS) {
    std::string pathQues, pathAnsw;

    // Выводим вопрос в консоль
    pathQues = createPath(path, 'Q', index);
    std::ifstream stream;
    stream.open(pathQues, std::ios::binary);

    std::cout << "Attention, question: \n\"";
    while (!stream.eof()) {
        char buffer[20] = {0};
        stream.read(buffer, sizeof(buffer) - 1);
        std::cout << buffer;

    }
    std::cout << "\"" << std::endl;
    stream.close();

    // "достаем" вопрос из фала
    std::string rightAnswer = "";
    std::string answer;
    pathAnsw = createPath(path, 'A', index);
    stream.open(pathAnsw);
    stream >> rightAnswer;
    stream.close();

    // Предлагаем ввести свой ответ
    std::cout << "Dear players, please enter your answer: \n-> ";
    std::cin >> answer;

    // сравниваем ответы и выводим результат с присвоением очков
    if (answer == rightAnswer) {
        std::cout << "Correct answer! Points are added to players." << std::endl;
        scoreP += 1;
    } else {
        std::cout << "The answer is incorrect! The point goes to the spectators." << std::endl;
        std::cout << "Right answer: " << rightAnswer << std::endl;
        scoreS += 1;
    }
}

int main() {

    // индекс играющего сектора
    int index = 1;
    // имитация наличия сектора
    bool sector[13] = {0};
    // путь к вопросам и ответам
    std::string path = "1";
    std::ifstream game;

    std::cout << "--- A program simulating the TV show \"What? Where? When?\" ---" << std::endl << std::endl;
    std::cout << "You will have to act as Player" << std::endl;
    std::cout << "Your opponent will be ordinary Spectators." << std::endl;
    std::cout << "Let's play!" << std::endl << std::endl;

    // повторение окна начала игры с возможностью вывода инструкции
    while (true) {
        std::cout << "Input the path to directory with Q&A:" << std::endl;
        std::cout << "If you need instructions, input \"1\"" << std::endl;
        std::cout << "-> ";
        std::cin >> path;

        if (path == "1") {
            showInstruction();
            continue;
        }
        if (checkContent(path)) {
            std::cout << "*** The game begins! ***" << std::endl << std::endl;
            break;
        }
        std::cout << "Invalid path or files doesn't exist" << std::endl << std::endl;
    }

    // переменные для счета игры
    int players = 0;
    int spectators = 0;

    // цикл игры
    while (players < 6 && spectators < 6) {
        std::cout << "Input the offset -> ";
        // вводим офсет с контролем ввода
        int offset = checkInput();
        
        // определяем индекс сектора с имеющимся вопросом
        index = createIndex(sector, index, offset);

        // играем по введенному сектору
        playSector(path, index, players, spectators);

        // результат раунда
        std::cout << std::endl;
        std::cout << "Round results: " << std::endl;
        std::cout << "Player - " << players << " : " << spectators << " - Spectators" << std::endl;
    }

    // результат игры
    std::cout << std::endl;
    std::cout << "The game is over! The " <<
        (players == 6? "Player" : "Spectators") << " are the winners." << std::endl;
  
    return 0;
}
