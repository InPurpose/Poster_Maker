//
// Created by xiwen on 5/5/2021.
//

#ifndef SFML_PROJECT_MENUBAR_H
#define SFML_PROJECT_MENUBAR_H
#include "Menu.h"
#include <map>

class MenuBar : public GUIComponents{
private:
    LinkedList<Menu> list;
    std::map<std::string, bool> Todo;
public:
    MenuBar();

    void add_item(unsigned int MenuNumber,std::string ItemName);
    void add_menu(std::string MenuName);

    bool ClickMenu(sf::RenderWindow &window);

    bool checkClick(std::string ItemName);
    void disableMenu(std::string ItemName);
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


#endif //SFML_PROJECT_MENUBAR_H
