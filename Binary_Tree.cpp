//
// Created by xiwen on 4/28/2021.
//

#ifndef SFML_PROJECT_BINARY_TREE_CPP
#define SFML_PROJECT_BINARY_TREE_CPP

#include "Binary_Tree.h"

template<class T>
void Binary_Tree<T>::inorder(TreeNode<T> *root, void f(T&))
{
    if(root == nullptr)
        return;

    inorder(root->left,f);
    f(root->data);
    inorder(root->right,f);
}

template<class T>
void Binary_Tree<T>::postorder(TreeNode<T> *root, void f(T&))
{
    if(root == nullptr)
        return;

    inorder(root->left);

    inorder(root->right);

    f(root->data);
}

template<class T>
void Binary_Tree<T>::preorder(TreeNode<T> *root, void f(T&))
{
    if(root == nullptr)
        return;

    f(root->data);

    inorder(root->left);

    inorder(root->right);
}

template<class T>
void Binary_Tree<T>::push(T item, TreeNode<T> *&root)
{
    if(root == nullptr)
    {
        root = new TreeNode<T>;
        root->data = item;
        return;
    }

    if(item <= root->data)
        push(item,root->left);
    else
        push(item,root->right);

}

template<class T>
void Binary_Tree<T>::push(T& item)
{
    push(item,root);
}

template<class T>
void Binary_Tree<T>::pop() {

}

template<class T>
void Binary_Tree<T>::inorder(void f(T&)) {
    inorder(root,f);
}

template<class T>
void Binary_Tree<T>::postorder(void f(T&)) {
    postorder(root,f);
}

template<class T>
void Binary_Tree<T>::preorder(void f(T&)) {
    preorder(root,f);
}

template<class T>
bool Binary_Tree<T>::empty() {
    return root == nullptr;
}

template<class T>
void Binary_Tree<T>::inorder(sf::RenderTarget &window) const
{
    inorder(root,window);
}

template<class T>
void Binary_Tree<T>::inorder(TreeNode<T> *root, sf::RenderTarget &window) const
{
    if(root == nullptr)
        return;

    inorder(root->left,window);
    window.draw(root->data);
    inorder(root->right,window);

}

#endif