//
// Created by xiwen on 4/11/2021.
//

#include "Box.h"

Box::Box()
{
    setSize(original_size);
    setPosition({55,55});
    setFillColor(sf::Color::Black);
    setOutlineThickness(3);
    setOutlineColor(sf::Color::White);
}

void Box::setOutColor(sf::Color color) {
    setOutlineColor(color);
}

void Box::zoom(int counter)
{
    setSize({getSize().x, original_size.y * counter});
}
