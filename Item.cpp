//
// Created by xiwen on 4/30/2021.
//

#include "Item.h"

Item::Item() : Item("")
{

}

Item::Item(std::string s1):Item(s1,{0,0})
{

}


Item::Item(std::string s1, sf::Vector2f pos) {
    text1.setFillColor(sf::Color::White);
    text1.setFont(Myfont::getFont());
    text1.setCharacterSize(24);
    text1.setString(s1);

    box.setFillColor(sf::Color::Black);
    box.setSize({200,40});
    setPosition(pos);

    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(3);
}


void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(box);
    window.draw(text1);
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Item::update()
{
    adjust_text();
}

Snapshot &Item::getSnapshot() {}

void Item::applySnapshot(const Snapshot &snapshot) {}

void Item::setPosition(sf::Vector2f v2f)
{
    v2f.x+=3;
    box.setPosition(v2f);
    adjust_text();
}

void Item::setString(std::string s1)
{
    text1.setString(s1);
}

sf::FloatRect Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void Item::setColor(sf::Color color) {
    box.setFillColor(color);
}

std::string Item::getString() {
    return text1.getString();
}

bool operator <=(const Item &left, const Item &right) {
    return left.text1.getString() <= right.text1.getString();
}

sf::Vector2f Item::getSize() {
    return box.getSize();
}

void Item::adjust_text()
{
    sf::Vector2f pos = box.getPosition();
    pos.x = box.getGlobalBounds().left + (box.getGlobalBounds().width - text1.getGlobalBounds().width)/2;
    pos.y = box.getGlobalBounds().top + (box.getGlobalBounds().height - text1.getGlobalBounds().height)/2;

    if(text1.getGlobalBounds().width <= box.getGlobalBounds().width)
        text1.setPosition(pos);
    else
        text1.setPosition(box.getPosition());
}

bool operator!=(const Item &left, const Item &right) {
    if(left.box.getGlobalBounds() != right.box.getGlobalBounds())
        if(left.text1.getString() != right.text1.getString())
            return true;

    return false;
}

bool operator == (const Item &left, const Item &right) {
    if(left.box.getGlobalBounds() == right.box.getGlobalBounds())
        if(left.text1.getString() == right.text1.getString())
            return true;

    return false;
}

void Item::setSize(sf::Vector2f size) {
    box.setSize(size);
}

void Item::setOutlineColor(sf::Color color) {
    box.setOutlineColor(color);
}



