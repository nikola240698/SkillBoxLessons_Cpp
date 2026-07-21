#include <QtWidgets/QApplication>
#include <qmainwindow.h>
#include <qplaintextedit.h>
#include <QWebEngineView>
#include <QHboxLayout>
#include <QFont>

int main(int argc, char *argv[])
{
	// Создаем экземпляр приложения Qt
    QApplication app(argc, argv);
    
	// Создаем главное окно приложения
    QMainWindow window;

	// Устанавливаем заголовок окна и его размеры
    window.setWindowTitle("Html-editor");
    window.resize(1200, 700);

	// Создаем центральный виджет и устанавливаем его в главное окно
	auto* centralWidget = new QWidget(&window);

	// Создаем горизонтальный layout для размещения виджетов
    auto* layout = new QHBoxLayout(centralWidget);

	// Создаем виджеты QPlainTextEdit и QWebEngineView для редактирования и отображения HTML
    auto* plainText = new QPlainTextEdit(centralWidget);
    auto* webView = new QWebEngineView(centralWidget);

	// Устанавливаем шрифт для QPlainTextEdit
	QFont plaintTextFont("Consolas", 11, QFont::Monospace);
	plainText->setFont(plaintTextFont);

	// Устанавливаем начальный HTML-код в виде строки
	QString initialString = R"(<!DOCTYPE html>
<html>
<body>
	<h1>This is the initial text</h1>
	<p>Enter your <b>HTML</b> markup and it will update immediately.</p>
</body>
</html>)";
	
	// Устанавливаем начальный текст в QPlainTextEdit
	plainText->setPlainText(initialString);

	// Устанавливаем начальный HTML в QWebEngineView
	webView->setHtml(initialString);
    
	// Подключаем сигнал textChanged от QPlainTextEdit к слоту, который обновляет содержимое QWebEngineView
	QObject::connect(plainText, &QPlainTextEdit::textChanged, [plainText, webView]() 
        {
		    webView->setHtml(plainText->toPlainText());
		});
	
	// Добавляем виджеты в layout с равным растяжением
	layout->addWidget(plainText, 1);
	layout->addWidget(webView, 1);

	// Устанавливаем центральный виджет в главное окно
	window.setCentralWidget(centralWidget);
	// Отображаем главное окно
    window.show();
	// Запускаем цикл обработки событий приложения
    return app.exec();
}
