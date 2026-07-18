#include "remoteController.h"

// метод установки уровня громкости
void RemoteControllerMainWindow::setVolume(int level) {
    // устанавливем значение на progressBar
    progressVolume->valueChanged(level);
}

// метод установки канала
void RemoteControllerMainWindow::setChanel() {
    // выводим в текстовое поле текущий канал
    editChanel->setText(QString::number(currentChanel));
}

// метод ввода номера 0 для номера канала
void RemoteControllerMainWindow::add0()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "0");
    }
};

// метод ввода номера 1 для номера канала
void RemoteControllerMainWindow::add1()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "1");
    }
};

// метод ввода номера 2 для номера канала
void RemoteControllerMainWindow::add2()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "2");
    }
};

// метод ввода номера 3 для номера канала
void RemoteControllerMainWindow::add3()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "3");
    }
};

// метод ввода номера 4 для номера канала
void RemoteControllerMainWindow::add4()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "4");
    }
};

// метод ввода номера 5 для номера канала
void RemoteControllerMainWindow::add5()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "5");
    }
};

// метод ввода номера 6 для номера канала
void RemoteControllerMainWindow::add6()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "6");
    }
};

// метод ввода номера 7 для номера канала
void RemoteControllerMainWindow::add7()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "7");
    }
};

// метод ввода номера 8 для номера канала
void RemoteControllerMainWindow::add8()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "8");
    }
};

// метод ввода номера 9 для номера канала
void RemoteControllerMainWindow::add9()
{
    // проверяем, что включено устройство
    if(turnedOn)
    {
        // создаем строку набора номера
        QString chanelNumber = "";
        // проверяем, что уже начали вводить канал
        if(inputChanelNumber) {
            // получаем уже введеные цифры
            chanelNumber = editChanel->text();
        }
        // поднимаем флаг, что начинаем ввод номера
        inputChanelNumber = true;
        // вводим выводим в поле номер с добавленной цифрой
        editChanel->setText(chanelNumber += "9");
    }
};

// метод включения/выключения устройства
void RemoteControllerMainWindow::powerChange()
{
    // если уже включено
    if (turnedOn)
    {
        // выводим сообщение, что отключили
        editPower->setText("OFF");
        // меняем цвет текста
        editPower->setStyleSheet("color: red");
        // опускаем флаг
        turnedOn = false;
    // если устройство отключено
    } else
    {
        // выводим сообщение о включении
        editPower->setText("ON");
        // меняем цвет текста
        editPower->setStyleSheet("color: green");
        // поднимаем флаг
        turnedOn = true;
    }
};

// метод отключения/включения звука
void RemoteControllerMainWindow::muteChange()
{
    // проверяем, что устройство включено
    if (turnedOn)
    {
        // проверяем, что звук отключен
        if (isMuted)
        {
            // опускаем флаг
            isMuted = false;
            // вводим в progressBar уровень звука до отключения
            progressVolume->setValue(volumeLevel);
        // если звук включен
        } else {
            // поднимаем флаг
            isMuted = true;
            // запоминаем уровень громкости
            volumeLevel = progressVolume->value();
            // на progressBar сбрасываем уроень громкости
            progressVolume->setValue(0);
        }
    }
};

// метод переключения на следующий канал
void RemoteControllerMainWindow::nextChanel()
{
    // проверяем, что устройство включено
    if (turnedOn)
    {
        // увеличиваем номер канала на единицу
        ++currentChanel;
        // проверяем, что не вышли за границы
        if (currentChanel > CHANEL_MAX_NUMBER) {
            // корректируем выход за границы
            currentChanel = 0;
        }
        // выставляем канал
        setChanel();

    }
};

// метод переключения на предыдущий канал
void RemoteControllerMainWindow::prevChanel()
{
    // проверяем, что устройство включено
    if (turnedOn)
    {
        // уменьшаем номер канала на единицу
        --currentChanel;
        // проверяем, что не вышли за границы
        if (currentChanel < 0) {
            // корректируем выход за границы
            currentChanel = CHANEL_MAX_NUMBER;
        }
        // выставляем канал
        setChanel();

    }
};

// метод увеличивания громкости
void RemoteControllerMainWindow::volumeUp()
{
    // проверяем, что устройство включено
    if (turnedOn)
    {
        // умеличиваем уровень громкости
        volumeLevel += 10;
        // проверяем границы
        if (volumeLevel > 100)
            // корректируем при выходе за границы
            volumeLevel = 100;
        // устанавливаем уровень громкости в progressBar
        progressVolume->setValue(volumeLevel);
    }

};

// метод уменьшения громкости
void RemoteControllerMainWindow::volumeDown()
{
    // проверяем, что устройство включено
    if (turnedOn)
    {
        // уменьшаем уровень громкости
        volumeLevel -= 10;
        // проверяем допустимые границы
        if (volumeLevel < 0)
            // корректируем при выходе за границы
            volumeLevel = 0;
        // выстанваливаем уровень громкости в progressBar
        progressVolume->setValue(volumeLevel);
    }
};

// метод нажатия на кнопку Ок для ввода канала
void RemoteControllerMainWindow::isOk()
{
    // проверяем, что начали вводить номер канала
    if (inputChanelNumber) {
        // опускаем флаг ввода номера канала
        inputChanelNumber = false;
        // получаем номер канала конертируя его в Int
        // проверка не требуется, так как вводятся с кнопок
        int inputChanelInt = (editChanel->text()).toInt();
        // проверяем введенный номер на величину ввода
        if (inputChanelInt <0 || inputChanelInt > CHANEL_MAX_NUMBER)
        {
            // выводим сообщение о границах канала
            editChanel->setText("Only from 0 to " + QString::number(CHANEL_MAX_NUMBER) + " chanels");
        } else
        {
            // присваиваем новый номер текущему каналу
            currentChanel = inputChanelInt;
            // выводим выбраный канал
            setChanel();
        }
    }
};




















