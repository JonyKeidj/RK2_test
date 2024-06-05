#include <iostream>
#include <memory>
#include <string>

// Структура Color для представления цвета
struct Color
{
    Color(std::uint8_t R, std::uint8_t G, std::uint8_t B)
        : R(R), G(G), B(B)
    {}

    std::uint8_t R, G, B;
};

// Абстрактный класс Theme
class Theme
{
public:
    virtual ~Theme() = default;

    virtual std::string Name() const = 0;
    virtual Color WallColor() const = 0;
    virtual Color FloorColor() const = 0;
    virtual Color CeilingColor() const = 0;
};

// Класс WhiteTheme, наследующий Theme
class WhiteTheme : public Theme
{
public:
    std::string Name() const override { return "White Theme"; }
    Color WallColor() const override { return { 255, 255, 255 }; }
    Color FloorColor() const override { return { 255, 255, 255 }; }
    Color CeilingColor() const override { return { 255, 255, 255 }; }
};

// Класс DarkTheme, наследующий Theme
class DarkTheme : public Theme
{
public:
    std::string Name() const override { return "Dark Theme"; }
    Color WallColor() const override { return { 0, 0, 0 }; }
    Color FloorColor() const override { return { 0, 0, 0 }; }
    Color CeilingColor() const override { return { 0, 0, 0 }; }
};

// Класс CustomTheme, наследующий Theme
class CustomTheme : public Theme
{
public:
    CustomTheme(std::string name, Color wallColor, Color floorColor, Color ceilingColor)
        : name_(std::move(name)), wallColor_(wallColor), floorColor_(floorColor), ceilingColor_(ceilingColor)
    {}

    std::string Name() const override { return name_; }
    Color WallColor() const override { return wallColor_; }
    Color FloorColor() const override { return floorColor_; }
    Color CeilingColor() const override { return ceilingColor_; }

private:
    std::string name_;
    Color wallColor_, floorColor_, ceilingColor_;
};

// Абстрактный класс House
class House
{
public:
    explicit House(std::shared_ptr<Theme> theme)
        : theme_(std::move(theme))
    {}
    virtual ~House() = default;

    virtual std::string Name() const = 0;

    void ChangeTheme(std::shared_ptr<Theme> const& theme) 
    {
        std::cout << Name() << " changes theme to '" << theme->Name() << "'." << std::endl;
        theme_ = theme; 
    }

    void ShowDescription() const
    {
        std::cout << Name() << " with theme('" << theme_->Name() << "')." << std::endl;
    }

private:
    std::shared_ptr<Theme> theme_;
};

// Класс OneRoom, наследующий House
class OneRoom : public House
{
public:
    using House::House;

    std::string Name() const override { return "One Room"; }
};

// Класс Apartment, наследующий House
class Apartment : public House
{
public:
    using House::House;

    std::string Name() const override { return "Apartment"; }
};

// Класс Castle, наследующий House
class Castle : public House
{
public:
    using House::House;

    std::string Name() const override { return "Castle"; }
};
