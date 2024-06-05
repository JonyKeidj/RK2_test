#include "gtest/gtest.h"
#include "business.h" // Подключаем исходный файл, чтобы иметь доступ к классам

// Тесты для класса Theme
TEST(ThemeTest, WhiteThemeTest) {
    WhiteTheme whiteTheme;
    EXPECT_EQ(whiteTheme.Name(), "Red Theme");
    EXPECT_EQ(whiteTheme.WallColor().R, 255);
    EXPECT_EQ(whiteTheme.WallColor().G, 255);
    EXPECT_EQ(whiteTheme.WallColor().B, 255);
}

TEST(ThemeTest, DarkThemeTest) {
    DarkTheme darkTheme;
    EXPECT_EQ(darkTheme.Name(), "Dark Theme");
    EXPECT_EQ(darkTheme.WallColor().R, 0);
    EXPECT_EQ(darkTheme.WallColor().G, 0);
    EXPECT_EQ(darkTheme.WallColor().B, 0);
}

// Тесты для класса House
TEST(HouseTest, OneRoomTest) {
    OneRoom oneRoom(std::make_shared<WhiteTheme>());
    EXPECT_EQ(oneRoom.Name(), "One Room");
}
