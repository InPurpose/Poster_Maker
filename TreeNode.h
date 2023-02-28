//
// Created by xiwen on 4/28/2021.
//

#ifndef SFML_PROJECT_TREENODE_H
#define SFML_PROJECT_TREENODE_H

template<class T>
struct TreeNode {
    T data;
    TreeNode<T> *left = nullptr;
    TreeNode<T> *right = nullptr;

};


#endif //BINARYTREE_TREENODE_H
