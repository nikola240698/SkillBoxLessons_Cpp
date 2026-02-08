#include <iostream>
#include <cctype>

// перечисления ибит нот
enum note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

// проверка правильности введеного аккорда
bool checkChord(const std::string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]) || str[i] < '0' || str[i] > '6') {
            return false;
        }
    }
    return true;
};

// создаем битовую маску введенного аккорда
int createBitMask(const std::string &str) {
    int bitMask = 0;
    for (int i = 0; i < str.length(); i++) {
        int noteBit = 1 << (str[i] - '0');
        bitMask |= noteBit;
    }
    return bitMask;
}

// выводим на экран нужные ноты по аккорду
void showChord(const int &bitMask) {
    if (bitMask & DO) {
        std::cout << "DO ";
    }
    if (bitMask & RE) {
        std::cout << "RE ";
    }
    if (bitMask & MI) {
        std::cout << "MI ";
    }
    if (bitMask & FA) {
        std::cout << "FA ";
    }
    if (bitMask & SOL) {
        std::cout << "SOL ";
    }
    if (bitMask & LA) {
        std::cout << "LA ";
    }
    if (bitMask & SI) {
        std::cout << "SI ";
    }
    std::cout << std::endl;
}

int main() {

    std::string chord;

    std::cout << "\t\t---------- Program for chord learning! ---------- " << std::endl;
    std::cout << "Input the note numbers of the chord and the program will give you the notes" << std::endl;
    std::cout << "Note range from 0 to 6 inclusive" << std::endl;
    std::cout << std::endl;

    std::cout << "Input the accord: ";
    std::cin >> chord;

    // проверяем, что введены именно цифры от 0 до 7
    if (!checkChord(chord)) {
        std::cerr << "Incorrect data" << std::endl;
        return -1;
    }

    // создаем битовую маску
    int bitMask = createBitMask(chord);
    // выводим получившийся аккорд
    showChord(bitMask);

    return 0;
}
