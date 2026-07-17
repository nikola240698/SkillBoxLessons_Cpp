#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

// создаем класс калькулятора
class CalcMainWindow : public QMainWindow
{
    // обязательное поле
    Q_OBJECT

public:

    // добавляем поля ввода и вывода текста
    QLineEdit* firstValue = nullptr;
    QLineEdit* secondValue = nullptr;
    QLineEdit* result = nullptr;
    // конструктор класса
    CalcMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {}


public slots:
    // описываем слоты класса
    void addition();
    void subtraction();
    void multiplication();
    void division();

private:
    // метод проверки введенного значения
    int checkValue(QString qString);

};


#endif