#include "node.h"

template <class T>
Node<T>::Node(T val) : value(val) {}

template <class T>
T Node<T>::get_value() { return value; }
template <class T>
void Node<T>::set_value(T val) { value = val; }

template <class T>
Node<T>* Node<T>::get_next() { return next; }
template <class T>
void Node<T>::set_next(Node<T>* value) { next = value; }

template class Node<int>;
