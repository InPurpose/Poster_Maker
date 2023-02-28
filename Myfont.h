//
// Created by xiwen on 4/10/2021.
//

#ifndef SFML_PROJECT_MYFONT_H
#define SFML_PROJECT_MYFONT_H
#include <SFML/Graphics.hpp>
#include <map>

class Myfont{
private:
    static bool set;
//    static sf::Font font;
    static void setFont();
    static std::map<std::string,sf::Font> font_list;
public:
    static sf::Font& getFont();
    static sf::Font& getFont(std::string fontName);

};

#endif //SFML_PROJECT_MYFONT_H
