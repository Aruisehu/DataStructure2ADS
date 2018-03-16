#ifndef NODE_H
#define NODE_H

#include <iostream>
class Node
{
    public:
        Node(int val);
        int get_value();
        void set_value(int val);
        Node* get_next();
        void set_next(Node* value);

    private:
        Node* next;
        int value;
};

#endif
