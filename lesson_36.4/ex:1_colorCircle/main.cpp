#include <QApplication>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QSlider>

// создем класс курга
class Circle : public QWidget
{
public:
    // объявляем переопределенные методы
    Circle() = default;
    Circle(QWidget* parent);
    void paintEvent(QPaintEvent *event) override;
    QSize minimumSizeHint() const override;

public slots:
    // объявляем слоты
    void setYellow();
    void setRed();
    void setGreen();

private:
    // поля изображений круга
    QPixmap mCurrentColorCircle;
    QPixmap mRedColorCircle;
    QPixmap mGreenColorCircle;
    QPixmap mYellowColorCircle;
};

// метод создания круга
Circle::Circle(QWidget* parent)
{
    // утсанавливаем родителя
    setParent(parent);
    // устанавливаем подпись
    setToolTip("color circle");
    // указваем размеры
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // указываем пути картинкам кругов
    mGreenColorCircle = QPixmap("/home/nick/CLionProjects/SkillBoxQtTutorial/img/greenCircle.png");
    mYellowColorCircle = QPixmap("/home/nick/CLionProjects/SkillBoxQtTutorial/img/yellowCircle.png");
    mRedColorCircle = QPixmap("/home/nick/CLionProjects/SkillBoxQtTutorial/img/redCircle.png");
    mCurrentColorCircle = mGreenColorCircle;
    // создаем изображение
    setGeometry(mCurrentColorCircle.rect());
}

// метод изображения круга
void Circle::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(event->rect(), mCurrentColorCircle);
}

// метод указания минимального размера
QSize Circle::minimumSizeHint() const
{
    return QSize(100, 100);
}

// меод установки желтого цвета
void Circle::setYellow()
{
    mCurrentColorCircle = mYellowColorCircle;
    update();
}

// метод установки зеленого цвета
void Circle::setGreen()
{
    mCurrentColorCircle = mGreenColorCircle;
    update();
}

// метод установки красного цвета
void Circle::setRed()
{
    mCurrentColorCircle = mRedColorCircle;
    update();
}

int main(int argc, char *argv[])
{
    // создаем приложение
    QApplication app(argc, argv);

    // создаем указатель на рабочее окно
    auto* window = new QWidget;
    // создаем круг
    auto* circle = new Circle(window);
    // создаем слайдер
    auto* slider = new QSlider(Qt::Horizontal);
    // параметры слайдера
    slider->setMaximum(100);
    slider->setMinimum(0);
    // создаем рсетку размещения
    auto* layout = new QGridLayout(window);
    // располагаем объекты
    layout->addWidget(circle, 0,0);
    layout->addWidget(slider,1,0);
    // запускаем обработчик событий
    QObject::connect(slider, &QSlider::valueChanged,[&slider, &circle](int newValue)
    {
        if (newValue >= 0 && newValue <= 33)
            circle->setGreen();
        else if (newValue >= 33 && newValue <= 66)
            circle->setYellow();
        else
            circle->setRed();
    });
    // параметры окна
    window->setFixedSize(200, 250);
    // показываем окно
    window->show();

    return app.exec();
}
