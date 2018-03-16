#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include "node.h"
class Liste
{
    public:
        Liste();
        int count();
        Node* get_first();
        void insert_first(int val);
        void insert_last(int val);
        void insert(int val, int i);
        int get(int index);
        int search(int val);
        void remove(int index);
        void remove_by_value(int val);
        void update(int index, int value);
        bool is_empty();
        void print();


    private:
        Node* first;
        int nb;
        Node* get_node(int index);
};

#endif

