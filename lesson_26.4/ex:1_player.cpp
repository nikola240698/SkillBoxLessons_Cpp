#include <iostream>
#include <ctime>
#include <utility>
#include <vector>
#include <string>

// класс для трека
class Track {

    // переменные класса
    std::string title;
    std::tm creationDate;
    int durationSec;

public:
    // инициализация параметров класса через двоеточие (для const переменных только так)
    Track(std::string  title, const std::tm& date, const int& duration)
    // CLion предложил метод std::move для быстроты и простоты работы сос троками
        : title(std::move(title)), creationDate(date), durationSec(duration) {}

    // получаем название файла
    std::string getTitle() {
        return title;
    }

    // информация о треке
    // const в конце, чтобы запретить методу изменять "тело" объекта
    void showInfo() const {
        std::cout << "Title: " <<  title << std::endl;
        std::cout << "Date of create: " << creationDate.tm_mday << "/"
            << creationDate.tm_mon + 1 << "/"
            << creationDate.tm_year + 1900 << std::endl;
        std::cout << "Track duration: " << durationSec / 60 << ":" << durationSec % 60 << std::endl;
        std::cout << std::endl;
    }

    // метод для удобного создания даты трека
    static std::tm compactDate(const int& year, const int& month, const int& day) {
        std::tm date{};
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        return date;
    }
};

// класс для проигрывателя
class Player {

    // переменные класса
    std::vector<Track> tracks;
    
    bool isPlayed = false;
    bool isPaused = false;

public:
    // добавляем трек в список
    void addTrack(const Track& track) {
        tracks.push_back(track);
    }

    // выводим список треков
    void showTracks() {
        // проверяем что список не пуст
        if (tracks.empty()) {
            std::cout << "There is no tracks" << std::endl;
            return;
        }

        // выводим список треков
        std::cout << "Tracks list: " << std::endl;
        for (int i = 0; i < tracks.size(); ++i) {
            std::cout << i + 1 << " - " << tracks[i].getTitle() << std::endl;
        }
    }

    // метод начала запуска трека
    void play() {
        // проверяем, что нет проигрывающегося или на паузе трека
        if (isPlayed && !isPaused) {
            std::cout << "The track is already playing" << std::endl;
            return;
        }
        // проверяем, если трек на паузе
        if (isPlayed && isPaused) {
            isPaused = false;
            std::cout << "The track continues to play" << std::endl;
            return;
        }
        // получаем у пользователя название трека
        std::string title;
        std::cout << "Input the title of the track -> ";
        std::getline(std::cin, title);
        // запускаем трек по введенному названию
        startPlay(getIndex(title));
    }

    // метод запуска трека
    void startPlay(const int& index) {
        // проверяем, что индекс корректен
        if (index < 0 || index >= tracks.size()) {
            std::cout << "Incorrect index" << std::endl;
            return;
        }
        
        // меняем состояния
        isPlayed = true;
        isPaused = false;       
        
        // выводим информацию о треке
        std::cout << "Play track: " << std::endl;
        tracks[index].showInfo();
    }

    // метод получения индекса трека
    int getIndex(const std::string& title) {
        for (int i = 0; i < tracks.size(); ++i) {
            if (title == tracks[i].getTitle()) {
                return i;
            }
        }
        std::cout << "There is no track with this title" << std::endl;
        return -1;
    }

    // метод постановки на паузу
    void pause() {
        if (!isPlayed) {
            std::cout << "There is nothing playing right now" << std::endl;
            return;
        }

        if (!isPaused) {
            isPaused = true;
            std::cout << "Pause" << std::endl;
        }

    }

    // метод остановки трека
    void stop() {
        if (!isPlayed) {
            std::cout << "There is nothing playing right now" << std::endl;
            return;
        }

        if (isPlayed || isPaused) {
            isPlayed = false;
            isPaused = false;
            std::cout << "Stop" << std::endl;
        }
    }

    // метод следующего трека в автоматике
    void next() {
        if (tracks.empty()) {
            std::cout << "There is no any tracks" << std::endl;
            return;
        }

        // воспроизводим рандомный другой трек
        int randInd = std::rand() % tracks.size();
        startPlay(randInd);
    }

    // список команд
    static void commandList() {
        std::cout << std::endl;
        std::cout << "---- List of available command ----" << std::endl;
        std::cout << "info - show command list" << std::endl;
        std::cout << "list - show tracks" << std::endl;
        std::cout << "play - play the track" << std::endl;
        std::cout << "pause - puase" << std::endl;
        std::cout << "stop - stop the playing" << std::endl;
        std::cout << "next - next random track" << std::endl;
        std::cout << "exit - exit the player" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
};

int main() {
    // для реального рандома
    std::srand(std::time(nullptr));

    Player* player = new Player;

    // добавляем треки в список
    player->addTrack(Track("Song 1", Track::compactDate(2021, 5, 20), 210));
    player->addTrack(Track("Song 2", Track::compactDate(2016, 9, 15), 260));
    player->addTrack(Track("Song 3", Track::compactDate(2018, 4, 7), 325));
    player->addTrack(Track("Song 4", Track::compactDate(2023, 10, 11), 278));
    player->addTrack(Track("Song 5", Track::compactDate(2010, 3, 17), 317));

    // строка для ввода команд и из список
    std::string command;
    Player::commandList();

    while (true) {
        std::cout << "Input the command ->";
        std::getline(std::cin, command);

        if (command == "list") {
            player->showTracks();
        } else if (command == "info") {
            Player::commandList();
        } else if (command == "play") {
            player->play();
        } else if (command == "pause") {
            player->pause();
        } else if (command == "stop") {
            player->stop();
        } else if (command == "next") {
            player->next();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Incorrecct command" << std::endl;
        }
    }

    delete player;
    return 0;
}
