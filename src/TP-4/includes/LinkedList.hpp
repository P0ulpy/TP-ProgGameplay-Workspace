//
// Created by Flo on 04/03/2022.
//

#ifndef TP_PROGGAMEPLAY_WORKSPACE_LINKEDLIST_HPP
#define TP_PROGGAMEPLAY_WORKSPACE_LINKEDLIST_HPP

namespace TP4 {

    template<class T>
    struct LinkedListNode {
        explicit LinkedListNode(const T &value, T *next = nullptr);

        T value;
        LinkedListNode<T> *next = nullptr;
    };

    template<class T>
    class LinkedList {
    public:
        LinkedListNode<T> *begin();

        LinkedListNode<T> *end();

        LinkedListNode<T> *push_back(const T &value);

        LinkedListNode<T> *insert(LinkedListNode<T> *afterNode, const T &value);

        LinkedListNode<T> *insertAfter(LinkedListNode<T> *afterNode, const T &value);

        unsigned int getSize();

        void empty();

    private:
        LinkedListNode<T> *first = nullptr;
        LinkedListNode<T> *last = nullptr;
        int size = 0;
    };

}
#endif //TP_PROGGAMEPLAY_WORKSPACE_LINKEDLIST_HPP