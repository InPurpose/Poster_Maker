//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_NODE_ITERATOR_CPP
#define SFML_PROJECT_NODE_ITERATOR_CPP

#include "Node_Iterator.h"


template<class T>
Node_Iterator<T> Node_Iterator<T>::operator++(int) {
    current = current->next;
    return *this;
}

template<class T>
Node_Iterator<T> &Node_Iterator<T>::operator++() {
    Node_Iterator<T> temp = *this;

    current = current->next;

    return *this;
}

template<class T>
T &Node_Iterator<T>::operator*() {
    return current->data;
}

template<class T>
T &Node_Iterator<T>::operator*() const {
    return current->data;
}

template<class T>
T& Node_Iterator<T>::operator [](unsigned int index)
{
    Node<T>* walker = current;
    for(int i=0;i<index;i++)
    {
        if(walker != nullptr)
            walker = current->next;
    }
    return walker->data;
}
template<class T>
Node_Iterator<T>& Node_Iterator<T>::operator +=(unsigned int index)
{
    Node_Iterator<T> temp = *this;
    for(int i=0;i<index;i++)
    {
        if(current != nullptr)
            current = current->next;
    }
    return *this;
}

template<class T>
Node_Iterator<T>& Node_Iterator<T>::operator -=(unsigned int index)
{
    Node_Iterator<T> temp = *this;
    for(int i=0;i<index;i++)
    {
        if(current != nullptr)
            current = current->previous;
    }
    return *this;
}

template<class S>
Node_Iterator<S> operator +(const Node_Iterator<S>& left, unsigned int index)
{
    Node_Iterator<S> temp(left);
    for (int i = 0; i < index; ++i) {
        if(temp.current != nullptr && temp.current->next != nullptr)
            temp.current = temp.current->next;
    }
    return temp;
}

template<class S>
Node_Iterator<S> operator -(const Node_Iterator<S>& left, unsigned int index)
{
    Node_Iterator<S> temp(left);
    for (int i = 0; i < index; --i) {
        if(temp.current != nullptr && temp.current->previous != nullptr)
            temp.current = temp.current->previous;
    }
    return temp;
}

template<class S>
bool operator==(const Node_Iterator<S> &left, const Node_Iterator<S> &right) {
    return left.current == right.current;
}

template<class S>
bool operator!=(const Node_Iterator<S> &left, const Node_Iterator<S> &right) {
    return left.current != right.current;
}

template<class T>
Node_Iterator<T>::Node_Iterator(): current(nullptr)
{

}

template<class T>
Node_Iterator<T>::Node_Iterator(Node<T>* node) : current(node){

}


#endif