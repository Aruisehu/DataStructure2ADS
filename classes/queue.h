#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"

template <class T>
class Queue
{
    public:
        Queue();
        int count();
        void queue_old(T val);
        void queue(T val);
        T dequeue();
        T peek();
        bool is_empty();
        void print();


    private:
        Node<T>* first;
        Node<T>* last;
        int nb;
};

#endif


