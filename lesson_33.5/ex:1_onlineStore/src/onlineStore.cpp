#include "onlineStore.h"

// метод проверки артикула
void OnlineStore::validateArticle(const std::string& article) const
{
    // если артикул пуст
    if (article.empty())
    {
        throw std::invalid_argument("The Article cannot be empty.");
    }
    // если база данных пуста
    if (database.find(article) == database.end())
    {
        throw std::invalid_argument("The product with the article \""
            + article + "\" is not in the store's database");
    }
}

// метод проверки количества предметов
void OnlineStore::validationQuantity(const int& quantity) const
{
    // если предметов отрицательное число
    if (quantity <= 0)
    {
        throw std::invalid_argument("TThe quantity of the product must be greater than zero.");
    }
}


// метод добавления записи в базу данных
void OnlineStore::addProductToDatabase(const std::string& article, const int quantity)
{
    // если артикул пустой
    if (article.empty())
    {
        throw std::invalid_argument("The article cannon be empty");
    }
    // если количество предметов отрицательное
    if (quantity < 0)
    {
        throw std::invalid_argument("The product quantity on the store cannon be negative.");
    }
    // пробуем искать товар по артикулу
    if (database.find(article) != database.end())
    {
        throw std::invalid_argument("There are not the product with the article");
    }
    // если не было ошибок, то добавляем в базу товар
    database[article] = quantity;
}

// метод добавления товара в корзину
void OnlineStore::addToBasket(const std::string& article, const int& quantity)
{
    // проверяем артикулы и количество предметов
    validateArticle(article);
    validationQuantity(quantity);
    // счетчик предметов в корзине
    int quantityInBasket = 0;
    // ищем в корзине введенный артикул
    std::map<std::string, int>::iterator basketIt = basket.find(article);
    // если нашли товар
    if (basketIt != basket.end())
    {
        quantityInBasket = basketIt->second;
    }
    // переменная ожидаемого остатка товара
    int availableQuantity = database.at(article) - quantityInBasket;
    // если товара осталось мало
    if (quantity > availableQuantity)
    {
        throw std::runtime_error("There are noe more products on the store. Available: "
            + std::to_string(availableQuantity));
    }
    // если нет ошибок, то добавляем в корзину товар
    basket[article] += quantity;

    std::cout << "The product \"" << article << "\" added to basket in amount: "
        << quantity << "pcs" << std::endl;
}

// метод удаления товара из корзины
void OnlineStore::remove(const std::string& article, const int& quantity)
{
    // проверяем указанные артикул и количество
    validateArticle(article);
    validationQuantity(quantity);
    // ищем в корзине необходимый товар
    std::map<std::string, int>::iterator basketIt = basket.find(article);
    // если не нашли такой
    if (basketIt == basket.end())
    {
        throw std::runtime_error("There are not the product \"" + article
            + "\" in the basket.");
    }
    // если ввели большее количество, чем имеется
    if (quantity > basketIt->second)
    {
        throw std::runtime_error("You can't delete more products than are in your basket."
                "In your basket: " + std::to_string(basketIt->second));
    }
    // при отсутствии ошибок выполняем удаление
    basketIt->second -= quantity;
    // выводим резульат в консоль
    std::cout << "Removed from basket " << quantity << "pcs of the product \""
        << article << "\"" << std::endl;
    // проверка на остаточной в корзине товаров с таким артикулом
    if (basketIt-> second == 0)
    {
        // если не осталось, то удаляем запись совсем
        basket.erase(basketIt);
    }
}

// метод вывода содержимого магазина
void OnlineStore::printDatabase() const
{
    std::cout << "There are the shop's products:" << std::endl;
    // если пустая база
    if (database.empty())
    {
        std::cout << "The database is empty" << std::endl;
        return;
    }
    // пробегаемся циклом по всему словарю
    for (auto it = database.begin(); it != database.end(); ++it)
    {
        // переменная количества предметов в корзине для общего отображения
        int quantityInBasket = 0;
        // ищем в корзине такой же товар
        auto basketIt = basket.find(it->first);
        // если нашли такой предмет, то учитываем его количество в корзине
        if (basketIt != basket.end())
        {
            quantityInBasket = basketIt->second;
        }
        // выводим результат
        std::cout << "The article: \"" << it->first
            << "\", total in storage: " << it->second
            << ", available: " << it->second - quantityInBasket << std::endl;
    }
}

// метод вывода списка корзины
void OnlineStore::printBasket() const
{
    std::cout << "Basket:" << std::endl;
    // проверяем корзину на пустоту
    if (basket.empty())
    {
        std::cout << "The basket is empty" << std::endl;
        return;
    }
    // пробегаемся по корзине и выводим информацию в консоль
    for (auto it = basket.begin(); it != basket.end(); ++it)
    {
        std::cout << "The article: \"" << it->first << "\", amount: "
            << it->second << std::endl;
    }
}