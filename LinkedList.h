//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_LINKEDLIST_H
#define SFML_PROJECT_LINKEDLIST_H
#include <iostream>
#include "Node.h"
#include "Node_Iterator.h"
#include <cassert>


template<class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

    Node<T>* NewNode(const T& item);//Create a dynamic node with given value
    Node<T>* FoundThis(const T& item);
public:
    typedef Node_Iterator<T> iterator;
    //Default
    LinkedList();

    //Big Three
    LinkedList& operator =(const LinkedList<T>& right);
    LinkedList(const LinkedList<T>& right);
    ~LinkedList();

    void InsertHead(const T& item);
    void InsertTail(const T& item);
    void InsertAfterThis(const T& ths, const T& item);
    void InsertBeforeThis(const T& ths, const T& item);

    void remove(const T& item);
    void removeHead();
    void removeTail();
    bool empty(){return head == nullptr;}
    void clear();
    void copy(const LinkedList<T>& right){*this = right;}
    int size() const;
    T nth_item(int index);

    template<class S>
    friend std::ostream& operator <<(std::ostream& outs,const LinkedList<S>& L);
    LinkedList& operator +=(T item);

    template<class S>
    friend bool operator ==(const LinkedList<S>& left,const LinkedList<S>& right);
    template<class S>
    friend bool operator !=(const LinkedList<S>& left,const LinkedList<S>& right);

    LinkedList<T>::iterator begin() const;
    LinkedList<T>::iterator end() const;
    LinkedList<T>::iterator LastOne() const;

};

#include "LinkedList.cpp"

#endif //SFML_PROJECT_LINKEDLIST_H
