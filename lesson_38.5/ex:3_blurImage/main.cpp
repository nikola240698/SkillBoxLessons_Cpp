#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>

#include <QFileDialog>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsScene>  
#include <QGraphicsBlurEffect>  
#include <QGraphicsPixmapItem>  


// функция применения размытия ко входному изображению  
QImage blurImage(const QImage& source, int blurRadius)
{
	// Проверка на пустое изображение
	if (source.isNull())
		return QImage();
	// Создаем необходимые перменные
	QGraphicsScene scene;
	QGraphicsPixmapItem item;
	// Получаем изображение
	item.setPixmap(QPixmap::fromImage(source));
	//	Создаем эффект размытия
	auto* blur = new QGraphicsBlurEffect;
	// назначаем радиус размытия
	blur->setBlurRadius(blurRadius);
	// применяем эффект к изображению
	item.setGraphicsEffect(blur);
	// добавляем изображение в сцену
	scene.addItem(&item);
	// создаем результирующее изображение с прозрачным фоном
	QImage result(source.size(), QImage::Format_ARGB32);
	// заполняем изображение прозрачным цветом
	result.fill(Qt::transparent);
	// создаем объект для рисования
	QPainter painter(&result);
	// рендерим сцену на результирующее изображение
	scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
	return result;
}


int main(int argc, char *argv[])
{
	// Создаем объект приложения
    QApplication app(argc, argv);

	// Создаем главное окно приложения
	QWidget* window = new QWidget();
	// Устанавливаем заголовок окна
	window->setWindowTitle("Image Blur Application");
	// Создаем кнопку открытия изображения
	QPushButton* buttonOpen	=new QPushButton("Open");
	// Создаем метку для отображения изображения
	QLabel* label = new QLabel("Your image");
	// Устанавливаем выравнивание текста в метке по центру
	label->setAlignment(Qt::AlignCenter);
	// Создаем слайдер для регулировки радиуса размытия
	QSlider* slider = new QSlider(Qt::Horizontal);
	// Устанавливаем диапазон значений слайдера от 0 до 10
	slider->setRange(0, 10);
	// Устанавливаем шаг изменения значения слайдера
	slider->setSingleStep(1);	
	// Устанавливаем начальное значение слайдера
	slider->setValue(0);
	// Создаем вертикальный компоновщик для размещения виджетов
	QVBoxLayout* vLayout = new QVBoxLayout(window);
	// Добавляем виджеты в компоновщик с равным распределением пространства
	vLayout->addWidget(label);
	vLayout->addWidget(slider);
	vLayout->addWidget(buttonOpen);
	// Устанавливаем компоновщик для главного окна
	window->setLayout(vLayout);
	// Инициализируем переменную для хранения текущего радиуса размытия
	int blurRadius = 0;

	// Подключаем сигнал нажатия кнопки к лямбда-функции для открытия изображения
	QObject::connect(buttonOpen, &QPushButton::clicked, [label, window, &blurRadius]() {
		// Открываем диалоговое окно для выбора изображения
		QString fileName = QFileDialog::getOpenFileName(window, "Open Image", "", "Image Files (*.jpg *.JPG)");
		// Если файл выбран, загружаем изображение и отображаем его в метке
		if (!fileName.isEmpty()) {
			QPixmap pixmap(fileName);
			label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio));
			// Сбрасываем радиус размытия при открытии нового изображения
			blurRadius = 0;
		}
		});

	// Подключаем сигнал изменения значения слайдера к лямбда-функции для применения размытия
	QObject::connect(slider, &QSlider::valueChanged, [slider, label, &blurRadius](int value)
		{
			// Проверяем, что изображение в метке не пустое
			if (label->pixmap().toImage().isNull()) 
				return;
			// Если новое значение радиуса размытия больше текущего, применяем размытие к изображению
			if (value > blurRadius)
			{
				label->setPixmap(QPixmap::fromImage(blurImage(label->pixmap().toImage(), value)));
				// Обновляем текущий радиус размытия
				blurRadius = value;
			}
		});
	
	// Устанавливаем фиксированный размер главного окна
	window->setFixedSize(800, 600);
	
	// Отображаем главное окно
	window->show();
	// Запускаем цикл обработки событий приложения
    return app.exec();
}
