
#include <Qstring>
#include <stdexcept>
#include "calc.h"


int CalcMainWindow::checkValue(QString qString) {
    // при пустой строке возвращаем 0
    if (qString.size() == 0)
        return 0;

    // создаем счетчик
    int i = 0;
    // проверяем на орицательное значение
    if (qString[0] == '-')
    {
        i = 1;
    }
    // проверяем все остальные символы
    for (; i < qString.size(); ++i) {
        if (!qString[i].isDigit())
            throw std::invalid_argument("NaN");
    }

    // возвращаем значение
    return qString.toInt();
}

// метод сложения чисел
void CalcMainWindow::addition()
{
    // пробуем
    try
    {
        // получаем первое значение с проверкой
        int firstValueInt = checkValue(firstValue->text());
        // получаем второе значение с проверкой
        int secondValueInt = checkValue(secondValue->text());
        // вычисляем резултат
        int resultInt = firstValueInt + secondValueInt;
        // выводим результат в поле
        result->setText(QString::number(resultInt));
    }
    // ловим ошибки
    catch (const std::invalid_argument& error)
    {
        // вывыодим ошибку в поле вывода
        result->setText(QString::fromStdString(error.what()));
    }

}

// метод вычитания
void CalcMainWindow::subtraction()
{
    // пробуем
    try
    {
        // получаем первое значение с проверкой
        int firstValueInt = checkValue(firstValue->text());
        // получаем второе значение с проверкой
        int secondValueInt = checkValue(secondValue->text());
        // вычисляем резултат
        int resultInt = firstValueInt - secondValueInt;
        // выводим результат в поле
        result->setText(QString::number(resultInt));
    }
    // ловим ошибки
    catch (const std::invalid_argument& error)
    {
        // вывыодим ошибку в поле вывода
        result->setText(QString::fromStdString(error.what()));
    }


}

// метод умножения
void CalcMainWindow::multiplication()
{
    // пробуем
    try
    {
        // получаем первое значение с проверкой
        int firstValueInt = checkValue(firstValue->text());
        // получаем второе значение с проверкой
        int secondValueInt = checkValue(secondValue->text());
        // вычисляем резултат
        int resultInt = firstValueInt * secondValueInt;
        // выводим результат в поле
        result->setText(QString::number(resultInt));
    }
    // ловим ошибки
    catch (const std::invalid_argument& error)
    {
        // вывыодим ошибку в поле вывода
        result->setText(QString::fromStdString(error.what()));
    }

}

// метод деления
void CalcMainWindow::division()
{
    // пробуем
    try
    {
        // получаем первое значение с проверкой
        int firstValueInt = checkValue(firstValue->text());
        // получаем второе значение с проверкой
        int secondValueInt = checkValue(secondValue->text());
        // проверяем, чтобы делитель не был нулем
        if (secondValueInt == 0)
            throw std::invalid_argument("Division by 0");
        // вычисляем резултат
        int resultInt = firstValueInt / secondValueInt;
        // выводим результат в поле
        result->setText(QString::number(resultInt));
    }
    // ловим ошибки
    catch (const std::invalid_argument& error)
    {
        // вывыодим ошибку в поле вывода
        result->setText(QString::fromStdString(error.what()));
    }
}
