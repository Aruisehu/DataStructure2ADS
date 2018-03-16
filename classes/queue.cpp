#include "queue.h"

using namespace std;

Queue::Queue()
{
    nb = 0;
}

int Queue::count() { return nb; }

int Queue::peek()
{
    //Récupère la valeur du noeud au début de la file
    return first->get_value();
}

void Queue::queue_old(int val)
{
    // Crée un noeud avec la valeur "val" et l'insère en fin de la file
    Node* node = new Node(val);
    if (first != NULL)
    {
        Node* current = first;

        for(int i = 0; i < nb-1; i++)
        {
            current = current->get_next();
        }
        current->set_next(node);
    } else {
        first = node;
    }
    nb++;
    last = node;
}

void Queue::queue(int val)
{
    // Crée un noeud avec la valeur "val" et l'insère en fin de la file
    Node* node = new Node(val);
    if (first != NULL)
    {
        last->set_next(node);
    } else {
        first = node;
    }
    nb++;
    last = node;
}

int Queue::dequeue()
{
    // Enlève le premier élément de la file
    int value = first->get_value();
    Node* removed = first;
    Node* next = removed->get_next();

    first = next;

    removed->set_next(NULL);
    removed = NULL;
    delete removed;
    nb--;
    return value;
}

bool Queue::is_empty()
{
    // Vérifie si la file est vide
    return nb == 0;
}

void Queue::print()
{
    // Affichage custom de la file
    cout << "[";
    Node* current = first;

    for(int i = 0; i < nb; i++)
    {
        cout << current->get_value() << ", ";
        current = current->get_next();
    }
    cout << "]" << endl;
}

