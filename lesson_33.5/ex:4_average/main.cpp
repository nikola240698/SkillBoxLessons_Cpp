#include <iostream>
#include <vector>
#include <limits>

// шаблон функции ввода произвольных переменных с проверкой на ошибки
template<typename T>
T inputValue()
{
    T value;
    while (true)
    {
        if (std::cin >> value)
        {
            return value;
        }
        std::cerr << "Incorrect input. Try again.\n";
        // Сбрасываем состояние ошибки потока
        std::cin.clear();
        // Удаляем неправильные данные из буфера
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// шаблон вычисления среднеарифметического значения
template<typename T>
double average(std::vector<T>& vec)
{
    T sum = 0;
    // суммируем все значения в векторе
    for (int i = 0; i < vec.size(); ++i)
    {
        sum += vec[i];
    }
    // возвращаем значение деленное на размер вектора, заранее приводя его к double
    return static_cast<double>(sum) / vec.size();
}

// шаблон ввода данных в вектор
template<typename T>
void input(std::vector<T>& vec)
{
    int size;
    while (true)
    {
        // вводим размер веткора с проверкой
        std::cout << "Input the size of the array ->";
        size = inputValue<int>();
        if (size <= 0)
        {
            std::cerr << "Value must be more than 0!" << std::endl;
            continue;
        }
        break;
    }
    // вводим каждый элемент
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Input value #" << i << std::endl;
        vec.push_back(inputValue<T>());
    }
}

// функция выбора типа переменных вектора
int selectType()
{
    while (true)
    {
        // выводим возможные значения
        std::cout << "Select the data type for the array" << std::endl;
        std::cout << "1 - int" << std::endl;
        std::cout << "2 - double" << std::endl;
        std::cout << "3 - float" << std::endl;
        // получаем значение от пользователя
        int type = inputValue<int>();
        // проверяем, что получили верное значение
        if (type >= 1 && type <= 3)
        {
            return type;
        }
        // сообщение об ошибке
        std::cout << "The number must be from 1 to 3" << std::endl;
    }
}

int main()
{    
    // условие выбора типа переменных вектора
    switch (selectType())
    {
        case 1:
        {
            auto* vec = new std::vector<int>;

            input(*vec);
            std::cout << "Average = " << average(*vec) << std::endl;

            delete vec;
            break;
        }
        case 2:
        {
            auto* vec = new std::vector<double>;

            input(*vec);
            std::cout << "Average = " << average(*vec) << std::endl;

            delete vec;
            break;
        }
        case 3:
        {
            auto* vec = new std::vector<float>;

            input(*vec);
            std::cout << "Average = " << average(*vec) << std::endl;

            delete vec;
            break;
        }
        default:
            std::cout << "Incorrect data" << std::endl;
    }
    return 0;
}
