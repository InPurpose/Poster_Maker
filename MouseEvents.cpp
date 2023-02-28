//
// Created by xiwen on 4/8/2021.
//

#ifndef MIDTERM_MOUSEEVENTS_CPP
#define MIDTERM_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<class T>
int MouseEvents<T>::clicks = 0;

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window)//worked
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(object.getGlobalBounds().contains(mpos))
            return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event)//worked
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
            return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(object.getGlobalBounds().contains(mpos) && event.MouseMoved)
            return true;
    }
//    if (event.type == sf::Event::MouseButtonPressed)
//    {
//        if(object.getGlobalBounds().contains(mpos) && event.MouseMoved)
//            return true;
//    }
    return false;
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window)//work
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    if(object.getGlobalBounds().contains(mpos))
        return true;

    return false;
}



#endif

