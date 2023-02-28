//
// Created by xiwen on 5/30/2021.
//

#include "Slider.h"

Slider::Slider() : Slider("Empty")
{


}

Slider::Slider(std::string name) {
    label.setFont(Myfont::getFont());
    label.setFillColor(sf::Color::White);
    label.setString(name);
    label.setCharacterSize(24);

    value.setFont(Myfont::getFont());
    value.setCharacterSize(24);
    value.setFillColor(sf::Color::White);
    value.setString("0");

    line.setSize({400,4});
    line.setFillColor(sf::Color::White);

    knob.setRadius(12);
    knob.setFillColor(sf::Color::White);

    initial_left = 24;
    initial_right = 72;
    setPosition({50,50});
    center();
}

void Slider::center() {
    sf::Vector2f pos = line.getPosition();
    pos.y = line.getGlobalBounds().top - (knob.getGlobalBounds().height - line.getGlobalBounds().height)/2;
    knob.setPosition(pos);

}

void Slider::setInit(const int left, const int right) {
    initial_left = left;
    initial_right = right;
}

void Slider::setPosition(sf::Vector2f vector2F)
{
    label.setPosition(vector2F);
    sf::FloatRect labelGb = label.getGlobalBounds();
    line.setPosition({labelGb.left+labelGb.width+5,labelGb.top+labelGb.height/2});
    knob.setPosition(line.getPosition());
    sf::FloatRect lineGb = line.getGlobalBounds();
    value.setPosition({lineGb.left+lineGb.width+5,label.getPosition().y+5});
    center();
}

void Slider::setString(std::string s1) {
    label.setString(s1);
    setPosition(label.getPosition());
}

int Slider::getValue() {
   float temp;
   temp = (knob.getPosition().x - line.getPosition().x) /(line.getGlobalBounds().width - 24);

   temp *= (initial_right-initial_left);
//   std::cout << (int)temp << "\n";
   return (int)temp + initial_left;
}


void Slider::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(label);
    window.draw(line);
    window.draw(knob);
    window.draw(value);
}

// from EventHandler
void Slider::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    const bool debug = false;
    if(MouseEvents<sf::CircleShape>::draggedOver(knob,window,event)) {
        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
        sf::FloatRect getGb = line.getGlobalBounds();
        if (debug) {
            std::cout << "dragging knob: " << knob.getPosition().x << "\n";
            std::cout << "{" << mpos.x << "," << mpos.y << "}\n";
            std::cout << (float) sf::Mouse::getPosition().x << "\n";
        }

        if (mpos.x < line.getPosition().x - 4) {
            knob.setPosition(line.getPosition().x - 4, knob.getPosition().y);
            return;
        }

        if (mpos.x > getGb.left + getGb.width - 23) {
            knob.setPosition({getGb.left + getGb.width - 24, knob.getPosition().y});
            return;
        }

        knob.setPosition({mpos.x-4, knob.getPosition().y});

        if(knob.getPosition().x <line.getPosition().x)
        {
            knob.setPosition(line.getPosition());
            center();
        }
    }
}

void Slider::update()
{
    if(value.getString() != std::to_string(getValue()))
        value.setString(std::to_string(getValue()));
}

//from SnapshotInterface
Snapshot& Slider::getSnapshot(){}
void Slider::applySnapshot(const Snapshot& snapshot){}







