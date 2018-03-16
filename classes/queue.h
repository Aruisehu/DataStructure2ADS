#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"
class Queue
{
    public:
        Queue();
        int count();
        void queue_old(int val);
        void queue(int val);
        int dequeue();
        int peek();
        bool is_empty();
        void print();


    private:
        Node* first;
        Node* last;
        int nb;
};

#endif


