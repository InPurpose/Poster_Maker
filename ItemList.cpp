//
// Created by xiwen on 4/30/2021.
//

#include "ItemList.h"

ItemList::ItemList() {

}

void ItemList::add_option(std::string s1)
{
    Item temp(s1);
    sf::Vector2f pos = LastPosition();
    temp.setPosition(pos);
//    tree.push(temp);
    list.InsertTail(temp);
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
//    tree.inorder(window);
    LinkedList<Item>::iterator iter = list.begin();
    for(;iter != list.end();++iter)
    {
        window.draw(*iter);
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    LinkedList<Item>::iterator iter = list.begin();
    for(;iter != list.end();++iter)
    {
        (*iter).addEventHandler(window,event);
        if(MouseEvents<Item>::hovered(*iter, window))
            (*iter).setColor(sf::Color::Blue);
        else
            (*iter).setColor(sf::Color::Black);

        if(MouseEvents<Item>::mouseClicked(*iter, window))
        {
            goTop = (*iter).getString();
            return;
        }
    }
}

void ItemList::update()
{
    LinkedList<Item>::iterator iter = list.begin();
    for(;iter != list.end();++iter)
    {
        if(iter == list.begin())
        {
            sf::Vector2f pos;
            pos.x = DefaultOnTop.left;
            pos.y = DefaultOnTop.top + DefaultOnTop.height;
            (*iter).setPosition(pos);
        }
        else
        {
            sf::Vector2f pos;
            pos.x = (*(iter-1)).getGlobalBounds().left;
            pos.y = (*(iter-1)).getGlobalBounds().top + (*(iter-1)).getGlobalBounds().height;
            (*iter).setPosition(pos);
        }
    }
}

Snapshot &ItemList::getSnapshot() {

}

void ItemList::applySnapshot(const Snapshot &snapshot)
{
    goTop = snapshot.getString();
}

sf::Vector2f ItemList::LastPosition() {
    sf::Vector2f pos;
    if(list.empty())
    {
        pos.x = DefaultOnTop.left;
        pos.y = DefaultOnTop.top + DefaultOnTop.height;
    }
    else
    {
        LinkedList<Item>::iterator iter = list.LastOne();
        pos.x = (*iter).getGlobalBounds().left;
        pos.y = (*iter).getGlobalBounds().top + (*iter).getGlobalBounds().height;
    }
    return pos;
}

std::string ItemList::getTop() {
    return goTop;
}

void ItemList::cleanTop() {
    goTop.clear();
}

void ItemList::simple_draw(sf::RenderTarget& window, Item& item) const
{
    window.draw(item);
}


void ItemList::setDefaultOnTop(const sf::FloatRect &defaultOnTop) {
    DefaultOnTop = defaultOnTop;
}

sf::FloatRect ItemList::getGlobalBounds()
{
    sf::FloatRect temp = {0,0,0,0};
    LinkedList<Item>::iterator iter = list.begin();
    for(;iter != list.end();++iter)
    {
        temp.height += (*iter).getGlobalBounds().height;
    }
    return temp;
}


