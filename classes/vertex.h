#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
class Vertex
{
    public:
        Vertex(int val);
        int get_value();
        void set_value(int val);
        Vertex* get_left();
        void set_left(Vertex* value);
        Vertex* get_right();
        void set_right(Vertex* value);

    private:
        Vertex* left;
        Vertex* right;
        int value;
};

#endif

