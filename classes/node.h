#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node
{
    public:
        Node(T val);
        T get_value();
        void set_value(T val);
        Node<T>* get_next();
        void set_next(Node<T>* value);

    private:
        Node<T>* next;
        T value;
};

#endif
