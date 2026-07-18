#ifndef REMOTECONTROLLER_H
#define REMOTECONTROLLER_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QString>

// максимальное количество каналов
#define CHANEL_MAX_NUMBER 234

// создаем класс окна
class RemoteControllerMainWindow : public QMainWindow
{
    // обязательное поле
    Q_OBJECT

public:

    // констркутор класса
    RemoteControllerMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {}

    // определяем указатели на поля вывода информации
    QLineEdit* editPower = nullptr;
    QLineEdit* editChanel = nullptr;
    // определяем указатель но уровень громкости
    QProgressBar* progressVolume = nullptr;

    // метод высставления уровня громкости
    void setVolume(int level);
    // метод установки канала
    void setChanel();

public slots:

    // методы/слоты дейтсвия кнопок
    void add0();
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
    void powerChange();
    void muteChange();
    void nextChanel();
    void prevChanel();
    void volumeUp();
    void volumeDown();
    void isOk();



private:

    // поля класса
    // текущий канад
    int currentChanel = 0;
    // флаг включенного положения
    bool turnedOn = false;
    // флаг отключения звука
    bool isMuted = false;
    // текущий уровень громкости
    int volumeLevel = 0;
    // флаг ввода номера канала
    bool inputChanelNumber = false;
};



#endif // REMOTECONTROLLER_H
