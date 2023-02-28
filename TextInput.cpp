//
// Created by xiwen on 4/9/2021.
//

#include "TextInput.h"

TextInput::TextInput() {

}

TextInput::TextInput(sf::Vector2f vector2F)
{
    origin = vector2F;
    typing.setPosition(vector2F);
    box.setPosition(vector2F);
}

void TextInput::update()
{
    typing.update();
    cursor.update();
}


void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(box);
    window.draw(typing);
    window.draw(label);
    if(isStateEnable(Cursor_Swtich))
        window.draw(cursor);
}

void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    const bool debug = false;
    if(isStateEnable(Typable))
    {
        typing.addEventHandler(window,event);
    }

    //cursor movement

    box.zoom(typing.getReturnCounter());
    cursor.setPos(typing.getPos(),typing.getReturnCounter());

    if(MouseEvents<sf::RectangleShape>::mouseClicked(box,window))
    {
        box.setOutColor(sf::Color::Red);
        label.setColor(sf::Color::Red);

        enableState(Typable);
        enableState(Cursor_Swtich);
    }

    if(!MouseEvents<sf::RectangleShape>::mouseClicked(box,window)
        && MouseEvents<sf::RectangleShape>::mouseClicked(window,event))
    {
        box.setOutColor(sf::Color::White);
        label.setColor(sf::Color::White);

        disableState(Typable);
        disableState(Cursor_Swtich);
    }

    if(Keyboard_Shortcuts::isUndo())
    {
        enableState(Undo);
    }

    if(isStateEnable(Undo))
    {
        if(!History::empty() && History::topHistory().getID() == 't')
        {
            if(debug)
                std::cout << "Top: " << History::topHistory().getString();

            box.setOutColor(sf::Color::Red);
            label.setColor(sf::Color::Red);
            enableState(Typable);
            enableState(Cursor_Swtich);

            applySnapshot(History::topHistory());
            History::popHistory();
        }
        disableState(Undo);
    }
}

Snapshot& TextInput::getSnapshot()
{

}

void TextInput::applySnapshot(const Snapshot& snapshot)
{
    typing.applySnapshot(snapshot);
}

void TextInput::setLabelSize(int size)
{
    label.setsize(size);
}

void TextInput::setPosition(sf::Vector2f vector2F)
{
    label.setposition(vector2F);
    sf::FloatRect label_GlobalB = label.getGlobalBounds();
    box.setPosition({label_GlobalB.left+3, label_GlobalB.top + label_GlobalB.height+5});
    typing.setPosition(box.getPosition());
}

void TextInput::setLabel(std::string s1)
{
    label.setstring(s1);
}

void TextInput::setLabelMargin(sf::FloatRect floatRect)
{

}

std::string TextInput::getString() {
    return typing.getString();
}

void TextInput::setString(std::string string1)
{
    typing.setStr(string1);
}

