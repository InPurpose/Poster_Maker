//
// Created by xiwen on 5/15/2021.
//

#include "FileTree.h"

void FileTree::push(FileNode *&root, std::string parent, std::string item)
{

    std::string iconName = item.substr(item.size()-3,3);
    Image::image icon = Image::FOLDER;
    if(iconName == "txt")
        icon = Image::TXT;
    if(iconName == "jpg" || iconName == "png")
        icon = Image::PHOTO;

    if(root == nullptr)
    {
        root = new FileNode(Image::FOLDER,parent);

        FileNode* n = new FileNode(icon, item);
        root->children.push_back(n);
        return;
    }

    if(root->data.getString() == parent)
    {
        FileNode* n = new FileNode(icon, item);
        root->children.push_back(n);
        return;
    }

    auto iter = root->children.begin();
    for(;iter != root->children.end(); ++iter)
    {
        push(*iter,parent,item);
    }
//    root->reposition();

}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event)
{
    if(root == nullptr)
        return;
    window.draw(root->data);
}

FileTree::FileTree() {
    enableState(ShowList);
}

void FileTree::push(std::string parent, std::string item) {
    push(root,parent,item);
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(root->data);
    root->reposition();
    if(isStateEnable(ShowList))
    {
        auto iter = root->children.begin();
        for(;iter !=  root->children.end(); ++iter)
        {
            (*iter)->draw(window,states);
        }
    }


}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<FileItem>::mouseClicked(root->data,window))
    {
        if(isStateEnable(ShowList))
            disableState(ShowList);
        else
            enableState(ShowList);
//        std::cout << "Clicked 1\n";
    }
//    root->data.addEventHandler(window,event);

    if(isStateEnable(ShowList))
    {
        auto iter = root->children.begin();
        for(;iter !=  root->children.end(); ++iter)
        {
            (*iter)->addEventHandler(window,event);
        }
    }

}

void FileTree::update() {}

Snapshot &FileTree::getSnapshot() {}

sf::FloatRect FileTree::getGlobalBounds() {}

void FileTree::applySnapshot(const Snapshot &snapshot) {}
