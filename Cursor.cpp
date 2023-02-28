//
// Created by xiwen on 4/9/2021.
//

#include "Cursor.h"

void Cursor::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
//    if(isStateEnable(Blinking))
    if(blink_switch)
        window.draw(cursor);
}

Cursor::Cursor()
{
    cursor.setSize({2.5, 48});
    cursor.setPosition({60,60});
    cursor.setFillColor(sf::Color::White);
}

void Cursor::update()
{
    if(clock.getElapsedTime().asMicroseconds() > speed)
    {
        blink();
        clock.restart();
    }
}

void Cursor::blink()
{
    if(blink_switch)
        blink_switch = false;
    else
        blink_switch = true;
}

Snapshot& Cursor::getSnapshot(){}

void Cursor::applySnapshot(const Snapshot& snapshot){}

void Cursor::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

}

void Cursor::setPos(sf::Vector2f vector2F,int counter)
{
    cursor.setPosition(vector2F);
}
