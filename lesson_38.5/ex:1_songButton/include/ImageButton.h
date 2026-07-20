#pragma once

#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H


#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>
#include <QTimer>

// Создаем класс кнопки
// наследуем класс QPushButton
class ImageButton : public QPushButton
{
    // так как наследовали QPushButton то необходимо подключить макрос
    Q_OBJECT

public:
    // переопределяем методы
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    // добавляем слоты (что-то типа методов работы кнопки)
    void setUp();
    void setDown();

private:
    // создаем поля для картинок кнопки
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;

};





#endif // IMAGEBUTTON_H
