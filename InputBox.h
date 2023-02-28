//
// Created by xiwen on 4/30/2021.
//

#ifndef SFML_PROJECT_INPUTBOX_H
#define SFML_PROJECT_INPUTBOX_H
#include "Item.h"
#include "History.h"

class InputBox : public GUIComponents{
private:
    Item display;
    std::string string1;
public:
    InputBox();

    void applyStr(std::string s1);

    void setText(std::string string1);
    void setPos(sf::Vector2f vector2F);

    sf::FloatRect getGlobalBounds();
    sf::Vector2f getTwof();

    std::string getString();

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


#endif //SFML_PROJECT_INPUTBOX_H
