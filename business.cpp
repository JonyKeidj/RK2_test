#include "business.h"

int main()
{
    OneRoom oneRoom(std::make_shared<DarkTheme>());
    oneRoom.ShowDescription();
    oneRoom.ChangeTheme(std::make_shared<WhiteTheme>());
    oneRoom.ShowDescription();

    Apartment apartment(std::make_shared<WhiteTheme>());
    apartment.ShowDescription();

    auto customTheme = std::make_shared<CustomTheme>("My Custom Theme", 
        Color(12, 34, 56), Color(78, 90, 12), Color(34, 56, 78));

    Castle castle(customTheme);
    castle.ShowDescription();
    
    apartment.ChangeTheme(customTheme);
    apartment.ShowDescription();
}
