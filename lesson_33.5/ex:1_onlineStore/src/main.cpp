#include <iostream>
#include <map>
#include <string>

#include "m_input.h"
#include "onlineStore.h"

int main()
{
    // создаем магазин
    OnlineStore store;
    // вводим количество товаров
    std::cout << "Input the amount of products in the store: " << std::endl;
    int productCount = inputInt();
    // проверяем что ввели верное количество
    if (productCount <= 0)
    {
        std::cout << "Incorrect amount of products" << std::endl;
    }
    // вводим каждый товар
    for (int i = 0; i < productCount; ++i)
    {
        std::cout << "The product #" << i + 1 << std::endl;

        // вводим название
        std::string article;
        std::cout << "Input the article: ";
        std::cin >> article;

        // вводим количество
        std::cout << "Input the amount of the product on the stock: ";
        int quantity = inputInt();

        // пробуем добавить его в магазин
        try
        {
            store.addProductToDatabase(article, quantity);
        }
        catch (const std::invalid_argument& error)
        {
            std::cout << "Error: " << error.what() << std::endl;
        }
    }

    std::string command;
    // циклом выполняем команды
    while (true)
    {
        std::cout << std::endl;
        std::cout << "Available commands:" << std::endl;
        std::cout << "add\t- add an item to the cart" << std::endl;
        std::cout << "remove\t- remove an item from the cart" << std::endl;
        std::cout << "basket\t- show the cart" << std::endl;
        std::cout << "store\t- show the store's products" << std::endl;
        std::cout << "exit\t- exit the program" << std::endl;
        std::cout << "Enter the command: " << std::endl;

        std::cin >> command;
        // команда показа корзины
        if (command == "basket")
        {
            store.printBasket();
            continue;
        }

        // команда вывода ассортимента магазина
        if (command == "store")
        {
            store.printDatabase();
            continue;
        }

        std::string article;
        int quantity;

        // пробуем команды добавить или удалить из корзины
        try
        {
            if (command == "add")
            {
                std::cout << "Input the article -> ";
                std::cin >> article;
                std::cout << "Input the quantity -> ";
                quantity = inputInt();
                store.addToBasket(article, quantity);
                continue;
            }
            if (command == "remove")
            {
                std::cout << "Input the article -> ";
                std::cin >> article;
                std::cout << "Input the quantity -> ";
                quantity = inputInt();
                store.remove(article, quantity);
                continue;
            }

        }
        // ловим ошибки
        catch (const std::invalid_argument& error)
        {
            std::cout << "Incorrect data: " << error.what() << std::endl;
        }
        catch (const std::runtime_error& error)
        {
            std::cout << "Runtime error: " << error.what() << std::endl;
        }

        // команда выхода из программы
        if (command == "exit")
        {
            break;
        }

        std::cout << "Incorrect command" << std::endl;

    }

    return 0;
}
