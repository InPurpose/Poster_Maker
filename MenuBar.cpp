//
// Created by xiwen on 5/5/2021.
//

#include "MenuBar.h"

MenuBar::MenuBar()
{
    Menu temp1,temp2,temp3;
    temp1.rename("File");
    temp2.rename("Edit");
    temp3.rename("Render");

    temp1.add_option("New File");
    temp1.add_option("Open File");
    temp1.add_option("Save File");
    temp1.add_option("Close File");


    temp2.add_option("Undo");
    temp2.add_option("Load Icon");

    list.InsertTail(temp1);
    list.InsertTail(temp2);
    list.InsertTail(temp3);

    Todo["Open File"] = false;
    Todo["Close File"] = false;
    Todo["Save File"] = false;
    Todo["New File"] = false;
    Todo["Load Icon"] = false;
    Todo["Undo"] = false;
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    const bool debug = false;
    int counter = 0;

    LinkedList<Menu>::iterator iter = list.begin();
    for(;iter != list.end();++iter)
    {
        window.draw(*iter);
        counter++;
    }
    if(debug)
        std::cout << counter << "\n";
}

void MenuBar::add_item(unsigned int MenuNumber, std::string ItemName) {
    LinkedList<Menu>::iterator iter;
    for(iter = list.begin();iter != list.end();++iter)
    {
        if(iter == list.begin())
        {
            (*iter).SetBoxPos({0, 0});
        }
        else
        {
            sf::Vector2f pos;
            pos.x = (*(iter-1)).getGlobalBounds().left+(*(iter-1)).getGlobalBounds().width;
            pos.y = (*(iter-1)).getGlobalBounds().top+3;//+(*(iter-1)).getGlobalBounds().height;
            (*iter).SetBoxPos(pos);
        }
    }
}

void MenuBar::add_menu(std::string MenuName)
{
    int counter = 0;
    Menu temp;
    list.InsertTail(temp);
    counter++;
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    const bool debug = false;

    LinkedList<Menu>::iterator iter;
    for(iter = list.begin();iter != list.end();++iter)
    {
        if(!(*iter).getTop().empty())
        {
            Todo[(*iter).getTop()] = true;
            (*iter).cleanTop();
        }
        (*iter).addEventHandler(window,event);
    }
}

void MenuBar::update()
{
    LinkedList<Menu>::iterator iter;
    for(iter = list.begin();iter != list.end();++iter)
    {
        if(iter == list.begin())
        {
            (*iter).SetBoxPos({0, 0});
        }
        else
        {
            sf::Vector2f pos;
            pos.x = (*(iter-1)).getGlobalBounds().left+(*(iter-1)).getGlobalBounds().width;
            pos.y = (*(iter-1)).getGlobalBounds().top+3;
            (*iter).SetBoxPos(pos);
        }
        (*iter).update();
    }
}

Snapshot &MenuBar::getSnapshot() {

}

void MenuBar::applySnapshot(const Snapshot &snapshot) {

}

bool MenuBar::ClickMenu(sf::RenderWindow &window) {
    LinkedList<Menu>::iterator iter;
    for(iter = list.begin();iter != list.end();++iter)
    {
        if(MouseEvents<Menu>::mouseClicked(*iter,window))
            return true;
    }
    return false;
}

bool MenuBar::checkClick(std::string ItemName) {
    return Todo[ItemName];
}

void MenuBar::disableMenu(std::string ItemName) {
    Todo[ItemName] = false;
}

