//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_GUICOMPONENTS_H
#define SFML_PROJECT_GUICOMPONENTS_H

#include "EventHandler.h"
#include "States.h"
#include "SnapshotInterface.h"

class GUIComponents : public sf::Drawable, public sf::Transformable,
                      public EventHandler, public SnapshotInterface, public States{
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
//    virtual sf::FloatRect getGlobalBound() = 0;

private:

};


#endif //SFML_PROJECT_GUICOMPONENTS_H
