#ifndef BUSINESS_H
#define BUSINESS_H

#include <iostream>
#include <stdexcept>
#include <string>

class EstateOwner;
class GroceryStore;
class Restaurant;

class BusinessMediator
{
public:
    BusinessMediator(EstateOwner& estateOwner, GroceryStore& groceryStore, Restaurant& restaurant);

    void EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    void GroceryStockChanged(std::int32_t currentStock);
    void GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    void FoodIsCooked();

private:
    EstateOwner& estateOwner_;
    GroceryStore& groceryStore_;
    Restaurant& restaurant_;
};

class EstateOwner
{
public:
    std::int32_t SetEstateRentPrice(std::int32_t price);
    BusinessMediator* SetBusinessMediator(BusinessMediator* mediator);

private:
    BusinessMediator* mediator_{ nullptr };
    std::int32_t estateRentPrice_{ 10000 };
};

class GroceryStore
{
public:
    std::int32_t Supply(std::uint16_t count);
    std::int32_t Sell();
    std::int32_t GetPrice() const;
    std::int32_t AlterPrice(std::int32_t priceChange);
    BusinessMediator* SetBusinessMediator(BusinessMediator* mediator);

private:
    BusinessMediator* mediator_{ nullptr };
    std::int32_t stock_{ 0 };
    std::int32_t price_{ 500 };
};

class Restaurant
{
public:
    Restaurant(GroceryStore& groceryStore);
    std::int32_t CookFood();
    bool IsOpened() const;
    void SetIsOpened(bool isOpened);
    std::int32_t GetPrice() const;
    std::int32_t AlterPrice(std::int32_t priceChange);
    BusinessMediator* SetBusinessMediator(BusinessMediator* mediator);

private:
    GroceryStore& groceryStore_;
    BusinessMediator* mediator_{ nullptr };
    bool isOpened_{ true };
    std::int32_t price_{ 500 };
};

void BuyFood(Restaurant& restaurant);
void SupplyGrocery(GroceryStore& groceryStore, std::uint16_t count);
void ChangeGroceryPrice(GroceryStore& groceryStore, std::int32_t priceChange);
void ChangeEstateRentPrice(EstateOwner& estateOwner, std::int32_t newPrice);

#endif // BUSINESS_H
