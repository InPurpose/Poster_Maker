//
// Created by xiwen on 6/7/2021.
//

#include "ColorMenu.h"

ColorMenu::ColorMenu() {
    box.setSize({40,40});
    box.setFillColor(sf::Color::Black);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(3);

    background.setSize({210,110});
    background.setFillColor(sf::Color::White);

    label.setFont(Myfont::getFont());
    label.setCharacterSize(24);
    label.setFillColor(sf::Color::White);

    addColor("Red",sf::Color::Red);
    addColor("Green",sf::Color::Green);
    addColor("Blue",sf::Color::Blue);

    addColor("Yellow",sf::Color::Yellow);
    addColor("Cyan",sf::Color::Cyan);
    addColor("Magenta",sf::Color::Magenta);

    addColor("Black",sf::Color::Black);
    addColor("White",sf::Color::White);

//    box.setSize({40,40});
////    box.setFillColor(color);
//    box.setOutlineThickness(2);
//    box.setOutlineColor(sf::Color::Black);
//    colorSquare.setColor(color);



}

sf::Color ColorMenu::getColor() const {
    return box.getFillColor();
}

void ColorMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(box);

    if(isStateEnable(ShowGrind))
        window.draw(colorSquare);

    if(isStateEnable(ShowBar))
    {
        window.draw(background);
        auto iter = colorPicker.begin();
        for(;iter != colorPicker.end();++iter)
        {
            window.draw((*iter).second);
        }
    }

}

void ColorMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {


    if(isStateEnable(ShowGrind))
    {
        colorSquare.addEventHandler(window,event);
        if(MouseEvents<ColorSquare>::mouseClicked(colorSquare,window))
            disableState(ShowGrind);
    }

    if(isStateEnable(ShowBar))
    {
        auto iter = colorPicker.begin();
        for(;iter != colorPicker.end();++iter)
        {

            if(MouseEvents<sf::RectangleShape>::mouseClicked((*iter).second,window))
            {
                colorSquare.setColor((*iter).second.getFillColor());
                enableState(ShowGrind);
            }
        }
    }

    if(MouseEvents<sf::RectangleShape>::mouseClicked(box,window))
    {
        enableState(ShowBar);
    }
    if(!MouseEvents<sf::RectangleShape>::mouseClicked(box,window)
       && MouseEvents<sf::RectangleShape>::mouseClicked(window,event))
    {
        disableState(ShowBar);
//        if(!isStateEnable(ShowGrind))
//            disableState(ShowGrind);
    }

}

void ColorMenu::update() {
    if(colorSquare.isPicked())
    {
        colorSquare.setPicked(false);
        box.setFillColor(colorSquare.getColor());
    }
}

sf::FloatRect ColorMenu::getGlobalBounds() {
    return box.getGlobalBounds();
}

Snapshot &ColorMenu::getSnapshot() {}

void ColorMenu::applySnapshot(const Snapshot &snapshot) {}

void ColorMenu::addColor(std::string name, sf::Color color1)
{
    sf::RectangleShape temp;
    temp.setSize({40,40});
    temp.setFillColor(color1);
    temp.setOutlineColor(sf::Color::Black);
    temp.setOutlineThickness(3);
    colorPicker[name] = temp;
}

void ColorMenu::reposit()
{
    int counter = 0;
    sf::Vector2f pos;

    auto iter = colorPicker.begin();
    for(;iter != colorPicker.end();++iter)
    {
        pos.x = (counter%4)*50 + box.getPosition().x+5;
        pos.y = (counter/4+1)*50 + box.getPosition().y;
        (*iter).second.setPosition(pos);
        counter++;
    }

    sf::Vector2f position = box.getPosition();
    position.y += 150;
    colorSquare.setPosition(position);

    pos.x = box.getPosition().x-3;
    pos.y = box.getGlobalBounds().top + box.getGlobalBounds().height;
    background.setPosition(pos);
}

void ColorMenu::setPosition(sf::Vector2f position)
{
    label.setPosition(position);
    sf::Vector2f pos = label.getPosition();
    pos.x = label.getGlobalBounds().left + label.getGlobalBounds().width + 10;
    pos.y = label.getPosition().y;
    box.setPosition(pos);
    reposit();
}

void ColorMenu::setString(std::string name) {
    label.setString(name);
}
