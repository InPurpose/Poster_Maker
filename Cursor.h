//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_CURSOR_H
#define SFML_PROJECT_CURSOR_H
#include "GUIComponents.h"
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"

class Cursor : public GUIComponents{
private:
    sf::RectangleShape cursor;
    bool blink_switch = false;
    sf::Clock clock;
    int speed = 500;
public:
    Cursor();
    void setPos(sf::Vector2f vector2F,int counter);

    void blink();

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

};


#endif //SFML_PROJECT_CURSOR_H
