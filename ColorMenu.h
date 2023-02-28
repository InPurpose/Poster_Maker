//
// Created by xiwen on 6/7/2021.
//

#ifndef SFML_PROJECT_COLORMENU_H
#define SFML_PROJECT_COLORMENU_H
#include "ColorSquare.h"
#include "Myfont.h"
#include <map>

class ColorMenu : public GUIComponents{
private:
    sf::Text label;
    sf::RectangleShape box;
    sf::RectangleShape background;
    std::map<std::string,sf::RectangleShape> colorPicker;
    ColorSquare colorSquare;

    void addColor(std::string name, sf::Color color1);
    void reposit();
public:
    ColorMenu();
    void setString(std::string name);
    void setPosition(sf::Vector2f position);
    sf::Color getColor() const;
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


#endif //SFML_PROJECT_COLORMENU_H
