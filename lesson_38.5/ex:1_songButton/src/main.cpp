// подключаем необходимые библиотеки
#include <QFile>
#include <QApplication>

#include <QBuffer>
#include <QTemporaryFile>
#include <QMediaPlayer>
#include <QAudioOutput>

#include "ImageButton.h"

// главная функция
int main(int argc, char **argv)
{
    // создам приложение
    QApplication app(argc, argv);
    // создаем кнопку
    ImageButton redButton(nullptr);
    // указываем размеры кнопки
    redButton.setFixedSize(250, 250);
    // перемещаем кнопку
    redButton.move(1000, 400);

    // создаем проигрыватель
    QMediaPlayer *player = new QMediaPlayer;
    // создаем аудивыход (необходим в Qt6)
    QAudioOutput *audioOutput = new QAudioOutput;
    // назначаем проигрывателю аудио выход
    player->setAudioOutput(audioOutput);

    // берем аудио из файлов
    QFile resourceFile(":/media/song/click.wav");
    // проверяем, что открылся файл
    if (resourceFile.open(QIODevice::ReadOnly)) {
        // передаем ауио через буфер (иначе на Qt6 никак не заработало)
        QByteArray *soundData = new QByteArray(resourceFile.readAll());
        QBuffer *buffer = new QBuffer(soundData);
        buffer->open(QIODevice::ReadOnly);
        // Передаем как устройство ввода
        player->setSourceDevice(buffer);
    }

    // получаем сигнал от кнопки и при помощи лямбда-функции воспроизводим звук
    QObject::connect(&redButton, &QPushButton::clicked, [player](){player->play();});
    // показываем кнопку
    redButton.show();

    // исполняем приложение
    return app.exec();
}

