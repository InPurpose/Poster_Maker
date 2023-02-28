//
// Created by xiwen on 4/9/2021.
//

#include "MultiText.h"

MultiText::MultiText()
{
    text1.setFont(Myfont::getFont());
    text1.setFillColor(sf::Color::White);
    text1.setCharacterSize(36);
}

void MultiText::addEventHandler(sf::RenderWindow& window, sf::Event event)
{

}

void MultiText::update()
{
    LinkedList<sf::Text>::iterator iter = list.begin();
    for(;iter != list.end();++iter)
    {
        ChangeColor::colorChange(iter);
    }
}

void MultiText::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    LinkedList<sf::Text>::iterator iter = list.begin();
    for(;iter != list.end();++iter)
    {
        window.draw(*iter);
    }
}

void MultiText::Insert(char letter) {
    text1.setString(std::string(1,letter));

    LinkedList<sf::Text>::iterator iter;
    iter = list.LastOne();
    if(list.empty())
    {
        text1.setPosition(origin);
    }
    else
    {
        text1.setPosition(LastCharPosition);
//        text1.setPosition((*iter).getGlobalBounds().left + (*iter).getGlobalBounds().width,origin.y*returnCounter);
    }

    list.InsertTail(text1);
    if(text1.getString() != "\n")
    {
        LastCharPosition.x = text1.getGlobalBounds().left + text1.getGlobalBounds().width;
    }
    else
    {
        LastCharPosition.x= origin.x;
    }
    LastCharPosition.y = origin.y*returnCounter;
}

void MultiText::Insert(std::string string1)
{
    list.clear();
    returnCounter = 1;
    for (int i = 0; i < string1.length(); ++i)
    {
        if(string1[i] == '\n')
        {
            returnCounter++;
        }

        Insert(string1[i]);

    }
}


void MultiText::NewLine(char letter)
{
    text1.setString(std::string(1,letter));
//    origin.y *=returnCounter;

    text1.setPosition(origin.x,origin.y);
    list.InsertTail(text1);
}

sf::FloatRect MultiText::getGlobalBound()
{
    if(list.empty())
    {
        return {56,60,0,0};
    }
    else
    {
        LinkedList<sf::Text>::iterator iter = list.LastOne();
        sf::FloatRect floatRect;
        floatRect = (*iter).getGlobalBounds();
        floatRect.left += (*iter).getGlobalBounds().width;
        return floatRect;
    }
}

Snapshot& MultiText::getSnapshot(){}

void MultiText::applySnapshot(const Snapshot& snapshot){}

void MultiText::setPosition(sf::Vector2f vector2F)
{
    origin = vector2F;
    LastCharPosition = vector2F;
}

std::string MultiText::EndStr() {
    sf::Text temp = *list.LastOne();
    return temp.getString();
}

int MultiText::getReturnCounter() const {
    return returnCounter;
}

const sf::Vector2f &MultiText::getLastCharPosition() const
{
    return LastCharPosition;
}
