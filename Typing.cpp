//
// Created by xiwen on 4/9/2021.
//

#include "Typing.h"

Typing::Typing() {

}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    const bool debug = false;
    if (event.type == sf::Event::TextEntered)
    {
        if(event.text.unicode == 8)
        {
            if (string1.length() > 0)
                string1.erase(string1.length() - 1, 1);
        }
        else if (event.text.unicode < 128 && event.text.unicode >=32)
        {
            if(string1.size() < 28)
                string1 += event.text.unicode;
        }

        if(event.text.unicode == 13 || getPos().x > 1290)
        {
            string1 += "\n";
        }

        multiText.Insert(string1);

        History::pushHistory(getSnapshot());

        if(debug)
            std::cout << "Top: " << History::topHistory().getString();

        for (int i = 0; i < string1.length(); ++i)
        {
            std::cout << string1[i];
        }

        std::cout << "string size: " << string1.size() << std::endl;

    }
}

void Typing::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(multiText);
}

void Typing::update()
{
    multiText.update();
}

Snapshot& Typing::getSnapshot() const
{
    Snapshot* snapshot = new Snapshot;

    snapshot->setString(string1);
    snapshot->setID('t');
    return *snapshot;
}

void Typing::applySnapshot(const Snapshot& snapshot)
{
    string1 = snapshot.getString();
}

sf::FloatRect Typing::getGlobalBound() {
    return multiText.getGlobalBound();
}

bool Typing::List_empty() {
    return string1.length() == 0;
}

void Typing::setPosition(sf::Vector2f vector2F)
{
    origin = vector2F;
    multiText.setPosition(vector2F);
}

int Typing::getReturnCounter() const {
    return multiText.getReturnCounter();
}

sf::Vector2f Typing::getPos() const {
    return multiText.getLastCharPosition();
}

std::string Typing::getString() {
    return string1;
}

void Typing::setStr(std::string string1) {
    this->string1 = string1;
    multiText.Insert(this->string1);
}


