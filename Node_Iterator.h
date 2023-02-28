//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_NODE_ITERATOR_H
#define SFML_PROJECT_NODE_ITERATOR_H

#include "Node.h"
#include <iterator>


template <class T>
class Node_Iterator : public std::iterator<std::forward_iterator_tag, T> {
private:
    Node<T>* current;
public:
    Node_Iterator& operator ++();
    Node_Iterator operator ++(int);

    T& operator*();
    T& operator*() const;

    T& operator [](unsigned int index);

    Node_Iterator& operator +=(unsigned int index);
    Node_Iterator& operator -=(unsigned int index);

    template<class S>
    friend Node_Iterator<S> operator +(const Node_Iterator<S>& left, unsigned int index);
    template<class S>
    friend Node_Iterator<S> operator -(const Node_Iterator<S>& left, unsigned int index);

    template<class S>
    friend Node_Iterator<S> operator +(const Node_Iterator<S>& left, unsigned int index);
    template<class S>
    friend Node_Iterator<S> operator -(const Node_Iterator<S>& left, unsigned int index);

    template<class S>
    friend bool operator ==(const Node_Iterator<S>& left, const Node_Iterator<S>& right);

    template<class S>
    friend bool operator !=(const Node_Iterator<S>& left, const Node_Iterator<S>& right);

    Node_Iterator();
    Node_Iterator(Node<T>* node);
};

#include "Node_Iterator.cpp"


#endif //SFML_PROJECT_NODE_ITERATOR_H
