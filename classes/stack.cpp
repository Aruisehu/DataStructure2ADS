#include "stack.h"

using namespace std;

Stack::Stack()
{
    nb = 0;
}

int Stack::count() { return nb; }

int Stack::peek()
{
    //Récupère la valeur du noeud en haut de la pile
    return first->get_value();
}

void Stack::push(int val)
{
    // Crée un noeud avec la valeur "val" et l'insère au début de la pile
    Node* node = new Node(val);
    node->set_next(first);
    first = node;
    nb++;
}

int Stack::pop()
{
    // Enlève l'élément en haut de la pile
    int value = first->get_value();
    Node* current = first;
    Node* next = first->get_next();

    first = next;

    current->set_next(NULL);
    current = NULL;
    delete current;
    nb--;
    return value;
}

bool Stack::is_empty()
{
    // Vérifie si la pile est vide
    return nb == 0;
}

void Stack::print()
{
    // Affichage custom de la pile
    cout << "[";
    Node* current = first;

    for(int i = 0; i < nb; i++)
    {
        cout << current->get_value() << ", ";
        current = current->get_next();
    }
    cout << "]" << endl;
}

