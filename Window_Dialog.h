//
// Created by xiwen on 6/4/2021.
//

#ifndef SFML_PROJECT_WINDOW_DIALOG_H
#define SFML_PROJECT_WINDOW_DIALOG_H
#include "SFML/Graphics.hpp"
#include "Item.h"
#include "MouseEvents.h"
#include <map>
#include "FileTree.h"


class Window_Dialog : public GUIComponents{
private:
    FileTree tree;
    std::string name;
public:
    Window_Dialog();
    void open();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    virtual void applySnapshot(const Snapshot& snapshot);
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    std::string getImg();
};


#endif //SFML_PROJECT_WINDOW_DIALOG_H
