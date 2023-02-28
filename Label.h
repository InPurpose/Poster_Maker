//
// Created by xiwen on 4/11/2021.
//

#ifndef SFML_PROJECT_LABEL_H
#define SFML_PROJECT_LABEL_H
#include <SFML/Graphics.hpp>
#include "Myfont.h"

class Label : public sf::Text{
private:
    sf::Font font;
public:
    Label();
    void setposition(sf::Vector2f vector2F);
    void setstring(std::string string1);
    void setColor(sf::Color color);
    void setsize(int size);

};


#endif //SFML_PROJECT_LABEL_H
