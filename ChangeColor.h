//
// Created by xiwen on 4/10/2021.
//

#ifndef SFML_PROJECT_CHANGECOLOR_H
#define SFML_PROJECT_CHANGECOLOR_H
#include <SFML/Graphics.hpp>
#include "Node_Iterator.h"
#include "LinkedList.h"

class ChangeColor{
public:
    static void colorChange(LinkedList<sf::Text>::iterator& iter);

private:
    static int counter;
    static bool digit(LinkedList<sf::Text>::iterator& iter);
    static bool operators(LinkedList<sf::Text>::iterator& iter);
    static int SpecialWords(LinkedList<sf::Text>::iterator& iter);

public:
//  =========================================================
//  not using
    static void colorChange(LinkedList<sf::Text>::iterator& begin,LinkedList<sf::Text>::iterator& end);

private:

    static int dynamic_counter;
    void ifDigit(LinkedList<sf::Text>::iterator& iter);
    void ifOperators(LinkedList<sf::Text>::iterator& iter);

};


#endif //SFML_PROJECT_CHANGECOLOR_H
