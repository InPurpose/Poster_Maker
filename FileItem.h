//
// Created by xiwen on 5/15/2021.
//

#ifndef SFML_PROJECT_FILEITEM_H
#define SFML_PROJECT_FILEITEM_H
#include "Item.h"
#include "Image.h"

class FileItem : public Item{
private:
    //this is the folder or file icon
    sf::Sprite icon;
    float padding = 5;
    void initialize();
public:
    //Constructors
    FileItem();
    FileItem(Image::image icon, std::string string1);
    FileItem(Image::image iconName, std::string text, sf::Vector2f size, sf::Vector2f position);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f pos);
    void setIcon(const sf::Sprite &icon);
    void setIcon(Image::image iconName);

};


#endif //SFML_PROJECT_FILEITEM_H
