//
// Created by xiwen on 5/15/2021.
//

#include "FileNode.h"

std::string FileNode::OpenTxt;
std::string FileNode::OpenImg;

FileNode::FileNode() {
    enableState(ShowList);
}

FileNode::FileNode(std::string string1) :data(Image::FOLDER,string1)
{

}

FileNode::FileNode(Image::image icon, std::string string1) :data(icon,string1)
{
    enableState(ShowList);

}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(data);
    if(isStateEnable(ShowList))
    {
        auto iter = children.begin();
        for(;iter !=  children.end(); ++iter)
        {
            (*iter)->draw(window,states);
        }
    }
}

void FileNode::toggleChlidren() {
    if(isStateEnable(ShowList))
        disableState(ShowList);
    else
        enableState(ShowList);
}

void FileNode::reposition() const
{
    sf::FloatRect p = data.getGlobalBounds();
    float y = p.height;
    auto iter = children.begin();
    for(; iter != children.end(); ++iter)
    {
        (*iter)->setPosition({40,y});
        y += p.height;
    }
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<FileItem>::mouseClicked(data, window))
    {
        data.setColor(sf::Color::Blue);
        {
            std::string temp = data.getString().substr(data.getString().size() - 3, 3);
            Image::image icon = Image::FOLDER;
            if (temp == "txt")
            {
                OpenTxt = data.getString();
                OpenImg = "";
            }
            if (temp == "jpg" || temp == "png")
            {
                OpenImg = data.getString();
                OpenTxt = "";
            }
        }
    }
    if(!MouseEvents<FileItem>::mouseClicked(data, window)
        &&MouseEvents<FileItem>::mouseClicked(window,event))
    {
        data.setColor(sf::Color::Black);
    }

    data.addEventHandler(window, event);
}

void FileNode::applySnapshot(const Snapshot &snapshot) {
//does nothing now
}

void FileNode::update() {
//does nothing now
}

Snapshot &FileNode::getSnapshot() {
//does nothing now
}

sf::FloatRect FileNode::getGlobalBounds() {
    return sf::FloatRect();
}

bool FileNode::isLeaf() const {
    return false;
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data) {
    this->data = data;
}

std::vector<FileNode*> &FileNode::getChildren() {
    return children;
}

std::vector<FileNode*>::iterator FileNode::begin() {
    return iterator(children.begin());
}

std::vector<FileNode*>::iterator FileNode::end() {
    return iterator(children.end());
}

void FileNode::setPosition(sf::Vector2f pos) {
    data.setPosition(pos);
}


