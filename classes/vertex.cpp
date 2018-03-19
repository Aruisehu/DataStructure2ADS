#include "vertex.h"

Vertex::Vertex(int val) : value(val) {}

int Vertex::get_value() { return value; }
void Vertex::set_value(int val) { value = val; }

Vertex* Vertex::get_left() { return left; }
void Vertex::set_left(Vertex* value) { left = value; }

Vertex* Vertex::get_right() { return right; }
void Vertex::set_right(Vertex* value) { right = value; }

