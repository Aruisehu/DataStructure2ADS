#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include "node.h"

template <class T>
class Liste
{
    public:
        Liste();
        int count();
        Node<T>* get_first();
        void insert_first(T val);
        void insert_last(T val);
        void insert(T val, int i);
        T get(int index);
        int search(T val);
        void remove(int index);
        void remove_by_value(T val);
        void update(int index, T value);
        bool is_empty();
        void print();


    private:
        Node<T>* first;
        int nb;
        Node<T>* get_node(int index);
};

#endif

