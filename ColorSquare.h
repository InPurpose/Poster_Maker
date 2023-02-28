//
// Created by xiwen on 6/7/2021.
//

#ifndef SFML_PROJECT_COLORSQUARE_H
#define SFML_PROJECT_COLORSQUARE_H
#include <SFML/Graphics.hpp>
#include "GUIComponents.h"
#include "MouseEvents.h"
#include <map>

class ColorSquare : public GUIComponents{
private:
    sf::VertexArray square;
    std::map<std::string,bool> colorInt;
    bool picked = false;
    sf::Color color;
public:
    ColorSquare();
    ColorSquare(sf::Color color);
    ColorSquare(sf::Color color,sf::Vector2f position);

    bool isPicked() const;
    void setPicked(bool picked);

    const sf::Color getColor() const;

    void setColor(sf::Color color1);
    void setPosition(sf::Vector2f position);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //This is not currently used
    virtual void applySnapshot(const Snapshot& snapshot);

    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot& getSnapshot();
    sf::FloatRect getGlobalBounds();

};


#endif //SFML_PROJECT_COLORSQUARE_H
