#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {
public:
    SListIterator() : Iterator<T>() {};
    SListIterator(Node<T> *current) : Iterator<T>(current) {};
    SListIterator<T> operator++(){};
};

template <typename Tr>
class SList {
public:
    typedef typename Tr::T T;
    typedef typename Tr::Operation Operation;
    typedef SListIterator<T> iterator;

private:
    Node<T>* head;
    Operation cmp;

public:
    int nodes=0;

    SList()
    {
        head = nullptr;
    };

    bool find(T search, Node<T> **&pointer)
    {
        pointer = &head;
        do
        {
            if(cmp(search, (*pointer)->data))
            {
                if(search==(*pointer)->data)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
                pointer = &((*pointer)->next);
        }while((*pointer));
    }

    bool insert(T data)
    {
        // TODO
    }

    bool remove(T item) {
        // TODO
    }

    iterator begin() {
        // TODO
    }

    iterator end() {
        // TODO
    }

    ~SList() {
        if (head) {
            head->killSelf();
        }
    }
};

#endif