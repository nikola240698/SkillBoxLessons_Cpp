#include "select.h"

// функция выбора типа переменной ключа/значения реестра
int selectType(const std::string& valueName)
{
    while (true)
    {
        // выводим возможные значения
        std::cout << "Select the data type for the " << valueName << std::endl;
        std::cout << "1 - int" << std::endl;
        std::cout << "2 - double" << std::endl;
        std::cout << "3 - string" << std::endl;
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

// функция выбора типа переменных для словаря реестра
int selectTypename()
{
    // переменная выбора
    int select = 0;
    // получаем типы данных для ключа/значения
    int keyType = selectType("Key");
    int valueType = selectType("Value");

    // при помощи битовых масок реализуем выбор необходимых типов
    // для ключа
    switch (keyType)
    {
        case 1: select |= HasIntKey;
            break;
        case 2: select |= HasDoubleKey;
            break;
        case 3: select |= HasStringKey;
            break;
    }
    // для значения
    switch (valueType)
    {
        case 1: select |= HasIntValue;
            break;
        case 2: select |= HasDoubleValue;
            break;
        case 3: select |= HasStringValue;
            break;
    }
    // возвращаем получившуюся маску
    return select;
}

// функция запуска необходимого словаря по шаблону
void selectTemplate()
{
    // получаем нашу битовую маску
    const int select = selectTypename();

    // проверяем что у нас в битовой маске и работу рееестра
    // при условии ключа int
    if (select & HasIntKey)
    {
        // при условии значения int
        if (select & HasIntValue)
        {
            registryWork<int, int>();
        }
        // при условии значения double
        if (select & HasDoubleValue)
        {
            registryWork<int, double>();
        }
        // при условии значения std::string
        if (select & HasStringValue)
        {
            registryWork<int, std::string>();
        }
    }
    // при условии ключа double
    if (select & HasDoubleKey)
    {
        // при условии значения int
        if (select & HasIntValue)
        {
            registryWork<double, int>();
        }
        // при условии значения double
        if (select & HasDoubleValue)
        {
            registryWork<double, double>();
        }
        // при условии значения std::string
        if (select & HasStringValue)
        {
            registryWork<double, std::string>();
        }
    }
    // при условии ключа std::string
    if (select & HasStringKey)
    {
        // при условии значения int
        if (select & HasIntValue)
        {
            registryWork<std::string, int>();
        }
        // при условии значения double
        if (select & HasDoubleValue)
        {
            registryWork<std::string, double>();
        }
        // при условии значения std::string
        if (select & HasStringValue)
        {
            registryWork<std::string, std::string>();
        }
    }
}