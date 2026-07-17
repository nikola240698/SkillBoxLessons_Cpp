import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Video Player")

    // Таймер для контроля задержки и шага заполнения
    Timer {
        // id таймера
        id: delayTimer
        // задержска в мс
        interval: 1000
        // запуск при создании
        running: false
        // цикличность до останова
        repeat: true
        // метод запуска
        onTriggered: {
            if (progressBar.value < progressBar.to) {
                // Увеличиваем значение прогресса
                progressBar.value += 0.05
            } else {
                // Останавливаем таймер по достижении 1.0
                delayTimer.stop()
            }
        }
    }

    // Таймер задержки при нажатии кнопок Next/Previous
    Timer {
        // id таймера
       id: delayNextPrevious
       // задержка
       interval: 1000
       // повтор
       repeat: false
       // метод по завершению
       onTriggered: {
           play.clicked()
       }
    }

    // текстовое поле действия кнопок
    Text {
        // id поля
        id: text
        // высота текста
        font.pointSize: 24
        // выравнивание
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter:  parent.verticalCenter
        anchors.verticalCenterOffset: -40
    }

    // progressBar симуляции запуска видео
    ProgressBar {
        // присваиваем id
        id: progressBar
        // располагаем по середине со смещением
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 150
        // растягиваем по краям родительского объекта
        anchors.left: parent.left
        anchors.right: parent.right
        // делаем отступы
        anchors.margins: 20
        // границы значений
        from: 0.0
        to: 1.0
    }

    // кнопка Play
    Button {
        // id кнопки
        id: play
        // текст кнопки
        text: "▶️"
        // выравнивание
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        // высота текста
        font.pointSize: 24

        // метод нажатия на кнопку
        onClicked:
        {
            // запускаем таймер
            delayTimer.start()
            // выводим сообщение
            text.text = "Playing"
        }
    }

    // кнопка Pause
    Button {
        // id кнопки
        text: "⏸️"
        // выравнивание
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 60
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        // высота текста
        font.pointSize: 24
        // метод нажатия на кнопку
        onClicked:
        {
            // выводим информацию
            text.text = "Pause"
            // сотанавливаем воспроизведение
            delayTimer.stop()
        }
    }

    // кнопка Stop
    Button {
        // id кнопки
        text: "⏹"
        // выравнивание
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -60
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        // высота текста
        font.pointSize: 24
        // метод нажатия на кнопку
        onClicked:
        {
            // выводим информацию
            text.text = "Stop"
            // останавливаем таймер заполнения
            delayTimer.stop()
            // сбрасываем воспроизведение
            progressBar.value = 0.0
        }
    }

    // кнопка Next
    Button {
        // id кнопки
        text: "⏩️"
        // выравнивание
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 120
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        // высота текста
        font.pointSize: 24
        // метод нажатия на кнопку
        onClicked:
        {
            // выводим информацию
            text.text = "Next"
            // останавливаем таймер
            delayTimer.stop()
            // сбрасываем progressBar
            progressBar.value = 0
            // запускаем таймер искуственной задержки
            delayNextPrevious.start();
        }
    }

    // кнопка Previous
    Button {
        // id кнопки
        text: "⏪️"
        // выравнивание кнопки
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -120
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 200
        // высота текста
        font.pointSize: 24
        // метод нажатия кнопки
        onClicked:
        {
            // выводим информацию
            text.text = "Previous"
            // останавливаем таймер
            delayTimer.stop()
            // сбрасываем progressBar
            progressBar.value = 0
            // запускаем таймер искуственной задержки
            delayNextPrevious.start();
        }
    }
}
