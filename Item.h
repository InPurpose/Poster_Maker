//
// Created by xiwen on 4/30/2021.
//

#ifndef SFML_PROJECT_ITEM_H
#define SFML_PROJECT_ITEM_H
#include "Box.h"
//#include "Typing.h"
#include "GUIComponents.h"
#include "Myfont.h"
#include "MouseEvents.h"

class Item : public GUIComponents{
private:
    sf::RectangleShape box;
    sf::Text text1;
public:
    Item();
    Item(std::string s1);
    Item(std::string s1,sf::Vector2f pos);

    friend bool operator==(const Item& left,const Item& right);
    friend bool operator<=(const Item& left,const Item& right);
    friend bool operator!=(const Item& left,const Item& right);

    void setPosition(sf::Vector2f v2f);
    void setString(std::string s1);
    void setSize(sf::Vector2f size);
    void setOutlineColor(sf::Color color);

    sf::Vector2f getSize();
    sf::FloatRect getGlobalBounds() const;
    void setColor(sf::Color color);
    std::string getString();

    void adjust_text();

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


#endif //SFML_PROJECT_ITEM_H
