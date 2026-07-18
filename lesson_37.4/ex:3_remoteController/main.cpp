#include "remoteController.h"
#include "ui_remoteController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // создаем приложение
    QApplication a(argc, argv);
    // создаем рабочее окно
    RemoteControllerMainWindow window(nullptr);

    // создаем наш пульт
    Ui_MainWindow remoteController;

    // отображаем пульт
    remoteController.setupUi(&window);

    // присваемаем поля вывода информации
    window.editPower = remoteController.editPower;
    window.editChanel = remoteController.editChanel;
    window.progressVolume = remoteController.progressVolume;

    // показываем окно
    window.show();

    return QApplication::exec();
}
