//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_NODE_H
#define SFML_PROJECT_NODE_H

template <class T>
struct Node {
    T data;
    Node<T>* previous = nullptr;
    Node<T>* next = nullptr;
};

#endif //SFML_PROJECT_NODE_H
