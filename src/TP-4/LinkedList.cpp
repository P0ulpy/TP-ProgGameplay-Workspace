//
// Created by Flo on 04/03/2022.
//

#include "includes/LinkedList.hpp"
using namespace TP4;

template<class T>
LinkedListNode<T>::LinkedListNode(const T &value, T *next)
    : value(value)
    , next(next) {}

template<class T>
LinkedListNode<T> *LinkedList<T>::begin() { return first; }
template<class T>
LinkedListNode<T> *LinkedList<T>::end() { return last; }

template<class T>
LinkedListNode<T>* LinkedList<T>::push_back(const T& value)
{
    auto* newElement = new LinkedListNode<T>(value, nullptr);

    if(!first)
    {
        first = newElement;
        last = first;
    }
    else
    {
        last->next = newElement;
        last = newElement;
    }
    ++size;
}

template<class T>
LinkedListNode<T>* LinkedList<T>::insert(LinkedListNode<T>* afterNode, const T& value)
{
    return insertAfter(afterNode);
}

template<class T>
LinkedListNode<T>* LinkedList<T>::insertAfter(LinkedListNode<T> *afterNode, const T &value)
{
    auto* newElement = new LinkedListNode<T>(value, afterNode->next, afterNode);
    afterNode->next = newElement;
    ++size;

    return newElement;
}

template<class T>
unsigned int LinkedList<T>::getSize() { return size; }

template<class T>
void LinkedList<T>::empty()
{
    LinkedListNode<T>* ref = first;
    while(ref)
    {
        LinkedListNode<T>* next = ref->next;
        delete ref;
        ref = next;
    }

    size = 0;
}
