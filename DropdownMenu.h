//
// Created by xiwen on 4/30/2021.
//

#ifndef SFML_PROJECT_DROPDOWNMENU_H
#define SFML_PROJECT_DROPDOWNMENU_H
#include "ItemList.h"
#include "InputBox.h"
#include "MouseEvents.h"
#include "Keyboard_Shortcuts.h"
#include "Window_Dialog.h"

class DropdownMenu : public GUIComponents{
private:
    InputBox inputBox;
    ItemList itemList;
public:
    DropdownMenu();
    DropdownMenu(sf::Vector2f vector2F);
    std::string getItem();
    void setPosition(sf::Vector2f vector2F);
    //  ======================================================================
//  Gui components
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //SFML_PROJECT_DROPDOWNMENU_H
