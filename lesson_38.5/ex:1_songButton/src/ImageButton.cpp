#include "ImageButton.h"

// описываем метод создания кнопки
ImageButton::ImageButton(QWidget *parent)
{
    // указываем родителя
    setParent(parent);
    // указываем размеры (фиксированные)
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // путь к картинке не нажатой кнопки
    mButtonUpPixmap = QPixmap(":/media/img/non_pressed.png");
    // путь к картинке нажатой кнопки
    mButtonDownPixmap = QPixmap(":/media/img/pressed.png");
    // путь к начальной картинке
    mCurrentButtonPixmap = mButtonUpPixmap;
    // устанавливаем размеры исходя из размера картинки
    setGeometry(mCurrentButtonPixmap.rect());
    // метод получения сигнала о нажатии на кнопку
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}


// описываем метод изображения кнопки
void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

// описываем метод изменения размера кнопки
QSize ImageButton::sizeHint() const
{
    return QSize(100, 100);
}

// описываем метод минимального размера кнопки
QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

// описываем метод нажатия на кнопку
void ImageButton::keyPressEvent(QKeyEvent *e)
{
    // вызываем слот нажатия на кнопку
    setDown();
}

// описываем метод нажатия на кнопку
void ImageButton::setDown()
{
    // меняем картинку нажатия
    mCurrentButtonPixmap = mButtonDownPixmap;
    // обновляем для изменения
    update();
    // собственный Qt таймер для создания задержки в мс и вызова метода отжатия кнопки
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

// описываем метод отжатия кнопки
void ImageButton::setUp()
{
    // меняем картинку
    mCurrentButtonPixmap = mButtonUpPixmap;
    // обновляем экран
    update();
}
