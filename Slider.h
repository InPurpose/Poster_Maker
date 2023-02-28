//
// Created by xiwen on 5/30/2021.
//

#ifndef SFML_PROJECT_SLIDER_H
#define SFML_PROJECT_SLIDER_H
#include <SFML/Graphics.hpp>
#include "GUIComponents.h"
#include "MouseEvents.h"
#include "Myfont.h"

class Slider : public GUIComponents{
private:
    sf::RectangleShape line;
    sf::CircleShape knob;
    float initial_left;
    float initial_right;
    sf::Text label;//change to label class, maybe?
    sf::Text value;
    void center();
public:
    Slider();
    Slider(std::string name);
    void setInit(const int left, const int right);
    void setPosition(sf::Vector2f vector2F);
    void setString(std::string s1);
    int getValue();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
//    virtual sf::FloatRect getGlobalBound() = 0;
};


#endif //SFML_PROJECT_SLIDER_H
