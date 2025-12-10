#include <iostream>

int main() {

  std::string racerName = "Шумахер";
  int lap = 4;	
  int enginePower = 254;
  int wheelRadius = 93;
  int carSterringWheel = 49;
  int windSpeed = 21;
  int rainSpeed = 17;
  int racerSpeed = enginePower + wheelRadius + carSterringWheel - windSpeed - rainSpeed;

  std::cout << "==================" << std::endl;
  std::cout << "Супер гонки. Круг " << lap << std::endl;
  std::cout << "==================" << std::endl;
  std::cout << racerName << " (" << racerSpeed << ")" << std::endl;
  std::cout << "==================" << std::endl;
  std::cout << "Водитель: " << racerName << std::endl;
  std::cout << "Скорость :" << racerSpeed << std::endl;
  std::cout << "------------------" << std::endl;
  std::cout << "Оснащение:" << std::endl;
  std::cout << "Двигатель: +" << enginePower << std::endl;
  std::cout << "Колеса: +" << wheelRadius << std::endl;
  std::cout << "Руль: +" << carSterringWheel << std::endl;
  std::cout << "------------------" << std::endl;
  std::cout << "Действия плохой погоды" << std::endl;
  std::cout << "Ветер: -" << windSpeed << std::endl;
  std::cout << "Дождь: -" << rainSpeed << std::endl;

}
