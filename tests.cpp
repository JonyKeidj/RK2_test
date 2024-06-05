#include <gtest/gtest.h>
#include "business.h"

// Тестирование изменения цены в продуктовом магазине
TEST(BusinessMediatorTest, GroceryStorePriceChangedTest) {
    GroceryStore groceryStore;
    EXPECT_EQ(groceryStore.AlterPrice(10000), 10000); // Изначально цена 10000
    EXPECT_EQ(groceryStore.AlterPrice(20000), 20000); // Изменение на 10000
}

// Тестирование изменения цены в ресторане
TEST(BusinessMediatorTest, RestaurantPriceChangedTest) {
    GroceryStore groceryStore; // Создаем продуктовый магазин
    Restaurant restaurant(groceryStore); // Передаем продуктовый магазин ресторану
    EXPECT_EQ(restaurant.AlterPrice(10000), 10000); // Изначально цена 10000
    EXPECT_EQ(restaurant.AlterPrice(20000), 20000); // Изменение на 10000
}

// Тестирование изменения запасов в продуктовом магазине
TEST(BusinessMediatorTest, GroceryStoreStockChangedTest) {
    GroceryStore groceryStore;
    EXPECT_EQ(groceryStore.AlterStock(100), 100); // Изначально запас 100
    EXPECT_EQ(groceryStore.AlterStock(-50), 50); // Уменьшение на 50
}

// Тестирование изменения запасов в ресторане
TEST(BusinessMediatorTest, RestaurantStockChangedTest) {
    GroceryStore groceryStore; // Создаем продуктовый магазин
    Restaurant restaurant(groceryStore); // Передаем продуктовый магазин ресторану
    EXPECT_EQ(restaurant.AlterStock(100), 100); // Изначально запас 100
    EXPECT_EQ(restaurant.AlterStock(-50), 50); // Уменьшение на 50
}

// Тестирование изменения цены аренды в недвижимости
TEST(BusinessMediatorTest, EstateRentPriceChangedTest) {
    Estate estate;
    EXPECT_EQ(estate.AlterRentPrice(10000), 10000); // Изначально цена аренды 10000
    EXPECT_EQ(estate.AlterRentPrice(20000), 20000); // Изменение на 10000
}

// Тестирование изменения цены покупки в недвижимости
TEST(BusinessMediatorTest, EstatePurchasePriceChangedTest) {
    Estate estate;
    EXPECT_EQ(estate.AlterPurchasePrice(10000), 10000); // Изначально цена покупки 10000
    EXPECT_EQ(estate.AlterPurchasePrice(20000), 20000); // Изменение на 10000
}
