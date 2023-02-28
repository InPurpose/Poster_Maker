//
// Created by xiwen on 6/4/2021.
//

#include "Window_Dialog.h"

Window_Dialog::Window_Dialog() {
    tree.push("Source","power.jpg");
    tree.push("Source","Skulls.jpg");
    tree.push("Source","Name.txt");

}

void Window_Dialog::open()
{
    Item Open("Open",{250,450});
    Item Cancel("Cancel",{470,450});



    sf::RenderWindow window({700, 500, 32},"Open");
    sf::Color white = sf::Color::White;
    white.a = 120;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                disableState(LoadFile);
                window.close();
            }
            if(MouseEvents<Item>::mouseClicked(Cancel,window))
            {
                disableState(LoadFile);
                window.close();
            }
            if(MouseEvents<Item>::mouseClicked(Open,window))
            {
                enableState(LoadFile);
                name = FileNode::OpenImg;
                window.close();
            }
            tree.addEventHandler(window,event);

        }

        window.clear(sf::Color::Black);
        window.draw(Open);
        window.draw(Cancel);
        window.draw(tree);
        window.display();
    }

}

void Window_Dialog::draw(sf::RenderTarget &window, sf::RenderStates states) const {}

void Window_Dialog::applySnapshot(const Snapshot &snapshot) {}

void Window_Dialog::addEventHandler(sf::RenderWindow &window, sf::Event event) {}

void Window_Dialog::update() {}

Snapshot &Window_Dialog::getSnapshot() {}

std::string Window_Dialog::getImg() {
    return name;
}



