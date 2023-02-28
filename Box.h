//
// Created by xiwen on 4/11/2021.
//

#ifndef SFML_PROJECT_BOX_H
#define SFML_PROJECT_BOX_H
#include <SFML/Graphics.hpp>

class Box : public sf::RectangleShape {
private:
    sf::Vector2f original_size = {600, 50};
public:
    Box();

    void setOutColor(sf::Color color);
    void zoom(int counter);

};

#endif //SFML_PROJECT_BOX_H
