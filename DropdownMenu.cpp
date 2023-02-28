//
// Created by xiwen on 4/30/2021.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu() :DropdownMenu({0,0})
{

}

DropdownMenu::DropdownMenu(sf::Vector2f vector2F)
{
    setPosition(vector2F);
    itemList.add_option("OpenSans Bold");
    itemList.add_option("Garlando");
    itemList.add_option("Black Gunslinger");
    itemList.add_option("COXXON");
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox);
    if(States::isStateEnable(ShowMenu))
        window.draw(itemList);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    const bool debug = true;

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

    if(Keyboard_Shortcuts::isUndo())
    {
        if(!History::empty() && History::topHistory().getID() == 'm')
        {
            if(debug)
                std::cout << "Top: " << History::topHistory().getString();
            applySnapshot(History::topHistory());
            History::popHistory();
        }
        disableState(Undo);
    }
}

void DropdownMenu::update()
{
    inputBox.setText(itemList.getTop());

    inputBox.update();
    itemList.update();
}

Snapshot &DropdownMenu::getSnapshot()
{
    return inputBox.getSnapshot();
}

void DropdownMenu::applySnapshot(const Snapshot &snapshot)
{
    itemList.applySnapshot(snapshot);
}

std::string DropdownMenu::getItem() {
    return inputBox.getString();
}

void DropdownMenu::setPosition(sf::Vector2f vector2F) {
    inputBox.setPos(vector2F);
    itemList.setDefaultOnTop(inputBox.getGlobalBounds());
}

