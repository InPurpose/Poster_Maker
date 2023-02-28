//
// Created by xiwen on 5/15/2021.
//

#include "FileItem.h"

FileItem::FileItem() : FileItem(Image::FOLDER,"Direct 1",{10,10},{0,0})
{

}

FileItem::FileItem(Image::image icon, std::string string1): FileItem(icon,string1,{10,10},{0,0})
{

}

FileItem::FileItem(Image::image iconName, std::string text, sf::Vector2f size, sf::Vector2f position)
{

    setIcon(iconName);
    icon.setPosition(position);

    float scale = Item::getGlobalBounds().height/ icon.getGlobalBounds().height;
    icon.setScale({scale,scale});

    setString(text);

    sf::Vector2f pos;
    pos.x = icon.getGlobalBounds().left + icon.getGlobalBounds().width;
    pos.y = icon.getPosition().y;
    Item::setPosition(position);
    icon.setPosition(Item::getGlobalBounds().left+5,Item::getGlobalBounds().top);

    setOutlineColor(sf::Color::Transparent);
}


void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    Item::draw(window,states);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

sf::FloatRect FileItem::getGlobalBounds() const{
    return Item::getGlobalBounds();
}

sf::Vector2f FileItem::getSize() const {

}

sf::Vector2f FileItem::getPosition() const {
    return icon.getPosition();
}

void FileItem::setPosition(sf::Vector2f pos) {
    icon.setPosition(pos);
    Item::setPosition(pos);
}

void FileItem::setIcon(const sf::Sprite &icon) {
    FileItem::icon = icon;
}

void FileItem::setIcon(Image::image iconName) {
    icon.setTexture(Image::getImage(iconName));
}

void FileItem::initialize() {

}


