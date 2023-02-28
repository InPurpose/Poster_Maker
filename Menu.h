//
// Created by xiwen on 5/5/2021.
//

#ifndef SFML_PROJECT_MENU_H
#define SFML_PROJECT_MENU_H

#include "InputBox.h"
#include "ItemList.h"

class Menu : public GUIComponents{
private:
    InputBox inputBox;
    ItemList itemList;
    std::string Top;
public:
    Menu();
    void rename(std::string NewName);
    void SetBoxPos(sf::Vector2f vector2F);
    void add_option(std::string string1);
    sf::FloatRect getGlobalBounds();

    std::string getTop();
    void cleanTop();
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


#endif //SFML_PROJECT_MENU_H
