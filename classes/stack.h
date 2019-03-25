#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.h"

template <class T>
class Stack
{
    public:
        Stack();
        int count();
        void push(T val);
        T peek();
        T pop();
        bool is_empty();
        void print();


    private:
        Node<T>* first;
        int nb;
};

#endif


