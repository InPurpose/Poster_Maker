//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_TEXTINPUT_H
#define SFML_PROJECT_TEXTINPUT_H
#include "GUIComponents.h"
#include "Typing.h"
#include "MouseEvents.h"
#include "Cursor.h"
#include "Label.h"
#include "Box.h"

class TextInput : public GUIComponents{
private:
    Box box;
    Typing typing;
    Cursor cursor;
    Label label;
    sf::Vector2f origin;
//    void setPosition(sf::Vector2f vector2F);
public:
    TextInput();
    TextInput(sf::Vector2f vector2F);

    std::string getString();
    void setString(std::string string1);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
//    virtual sf::FloatRect getGlobalBound() = 0;


//set label
    void setLabel(std::string s1);

    void setLabelSize(int size);
    void setLabelMargin(sf::FloatRect floatRect);
    void setPosition(sf::Vector2f vector2F);
};


#endif //SFML_PROJECT_TEXTINPUT_H
