//
// Created by xiwen on 4/10/2021.
//

#include "Myfont.h"

//sf::Font Myfont::font;
bool Myfont::set = false;
std::map<std::string,sf::Font> Myfont::font_list;

sf::Font& Myfont::getFont()
{
    if(!set)
    {
        setFont();
        set = true;
    }
    return font_list["OpenSans Bold"];
}

void Myfont::setFont()
{
//    if(!font.loadFromFile("Fonts/OpenSans-Bold.ttf"))
//    {
//        exit (1);
//    }

    if(!font_list["OpenSans Bold"].loadFromFile("Fonts/OpenSans-Bold.ttf"))
        exit(1);
    if(!font_list["Garlando"].loadFromFile("Fonts/Garlando.ttf"))
        exit(1);
    if(!font_list["COXXON"].loadFromFile("Fonts/COXXON.ttf"))
        exit(1);
    if(!font_list["Black Gunslinger"].loadFromFile("Fonts/Black Gunslinger.ttf"))
        exit(1);
}

sf::Font &Myfont::getFont(std::string fontName)
{
    if(!set)
    {
        setFont();
        set = true;
    }
    return font_list[fontName];
}
