//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_TYPING_H
#define SFML_PROJECT_TYPING_H
#include "MultiText.h"

class Typing : public sf::Text{
private:
    std::string string1;
    MultiText multiText;
    sf::Vector2f origin;
public:
    Typing();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
    //from SnapshotInterface
    virtual Snapshot& getSnapshot() const;
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::FloatRect getGlobalBound();
    bool List_empty();
    void setPosition(sf::Vector2f vector2F);
    int getReturnCounter() const;
    std::string getString();
    void setStr(std::string string1);
    void newLine();
    sf::Vector2f getPos() const;
};


#endif //SFML_PROJECT_TYPING_H
