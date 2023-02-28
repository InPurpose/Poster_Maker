//
// Created by xiwen on 4/10/2021.
//

#include "Keyboard_Shortcuts.h"

bool Keyboard_Shortcuts::isUndo() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        return true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        return true;

    return false;
}
