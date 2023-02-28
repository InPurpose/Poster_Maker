//
// Created by xiwen on 5/15/2021.
//

#ifndef SFML_PROJECT_FILENODE_H
#define SFML_PROJECT_FILENODE_H
#include "FileItem.h"
#include "Image.h"
#include <iterator>
//#include "Window_Dialog.h"

class FileNode : public GUIComponents{
public:
    FileItem data;
    static std::string OpenTxt;
    static std::string OpenImg;

    std::vector<FileNode*> children;

    void toggleChlidren();

    void reposition() const;
public:
    typedef typename std::vector<FileNode*>::iterator iterator;
    FileNode();
    FileNode(std::string string1);
    FileNode(Image::image icon, std::string string1);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    virtual void applySnapshot(const Snapshot& snapshot);
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();

    sf::FloatRect getGlobalBounds();
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;

    //getters and setters
    FileItem &getData();
    void setData(const FileItem &data);
    std::vector<FileNode*>& getChildren();
    void setPosition(sf::Vector2f pos);
    //iterators
    iterator begin();
    iterator end();
};


#endif //SFML_PROJECT_FILENODE_H
