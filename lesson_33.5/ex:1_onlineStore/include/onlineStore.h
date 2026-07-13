#pragma once

#include <iostream>
#include <map>
#include <string>

class OnlineStore
{
    // поле склада товаров магазина
    std::map<std::string, int> database;
    // поле корзины покупателя
    std::map<std::string, int> basket;

    // метод проверки артикула
    void validateArticle(const std::string& article) const;

    // метод проверки количества предметов
    void validationQuantity(const int& quantity) const;

public:

    // метод добавления записи в базу данных
    void addProductToDatabase(const std::string& article, const int quantity);

    // метод добавления товара в корзину
    void addToBasket(const std::string& article, const int& quantity);

    // метод удаления товара из корзины
    void remove(const std::string& article, const int& quantity);

    // метод вывода содержимого магазина
    void printDatabase() const;

    // метод вывода списка корзины
    void printBasket() const;
};