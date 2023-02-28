//
// Created by xiwen on 4/30/2021.
//

#include "InputBox.h"

InputBox::InputBox() {
    display.setString("Menu");
    setPos({0,0});
    string1 = display.getString();
}

void InputBox::applyStr(std::string s1)
{
    display.setString(s1);
}

sf::FloatRect InputBox::getGlobalBounds() {
    return display.getGlobalBounds();
}

void InputBox::setText(std::string string1) {
    display.setString(string1);
}

void InputBox::setPos(sf::Vector2f vector2F)
{
    display.setPosition(vector2F);
}

sf::Vector2f InputBox::getTwof()
{
    return display.getSize();
}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(display);
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void InputBox::update()
{
    display.update();
    if(display.getString() != string1)
    {
        History::pushHistory(getSnapshot());
        string1 = display.getString();
    }
}

Snapshot &InputBox::getSnapshot()
{
    Snapshot* snapshot = new Snapshot;

    snapshot->setString(display.getString());
    snapshot->setID('m');
    return *snapshot;
}

void InputBox::applySnapshot(const Snapshot &snapshot)
{
    std::cout << "got you.\n";
    display.setString(snapshot.getString());
}

std::string InputBox::getString() {
    return string1;
}


