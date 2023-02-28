//
// Created by xiwen on 4/9/2021.
//

#ifndef SFML_PROJECT_LINKEDLIST_CPP
#define SFML_PROJECT_LINKEDLIST_CPP

#include "LinkedList.h"


template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& right)
{
    if(*this == right)
        return *this;

    clear();

    Node<T>* walker = right.head;
    while(walker != nullptr)
    {
        InsertTail(walker->data);
        walker = walker->next;
    }
    return *this;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& right)
{
    head = nullptr;
    tail = nullptr;
    *this = right;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<class T>
void LinkedList<T>::InsertHead(const T& item)
{
    Node<T>* temp = NewNode(item);

    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
}

template<class T>
void LinkedList<T>::InsertTail(const T& item)
{
    Node<T>* temp = NewNode(item);

    if(tail == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->previous = tail;
        tail->next = temp;
        tail = temp;
    }
}

template<class T>
void LinkedList<T>::InsertAfterThis(const T& ths, const T& item)
{
    Node<T>* address = FoundThis(ths);

    if(address != nullptr)
    {
        if(address->next == nullptr)
            InsertTail(item);
        else
        {
            Node<T>* temp = NewNode(item);
            temp->next = address->next;
            temp->previous = address;
            address->next->previous = temp;
            address->next = temp;
        }
    }
}

template<class T>
void LinkedList<T>::InsertBeforeThis(const T& ths, const T& item)
{
    Node<T>* address = FoundThis(ths);

    if(address != nullptr)
    {
        if(address->previous == nullptr)
            InsertHead(item);
        else
        {
            Node<T>* temp = NewNode(item);
            address->previous->next = temp;
            temp->next = address;
            temp->previous = address->previous;
            address->previous = temp;
        }
    }
}

template<class T>
Node<T>* LinkedList<T>::NewNode(const T& item)
{
    Node<T>* temp = new Node<T>;

    temp->data = item;
    temp->next = nullptr;
    temp->previous = nullptr;
    return temp;
}

template<class T>
Node<T>* LinkedList<T>::FoundThis(const T& item)
{
    Node<T>* walker = head;
    while(walker != nullptr)
    {
        if(walker->data == item)
            return walker;
        walker = walker->next;
    }
    return walker;
}

template<class T>
void LinkedList<T>::remove(const T& item)
{
    Node<T>* address = FoundThis(item);

    if(address == nullptr)
    {
        std::cout << "This object does not exist.\n";
        return;
    }

    if(address == head)
    {
        address->next->previous = address->previous;
        head = address->next;
        delete address;
        return;
    }

    if(address == tail)
    {
        address->previous->next = address->next;
        tail = address->previous;
        delete address;
        return;
    }

    address->previous->next = address->next;
    address->next->previous = address->previous;

    delete address;
}


template<class T>
void LinkedList<T>::clear()
{
    Node<T>* walker = head;

    while(walker != nullptr)
    {
        Node<T>* temp = walker;
        walker = walker->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}


template<class S>
std::ostream& operator <<(std::ostream& outs,const LinkedList<S>& L)
{
    Node<S>* walker = L.head;
    while(walker != nullptr)
    {
        outs << walker->data << " ";
        walker = walker->next;
    }

    outs << std::endl;
    return outs;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator +=(T item)
{
    InsertTail(item);
}

template<class T>
bool operator ==(const LinkedList<T>& left,const LinkedList<T>& right)
{
    Node<T>* left_walker = left.head;
    Node<T>* right_walker = right.head;

    if(left_walker == nullptr && right_walker != nullptr)
        return false;
    if(right_walker == nullptr && left_walker != nullptr)
        return false;


    while(left_walker != nullptr && right_walker != nullptr)
    {
        if(left_walker->data != right_walker->data)
            return false;
        left_walker = left_walker->next;
        right_walker = right_walker->next;
    }
    return true;
}

template<class T>
int LinkedList<T>::size() const {
    int counter = 0;
    Node<T>* walker = head;
    while(walker != tail && walker != nullptr)
    {
        counter++;
        walker = walker->next;
    }
    return counter;
}

template<class T>
void LinkedList<T>::removeHead()
{
    if(head == nullptr)
        return;

    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node<T>* temp = head;
    head->next->previous = nullptr;
    head = head->next;
    delete temp;
}

template<class T>
void LinkedList<T>::removeTail()
{
    if(head == nullptr)
        return;
    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    Node<T>* temp = tail;
    tail->previous->next = nullptr;
    tail = tail->previous;
    delete temp;
}


template<class T>
T LinkedList<T>::nth_item(int index) {
    assert(index < size());
    Node<T>* walker = head;
    for (int i = 0; i < index; ++i)
    {
        walker = walker->next;
    }
    return walker->data;
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::begin() const
{
    return Node_Iterator<T>(head);
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::end() const
{
    return Node_Iterator<T>(nullptr);
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::LastOne() const
{
    return Node_Iterator<T>(tail);
}

template<class S>
bool operator!=(const LinkedList<S> &left, const LinkedList<S> &right) {
    return 0;
}

#endif