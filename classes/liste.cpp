#include "liste.h"

using namespace std;

Liste::Liste()
{
    nb = 0;
}

int Liste::count() { return nb; }
Node* Liste::get_first() { return first; }

Node* Liste::get_node(int index)
{
    // Recupère le node à l'index "index"
    if (index >= nb or index < 0)
    {
        cout << "Error not that many element" << endl;
        return NULL;
    }

    Node* current = first;

    for(int i = 0; i < index; i++)
    {
        current = current->get_next();
    }
    return current;
}
int Liste::get(int index)
{
    //Récupère la valeur du noeud à l'index "index"
    if (index >= nb)
    {
        cout << "Error not that many element" << endl;
        return -1;
    }

    Node* current = first;

    for(int i = 0; i < index; i++)
    {
        current = current->get_next();
    }
    return current->get_value();
}

void Liste::insert_first(int val)
{
    // Crée un noeud avec la valeur "val" et l'insère au début de la liste
    Node* node = new Node(val);
    node->set_next(first);
    first = node;
    nb++;
}

void Liste::insert_last(int val)
{
    // Crée un noeud avec la valeur "val" et l'insère en fin de la liste
    Node* node = new Node(val);
    Node* last = get_node(nb-1);
    last->set_next(node);
    nb++;
}

void Liste::insert(int val, int i)
{
    // Crée un noeud avec la valeur "val" et l'insère en i-ème position dans la liste
    if (i >= nb)
    {
        cout << "Error not that many element" << endl;
        return;
    }

    Node* prev_node = get_node(i-1);
    Node* next_node = get_node(i);
    Node* new_node = new Node(val);

    prev_node->set_next(new_node);
    new_node->set_next(next_node);

    nb++;
}

int Liste::search(int val)
{
    // Cherche un élément par valeur
    Node* current = first;
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

void Liste::remove(int index)
{
    // Enlève l'élément à la position "index"
    Node* removed = get_node(index);
    Node* prev = get_node(index - 1);
    Node* next = removed->get_next();

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

void Liste::remove_by_value(int val)
{
    // Enlève la première occurence de "val" dans la liste, si elle est trouvée
    int index = search(val);
    if (index != -1)
    {
        remove(index);
    }
}

void Liste::update(int index, int value)
{
    // Modifie la valeur du noeud à la position "index"
    Node* node = get_node(index);
    node->set_value(value);
}

bool Liste::is_empty()
{
    // Vérifie si la liste est vide
    return nb == 0;
}

void Liste::print()
{
    // Affichage custom de la liste
    cout << "[";
    Node* current = first;

    for(int i = 0; i < nb; i++)
    {
        cout << current->get_value() << ", ";
        current = current->get_next();
    }
    cout << "]" << endl;
}
