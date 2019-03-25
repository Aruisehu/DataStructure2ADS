#include "stack.h"

using namespace std;

template <class T>
Stack<T>::Stack()
{
    nb = 0;
}

template <class T>
int Stack<T>::count() { return nb; }

template <class T>
T Stack<T>::peek()
{
    //Récupère la valeur du noeud en haut de la pile
    return first->get_value();
}

template <class T>
void Stack<T>::push(T val)
{
    // Crée un noeud avec la valeur "val" et l'insère au début de la pile
    Node<T>* node = new Node<T>(val);
    node->set_next(first);
    first = node;
    nb++;
}

template <class T>
T Stack<T>::pop()
{
    // Enlève l'élément en haut de la pile
    T value = first->get_value();
    Node<T>* current = first;
    Node<T>* next = first->get_next();

    first = next;

    current->set_next(NULL);
    current = NULL;
    delete current;
    nb--;
    return value;
}

template <class T>
bool Stack<T>::is_empty()
{
    // Vérifie si la pile est vide
    return nb == 0;
}

template <class T>
void Stack<T>::print()
{
    // Affichage custom de la pile
    cout << "[";
    Node<T>* current = first;

    for(int i = 0; i < nb; i++)
    {
        cout << current->get_value() << ", ";
        current = current->get_next();
    }
    cout << "]" << endl;
}

template class Stack<int>;
