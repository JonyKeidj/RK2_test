#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "BusinessSystem.cpp"

void BuyFood(Restaurant& restaurant)
{
    auto price = restaurant.CookFood();
    if (price >= 0)
    {
        std::cout << "[BuyFood] The price of food : " << price << std::endl;
    }
    else
    {
        std::cout << "[BuyFood] Restaurant was closed bescause groceries are lack." << std::endl;
    }
}

void SupplyGrocery(GroceryStore& groceryStore, std::uint16_t count)
{
    std::uint16_t newCount = groceryStore.Supply(count);
    std::int32_t oldPrice = estateOwner.SetEstateRentPrice(newPrice);
    std::cout << "Grocery Stock Changes : " << oldCount << " -> " << newCount << std::endl;
}

void ChangeGroceryPrice(GroceryStore& groceryStore, std::int32_t priceChange)
{
    auto newPrice = groceryStore.AlterPrice(priceChange);
    auto oldPrice = newPrice - priceChange;
    std::cout << "Grocery Price Changes : " << oldPrice << " -> " << newPrice << std::endl;
}

void ChangeEstateRentPrice(EstateOwner& estateOwner, std::int32_t newPrice)
{
    auto oldPrice = estateOwner.SetEstateRentPrice(newPrice);
    std::cout << "EstateRentPrice Changes : " << oldPrice << " -> " << newPrice << std::endl;
}

/*
    Mediator Pattern은 한 집합에 속해있는 객체들의 상호작용을 캡슐화하는 패턴입니다.
    객체들간의 상호작용이 하나의 객체로 모아지기 때문에, 객체들이 서로를 직접 참조하지 않게되어
    객체들이 loosely coupling 되는 효과가 있습니다.
    객체들간의 상호작용 로직이 객체들과 분리되어 추상화되므로, 상호작용 로직만을 쉽게 수정하거나
    런타임에 변경할 수 있게 됩니다. 또한 각 객체들이 별도로 재사용이 가능해지게 됩니다.
    단, Mediator 클래스 자체는 복잡도가 증가해 유지보수가 어려워질 수 있습니다.
*/

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
}
