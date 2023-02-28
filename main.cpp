#include "ImageEditor.h"

int main() {
    ImageEditor imageEditor;
    sf::RenderWindow window(sf::VideoMode(1500, 950, 32), "Logo Maker");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            imageEditor.addEventHandler(window,event);
        }

        imageEditor.update();

        window.clear();
        window.draw(imageEditor);
        window.display();
        }

        return 0;
}