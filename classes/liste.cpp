#include "liste.h"

using namespace std;

template <class T>
Liste<T>::Liste()
{
    nb = 0;
}

template <class T>
int Liste<T>::count() { return nb; }
template <class T>
Node<T>* Liste<T>::get_first() { return first; }

template <class T>
Node<T>* Liste<T>::get_node(int index)
{
    // Recupère le node à l'index "index"
    if (index >= nb or index < 0)
    {
        cout << "Error not that many element" << endl;
        return 0;
    }

    Node<T>* current = first;

    for(int i = 0; i < index; i++)
    {
        current = current->get_next();
    }
    return current;
}

template <class T>
T Liste<T>::get(int index)
{
    //Récupère la valeur du noeud à l'index "index"
    if (index >= nb)
    {
        cout << "Error not that many element" << endl;
        return 0;
    }

    Node<T>* current = first;

    for(int i = 0; i < index; i++)
    {
        current = current->get_next();
    }
    return current->get_value();
}

template <class T>
void Liste<T>::insert_first(T val)
{
    // Crée un noeud avec la valeur "val" et l'insère au début de la liste
    Node<T>* node = new Node<T>(val);
    node->set_next(first);
    first = node;
    nb++;
}

template <class T>
void Liste<T>::insert_last(T val)
{
    // Crée un noeud avec la valeur "val" et l'insère en fin de la liste
    Node<T>* node = new Node<T>(val);
    Node<T>* last = get_node(nb-1);
    last->set_next(node);
    nb++;
}

template <class T>
void Liste<T>::insert(T val, int i)
{
    // Crée un noeud avec la valeur "val" et l'insère en i-ème position dans la liste
    if (i >= nb)
    {
        cout << "Error not that many element" << endl;
        return;
    }

    Node<T>* prev_node = get_node(i-1);
    Node<T>* next_node = get_node(i);
    Node<T>* new_node = new Node<T>(val);

    prev_node->set_next(new_node);
    new_node->set_next(next_node);

    nb++;
}

template <class T>
int Liste<T>::search(T val)
{
    // Cherche un élément par valeur
    Node<T>* current = first;
    for(int i = 0; i < nb; i++)
    {
        if (current->get_value() == val)
        {
            return i;
        }
        current = current->get_next();
    }
    return -1; // Not found
}

template <class T>
void Liste<T>::remove(int index)
{
    // Enlève l'élément à la position "index"
    Node<T>* removed = get_node(index);
    Node<T>* prev = get_node(index - 1);
    Node<T>* next = removed->get_next();

    if (removed == NULL)
    {
        return;
    }

    if (prev)
    {
        prev->set_next(next);
    } else
    {
        first = next;
    }

    removed->set_next(NULL);
    removed = NULL;
    delete removed;
    nb--;
}

template <class T>
void Liste<T>::remove_by_value(T val)
{
    // Enlève la première occurence de "val" dans la liste, si elle est trouvée
    int index = search(val);
    if (index != -1)
    {
        remove(index);
    }
}

template <class T>
void Liste<T>::update(int index, T value)
{
    // Modifie la valeur du noeud à la position "index"
    Node<T>* node = get_node(index);
    node->set_value(value);
}

template <class T>
bool Liste<T>::is_empty()
{
    // Vérifie si la liste est vide
    return nb == 0;
}

template <class T>
void Liste<T>::print()
{
    // Affichage custom de la liste
    cout << "[";
    Node<T>* current = first;

    for(int i = 0; i < nb; i++)
    {
        cout << current->get_value() << ", ";
        current = current->get_next();
    }
    cout << "]" << endl;
}

template class Liste<int>;
