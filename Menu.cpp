//
// Created by xiwen on 5/5/2021.
//

#include "Menu.h"

Menu::Menu()
{
    itemList.setDefaultOnTop(inputBox.getGlobalBounds());
    Top.clear();
}


void Menu::SetBoxPos(sf::Vector2f vector2F)
{
    inputBox.setPos(vector2F);
    itemList.setDefaultOnTop(inputBox.getGlobalBounds());

}

void Menu::add_option(std::string string1)
{
    itemList.add_option(string1);
}


sf::FloatRect Menu::getGlobalBounds()
{
    return inputBox.getGlobalBounds();
}


//  ======================================================================
//  Gui components
void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox);

    if(States::isStateEnable(ShowMenu))
    {
//        std::cout << "ShowMenu is enable.\n";
        window.draw(itemList);
    }
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    const bool debug = false;

    inputBox.addEventHandler(window,event);
    if(MouseEvents<InputBox>::mouseClicked(inputBox,window))
    {
        if(debug)
            std::cout << "Inputbox get clicked.\n";

        if(States::isStateEnable(ShowMenu))
            States::disableState(ShowMenu);
        else
            States::enableState(ShowMenu);
    }

    if(States::isStateEnable(ShowMenu))
    {
        itemList.addEventHandler(window,event);
    }

    if(!MouseEvents<InputBox>::mouseClicked(inputBox,window)
       && MouseEvents<InputBox>::mouseClicked(window,event))
    {
        if(debug)
            std::cout << "Clicked outside the inputbox.\n";
        if(States::isStateEnable(ShowMenu))
            States::disableState(ShowMenu);
    }
}

void Menu::update()
{
    itemList.update();
    if(!itemList.getTop().empty())
    {
//        std::cout << itemList.getTop() << "\n";
        Top = itemList.getTop();
        itemList.cleanTop();
    }
}

Snapshot &Menu::getSnapshot() {

}

void Menu::applySnapshot(const Snapshot &snapshot) {

}

void Menu::rename(std::string NewName)
{
    inputBox.setText(NewName);
}

std::string Menu::getTop() {
    return Top;
}

void Menu::cleanTop() {
    Top.clear();
}

