//
// Created by xiwen on 4/28/2021.
//

#ifndef SFML_PROJECT_BINARY_TREE_H
#define SFML_PROJECT_BINARY_TREE_H
#include <iostream>
#include "TreeNode.h"
#include <SFML/Graphics.hpp>

namespace
{
    template<class T>
    void output(T& item)
    {
        std::cout << item << " ";
    }

    template<class T>
    bool compare(T& left, T&right)
    {

    }

}

template<class T>
class Binary_Tree {
private:
    TreeNode<T> * root = nullptr;

    void inorder(TreeNode<T> * root, void f(T&));
    void inorder(TreeNode<T> * root, sf::RenderTarget &window)  const;

    void postorder(TreeNode<T> * root, void f(T&) = output);
    void preorder(TreeNode<T> * root, void f(T&) = output);

    void push(T item, TreeNode<T>*& root);
    bool empty();
public:

    void push(T& item);
    void pop();

    void inorder(void f(T&) = output);
    void inorder(sf::RenderTarget &window) const;
    void postorder(void f(T&) = output);
    void preorder(void f(T&) = output);
};

#include "Binary_Tree.cpp"

#endif //SFML_PROJECT_BINARY_TREE_H
