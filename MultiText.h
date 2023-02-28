//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_MULTITEXT_H
#define SFML_PROJECT_MULTITEXT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "LinkedList.h"
#include "GUIComponents.h"
#include "Myfont.h"
#include "ChangeColor.h"
#include "History.h"

class MultiText : public GUIComponents{
private:
    LinkedList<sf::Text> list;
    sf::Text text1;
    sf::Vector2f origin;
    sf::Vector2f LastCharPosition;
    int returnCounter = 1;
public:
    int getReturnCounter() const;

private:
    std::string EndStr();
public:
    MultiText();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::FloatRect getGlobalBound();

    void Insert(char letter);
    void Insert(std::string string1);
    void NewLine(char letter);

    void setPosition(sf::Vector2f vector2F);

    const sf::Vector2f &getLastCharPosition() const;
};


#endif //SFML_PROJECT_MULTITEXT_H
