#include "calc.h"
#include "ui_calc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // создаем приложение
    QApplication a(argc, argv);
    // создаем рабочее окно
    CalcMainWindow window(nullptr);
    // создаем наш калькулятор
    Ui_MainWindow calc;
    // отображаем калькулятор
    calc.setupUi(&window);
    // присваиваем поля
    window.firstValue = calc.firstValueEdit;
    window.secondValue = calc.secondValueEdit;
    window.result = calc.resultValueEdit;
    // изменяем размер окна
    window.resize(480, 640);
    // показываем окно
    window.show();

    return QApplication::exec();
}
