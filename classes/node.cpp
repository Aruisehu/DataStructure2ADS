#include "node.h"

Node::Node(int val) : value(val) {}

int Node::get_value() { return value; }
void Node::set_value(int val) { value = val; }

Node* Node::get_next() { return next; }
void Node::set_next(Node* value) { next = value; }
