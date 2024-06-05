#include "business.h"
#include "gtest/gtest.h"

TEST(BusinessMediatorTest, GroceryStoreStockChangedTest) {
    // Создаем объект магазина с начальным запасом товара
    GroceryStore groceryStore(100);
    EXPECT_EQ(groceryStore.AlterStock(100), 100); // Изначально запас 100
    EXPECT_EQ(groceryStore.AlterStock(-50), 50); // Уменьшение на 50
}

TEST(BusinessMediatorTest, RestaurantStockChangedTest) {
    // Создаем объект ресторана с начальным запасом товара
    Restaurant restaurant(100);
    EXPECT_EQ(restaurant.AlterStock(100), 100); // Изначально запас 100
    EXPECT_EQ(restaurant.AlterStock(-50), 50); // Уменьшение на 50
}

TEST(BusinessMediatorTest, EstateRentPriceChangedTest) {
    // Создаем объект недвижимости с начальными ценами аренды и покупки
    Estate estate(10000, 20000);
    EXPECT_EQ(estate.AlterRentPrice(10000), 10000); // Изначально цена аренды 10000
    EXPECT_EQ(estate.AlterRentPrice(20000), 20000); // Изменение на 10000
}

TEST(BusinessMediatorTest, EstatePurchasePriceChangedTest) {
    // Создаем объект недвижимости с начальными ценами аренды и покупки
    Estate estate(10000, 20000);
    EXPECT_EQ(estate.AlterPurchasePrice(10000), 10000); // Изначально цена покупки 10000
    EXPECT_EQ(estate.AlterPurchasePrice(20000), 20000); // Изменение на 10000
}
