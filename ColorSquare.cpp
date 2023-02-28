//
// Created by xiwen on 6/7/2021.
//

#include "ColorSquare.h"

ColorSquare::ColorSquare() : ColorSquare(sf::Color::Magenta,{0,0})
{

}

ColorSquare::ColorSquare(sf::Color color): ColorSquare(color,{0,0})
{

}

ColorSquare::ColorSquare(sf::Color color, sf::Vector2f position)
{
    square.setPrimitiveType(sf::Points);
    square.resize(65536);

    setColor(color);
    setPosition(position);
}

void ColorSquare::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(square);
}


void ColorSquare::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f)sf::Mouse::getPosition(window);

    for (int i = 0; i < 256; ++i)
        for (int j = 0; j < 256; ++j)
        {
            sf::Vector2f pos = square[i*256+j].position;
            if(mpos == pos && MouseEvents<sf::VertexArray>::mouseClicked(window,event))
            {
                color = square[i*256+j].color;
                picked = true;
            }
        }
}

void ColorSquare::update() {}

Snapshot &ColorSquare::getSnapshot() {}

void ColorSquare::applySnapshot(const Snapshot &snapshot) {}

bool ColorSquare::isPicked() const {
    return picked;
}

void ColorSquare::setPicked(bool picked) {
    ColorSquare::picked = picked;
}

const sf::Color ColorSquare::getColor() const {
    return color;
}

void ColorSquare::setColor(sf::Color color1)
{
    colorInt["Red"] = (color1.r == 0);
    colorInt["Green"] = (color1.g == 0);
    colorInt["Blue"] = (color1.b == 0);

    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {

            if(colorInt["Red"])
                square[i  + j* 256].color.r = (double) j / 255 * i;
            else
                square[i  + j* 256].color.r = j;

            if(colorInt["Green"])
                square[i  + j* 256].color.g = (double) j / 255 * i;
            else
                square[i  + j* 256].color.g = j;

            if(colorInt["Blue"])
                square[i  + j* 256].color.b = (double) j / 255 * i;
            else
                square[i  + j* 256].color.b = j;
        }
    }
}

void ColorSquare::setPosition(sf::Vector2f position) {
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            square[i + j* 256 ].position = sf::Vector2f( (i+position.x),  (j+position.y));

        }
    }
}

sf::FloatRect ColorSquare::getGlobalBounds() {
    return square.getBounds();
}
