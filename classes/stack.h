#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.h"
class Stack
{
    public:
        Stack();
        int count();
        void push(int val);
        int peek();
        int pop();
        bool is_empty();
        void print();


    private:
        Node* first;
        int nb;
};

#endif


