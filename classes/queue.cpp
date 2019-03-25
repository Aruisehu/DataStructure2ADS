#include "queue.h"

using namespace std;

template <class T>
Queue<T>::Queue()
{
    nb = 0;
}

template <class T>
int Queue<T>::count() { return nb; }

template <class T>
T Queue<T>::peek()
{
    //Récupère la valeur du noeud au début de la file
    return first->get_value();
}

template <class T>
void Queue<T>::queue_old(T val)
{
    // Crée un noeud avec la valeur "val" et l'insère en fin de la file
    Node<T>* node = new Node<T>(val);
    if (first != NULL)
    {
        Node<T>* current = first;

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

template <class T>
void Queue<T>::queue(T val)
{
    // Crée un noeud avec la valeur "val" et l'insère en fin de la file
    Node<T>* node = new Node<T>(val);
    if (first != NULL)
    {
        last->set_next(node);
    } else {
        first = node;
    }
    nb++;
    last = node;
}

template <class T>
T Queue<T>::dequeue()
{
    // Enlève le premier élément de la file
    int value = first->get_value();
    Node<T>* removed = first;
    Node<T>* next = removed->get_next();

    first = next;

    removed->set_next(NULL);
    removed = NULL;
    delete removed;
    nb--;
    return value;
}

template <class T>
bool Queue<T>::is_empty()
{
    // Vérifie si la file est vide
    return nb == 0;
}

template <class T>
void Queue<T>::print()
{
    // Affichage custom de la file
    cout << "[";
    Node<T>* current = first;

    for(int i = 0; i < nb; i++)
    {
        cout << current->get_value() << ", ";
        current = current->get_next();
    }
    cout << "]" << endl;
}

template class Queue<int>;
