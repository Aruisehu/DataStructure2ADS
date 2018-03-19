#ifndef BTREE_H
#define BTREE_H

#include "vertex.h"
#include <iostream>

class BTree
{
    public:
        BTree();
        Vertex* get_root();
        void insert(int val);
        bool search(int val);
        int min();
        int max();
        void remove(int val);
        void print(Vertex* vertex);

    private:
        Vertex* root;
        Vertex* get_successor(Vertex* vertex);
        Vertex* get_vertex(int val);
        Vertex* get_parent(int val);

};

#endif
