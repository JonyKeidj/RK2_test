#include <gtest/gtest.h>
#include "business.h"

// Тест для проверки изменения цены аренды недвижимости
TEST(BusinessMediatorTest, EstateRentPriceChangedTest) {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant(groceryStore);
    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    // Изначально цена аренды равна 10000
    EXPECT_EQ(estateOwner.SetEstateRentPrice(10000), 10000);

    // После изменения цены на 20000, ожидается изменение цены продуктов в продуктовом магазине и ресторане
    mediator.EstateRentPriceChanged(10000, 20000);
    EXPECT_EQ(groceryStore.GetPrice(), 502); // (20000 - 10000) / 10000 = 1 => изменение цены на 1
    EXPECT_EQ(restaurant.GetPrice(), 510);   // (20000 - 10000) / 1000 = 10 => изменение цены на 10
}

// Тест для проверки изменения запасов продуктов в продуктовом магазине
TEST(BusinessMediatorTest, GroceryStockChangedTest) {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant(groceryStore);
    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    // Изначально запас продуктов равен 0
    EXPECT_EQ(groceryStore.Supply(0), 0);

    // После добавления 5 продуктов, ожидается открытие ресторана
    groceryStore.Supply(5);
    mediator.GroceryStockChanged(5);
    EXPECT_TRUE(restaurant.IsOpened());

    // После продажи всех продуктов, ожидается закрытие ресторана из-за недостатка товара
    for (int i = 0; i < 5; ++i) {
        groceryStore.Sell();
    }
    mediator.GroceryStockChanged(0);
    EXPECT_FALSE(restaurant.IsOpened());
}

// Тест для проверки изменения цены продуктов в продуктовом магазине
TEST(BusinessMediatorTest, GroceryPriceChangedTest) {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant(groceryStore);
    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    // Изначально цена продуктов равна 500
    EXPECT_EQ(groceryStore.GetPrice(), 500);

    // После изменения цены на 600, ожидается изменение цены в ресторане
    mediator.GroceryPriceChanged(500, 600);
    EXPECT_EQ(restaurant.GetPrice(), 600); // изменение на 100
}
