#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "BusinessSystem.cpp"
#include "BusinessSystem.h"

void BuyFood(Restaurant& restaurant)
{
    auto price = restaurant.CookFood();
    if (price >= 0)
    {
        std::cout << "[BuyFood] The price of food : " << price << std::endl;
    }
    else
    {
        std::cout << "[BuyFood] Restaurant was closed because groceries are lacking." << std::endl;
    }
}

void SupplyGrocery(GroceryStore& groceryStore, std::int32_t count)
{
    groceryStore.Supply(count);
}

void ChangeGroceryPrice(GroceryStore& groceryStore, std::int32_t priceChange)
{
    groceryStore.AlterPrice(priceChange);
}

void ChangeEstateRentPrice(EstateOwner& estateOwner, std::int32_t newPrice)
{
    estateOwner.SetEstateRentPrice(newPrice);
}

int main()
{
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant;

    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    SupplyGrocery(groceryStore, 2);
    groceryStore.Sell();
    BuyFood(restaurant);
    BuyFood(restaurant);
    std::cout << std::endl;

    SupplyGrocery(groceryStore, 3);
    ChangeEstateRentPrice(estateOwner, 1000);
    BuyFood(restaurant);
    ChangeEstateRentPrice(estateOwner, 10000);
    BuyFood(restaurant);
    ChangeEstateRentPrice(estateOwner, 100000);
    BuyFood(restaurant);
    std::cout << std::endl;

    SupplyGrocery(groceryStore, 3);
    ChangeGroceryPrice(groceryStore, 100);
    BuyFood(restaurant);
    ChangeEstateRentPrice(estateOwner, 10000);
    BuyFood(restaurant);
    ChangeGroceryPrice(groceryStore, -100);
    BuyFood(restaurant);
    BuyFood(restaurant);

    return 0;
}
