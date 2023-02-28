//
// Created by xiwen on 4/11/2021.
//

#include "Label.h"

Label::Label() {
    setFont(Myfont::getFont());
    setColor(sf::Color::White);
    setstring("");
    setCharacterSize(24);
    setposition({0,0});
}

void Label::setposition(sf::Vector2f vector2F) {
    setPosition(vector2F);
}

void Label::setsize(int size) {
    setCharacterSize(size);
}

void Label::setstring(std::string string1) {
    setString(string1);
}

void Label::setColor(sf::Color color) {
    setFillColor(color);
}
