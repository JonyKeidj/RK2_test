#ifndef BUSINESS_H
#define BUSINESS_H

#include <string>

class GroceryStore {
public:
    GroceryStore(); // Конструктор по умолчанию
    explicit GroceryStore(int stock); // Конструктор с параметром
    int AlterStock(int change); // Метод изменения запасов товара

private:
    int stock_;
};

class Restaurant {
public:
    Restaurant(); // Конструктор по умолчанию
    explicit Restaurant(int stock); // Конструктор с параметром
    int AlterStock(int change); // Метод изменения запасов товара

private:
    int stock_;
};

class Estate {
public:
    Estate(); // Конструктор по умолчанию
    explicit Estate(int rentPrice, int purchasePrice); // Конструктор с параметрами
    int AlterRentPrice(int change); // Метод изменения цены аренды
    int AlterPurchasePrice(int change); // Метод изменения цены покупки

private:
    int rentPrice_;
    int purchasePrice_;
};

#endif // BUSINESS_H
