//
// Created by xiwen on 5/15/2021.
//

#ifndef SFML_PROJECT_FILETREE_H
#define SFML_PROJECT_FILETREE_H
#include "FileNode.h"

class FileTree : public GUIComponents{
private:
    FileNode* root = nullptr;
    std::vector<FileNode*> children;
    void push(FileNode*& root, std::string parent, std::string item);
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    sf::Vector2f initPosition = {0, 0};
public:
    FileTree();

    void push(std::string parent, std::string item = "NULL");

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void applySnapshot(const Snapshot& snapshot);
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual sf::FloatRect getGlobalBounds();
};


#endif //SFML_PROJECT_FILETREE_H
