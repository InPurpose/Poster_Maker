//
// Created by xiwen on 4/30/2021.
//

#ifndef SFML_PROJECT_ITEMLIST_H
#define SFML_PROJECT_ITEMLIST_H
#include "Item.h"
#include "Binary_Tree.h"
#include "LinkedList.h"
//#include "Node_Iterator.h"
#include "MouseEvents.h"

class ItemList : public GUIComponents {
private:
//    Binary_Tree<Item> tree;
    LinkedList<Item> list;
    sf::FloatRect DefaultOnTop = {0,0,0,0};
    sf::Vector2f LastPosition();
    std::string goTop = "OpenSans Bold";
public:

    ItemList();

    void setDefaultOnTop(const sf::FloatRect &defaultOnTop);
    void add_option(std::string s1);
    void simple_draw(sf::RenderTarget& window, Item& item) const;
    std::string getTop();
    void cleanTop();
    sf::FloatRect getGlobalBounds();
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


#endif //SFML_PROJECT_ITEMLIST_H
