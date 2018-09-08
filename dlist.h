#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include "iterator.h"
using namespace std;
template <typename T>
class DListIterator : public Iterator<T> {
public:
    DListIterator() : Iterator<T>() {};
    DListIterator(Node<T> *current) : Iterator<T>(current) {};
    DListIterator<T> operator++()
    {
        this->current = this->current->next;
        return *this;
    };
    DListIterator<T> operator--()
    {
        this->current = this->current->prev;
        return *this;
    };
};

template <typename Tr>
class DList
{
public:
    typedef typename Tr::T T;
    typedef DListIterator<T> iterator;

private:
    Node<T>* head;
    Node<T>* tail;

public:
    int nodes=0;

    DList()
    {
        head = tail = nullptr;
    };

    void push_front(T data)
    {
        auto* temp = new Node<T>(data);
        if(nodes==0)
            head=tail=temp;
        else
        {
            head->prev=temp;
            temp->next=head;
            head=temp;
        }
        nodes++;
    }

    void push_back(T data)
    {
        auto* temp = new Node<T>(data);
        if(nodes==0)
            head=tail=temp;
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        nodes++;
    }

    void pop_front()
    {
        auto* temp = head;
        if(nodes==0)
            cout << "Lista vacia\n";
        else
        {
            temp->next->prev=nullptr;
            head=temp->next;
            delete temp;
        }
        nodes--;
    }

    void pop_back()
    {
        auto* temp = tail;
        if(nodes==0)
            cout << "Lista vacia\n";
        else
        {
            tail->prev->next=nullptr;
            tail=tail->prev;
            delete temp;
        }
        nodes--;
    }

    iterator begin()
    {
        return iterator(head);
    }

    iterator end()
    {
        return iterator(tail);
    }

    void print()
    {
        auto temp = head;
        for(int i=0; i<nodes; i++)
        {
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }

    ~DList()
    {
        if(head)
        {
            head->killSelf();
        }
    }
};

#endif