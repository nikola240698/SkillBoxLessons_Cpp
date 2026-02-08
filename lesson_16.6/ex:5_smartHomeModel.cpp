#include <iostream>
#include <sstream>

// перечисления переключателей
enum switches {
    HEATER              = 1,
    CONDITIONER         = 2,
    HEATER_PIPE_WATER   = 4,
    LIGHT_OUTSIDE       = 8,
    LIGHT_INSIDE        = 16

};

// глобальная переменная времени
int g_time = 0;

// функция определения времени в 24 формате
int getTimeNow() {
    if (g_time > 23) {
        return g_time % 24;
    }
    return g_time;
}

void createMask(const std::string &buffer, int &bitMask) {

    int tempIns, tempOuts;
    std::string isMove, isLight;

    // парсим строку в данные
    std::stringstream buffer_stream(buffer);
    buffer_stream >> tempIns >> tempOuts >> isMove >> isLight;

    // перевод состояний в булевы значения
    bool boolMove = isMove == "yes";
    bool boolLight = isLight == "on";

    // проверяем температуру внутри здания
    // условие включения обогрева
    if (tempIns < 22 && !(bitMask & HEATER)) {
        bitMask |= HEATER;
        std::cout << "Heater ON" << std::endl;
    } else if (tempIns > 25 && bitMask & HEATER) {
        bitMask &= ~HEATER;
        std::cout << "Heater OFF" << std::endl;
    }

    // условие включения кондиционера
    if (tempIns >= 30 && !(bitMask & CONDITIONER)) {
        bitMask |= CONDITIONER;
        std::cout << "Conditioner ON" << std::endl;
    } else if (tempIns <= 25 && bitMask & CONDITIONER) {
        bitMask &= ~CONDITIONER;
        std::cout << "Conditioner OFF" << std::endl;
    }

    // проверяем температуру снаружи для включения обогрева труб
    if (tempOuts < 0 && !(bitMask & HEATER_PIPE_WATER)) {
        bitMask |= HEATER_PIPE_WATER;
        std::cout << "Water pipe heater ON" << std::endl;
    } else if (tempOuts > 5 && bitMask & HEATER_PIPE_WATER) {
        bitMask &= ~HEATER_PIPE_WATER;
        std::cout << "Water pipe heater OFF" << std::endl;
    }

    // проверяем наличие движения и время для включения внеш.освещения
    if (boolMove && (getTimeNow() >= 16 || getTimeNow() < 5)) {
        if (!(bitMask & LIGHT_OUTSIDE)) {
            bitMask |= LIGHT_OUTSIDE;
            std::cout << "Lights outside ON" << std::endl;
        }
    } else {
        if (bitMask & LIGHT_OUTSIDE) {
            bitMask &= ~LIGHT_OUTSIDE;
            std::cout << "Lights outside OFF" << std::endl;
        }
    }

    // проверяем условия освещения внутри
    // убеждаемся, что свет включен
    if (boolLight) {
        int lightTemp = 5000;

        // проверяем условия плавного снижения температуры света
        if (getTimeNow() >= 16) {
            if (getTimeNow() >= 20) {
                lightTemp = 2700;
            } else {
                lightTemp = 5000 - 575 * (getTimeNow() - 16);
            }
        }

        // проверяем условие включения света
        if (!(bitMask & LIGHT_INSIDE)) {
            bitMask |= LIGHT_INSIDE;
            std::cout << "Lights inside ON" << std::endl;

        }
        // выводим сообщение температуры света
        std::cout << "Color temperature " << lightTemp << "K" << std::endl;

    // отключаем свет
    } else if (bitMask & LIGHT_INSIDE) {
        bitMask &= ~LIGHT_INSIDE;
        std::cout << "Lights inside OFF" << std::endl;
    }
}

// функция переноса нынешних состояний в прошедшие
void swapMask(int arr[]) {
    arr[0] = arr[1];
}

int main() {

    int bitMask = 0;
    std::string buffer;

    std::cout << "\t---------- Smart Home Model ----------" << std::endl;
    std::cout << std::endl;
    
    // цикл работы смарт-системы на два дня
    while (g_time < 48) {
        std::cout << "Time now " << getTimeNow() << ":00" << std::endl;

        std::cout << "Input the following information:" << std::endl;
        std::cout << "Temperature inside, temperature outside, movement, lights:" << std::endl;

        std::getline(std::cin, buffer);
        
        // создаем битовую маску и производим операции с выключателями
        createMask(buffer, bitMask);
        
        std::cout << std::endl;
        std::cout << std::endl;
        
        // перематываем час
        g_time++;
    }

    std::cout << "Two days have passed..." << std::endl;

    return 0;
}
