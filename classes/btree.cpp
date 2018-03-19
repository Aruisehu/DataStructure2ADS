#include "btree.h"

using namespace std;

BTree::BTree() {}

Vertex* BTree::get_root()
{
    return root;
}

Vertex* BTree::get_vertex(int val)
{
    Vertex* current = root;
    int cur_val;
    while (current)
    {
        cur_val = current->get_value();
        if (cur_val == val)
        {
            return current;
        }
        if (cur_val > val)
        {
            current = current->get_left();
        }
        else
        {
            current = current->get_right();
        }
    }
    return NULL;
}

Vertex* BTree::get_successor(Vertex* vertex)
{
    Vertex* successor = vertex->get_right();
    while (successor && successor->get_left())
    {
        successor = successor->get_left();
    }
    return successor;
}

Vertex* BTree::get_parent(int val)
{
    Vertex* current = root;
    int cur_val;
    while (current)
    {
        cur_val = current->get_value();
        if ((current->get_left() && current->get_left()->get_value() == val) || (current->get_right() && current->get_right()->get_value() == val))
        {
            return current;
        }
        if (cur_val > val)
        {
            current = current->get_left();
        }
        else
        {
            current = current->get_right();
        }
    }
    return NULL;
}

int BTree::min()
{
    Vertex* current = root;
    while (current->get_left())
    {
        current = current->get_left();
    }

    return current->get_value();
}

int BTree::max()
{
    Vertex* current = root;
    while (current->get_right())
    {
        current = current->get_right();
    }

    return current->get_value();
}

bool BTree::search(int val)
{
    Vertex* current = root;
    int cur_val;
    while (current)
    {
        cur_val = current->get_value();
        if (cur_val == val)
        {
            return true;
        }
        if (cur_val > val)
        {
            current = current->get_left();
        }
        else
        {
            current = current->get_right();
        }
    }
    return false;
}

void BTree::insert(int val)
{
    Vertex* vertex = new Vertex(val);
    if (!search(val))
    {
        Vertex* current = root;
        int cur_val;
        bool running = true;
        if (!root)
        {
            root = vertex;
            return;
        }
        while (running)
        {
            cur_val = current->get_value();
            if (cur_val > val)
            {
                if (current->get_left())
                {
                    current = current->get_left();
                }
                else
                {
                    running = false;
                }
            }
            else
            {
                if (current->get_right())
                {
                    current = current->get_right();
                }
                else
                {
                    running = false;
                }
            }
        }
        if (cur_val > val)
        {
            current->set_left(vertex);
        }
        else
        {
            current->set_right(vertex);
        }


    } else
    {
        cout << "Deja dans l'arbre" << endl;
    }
}

void BTree::remove(int val)
{
    Vertex* current = get_vertex(val);
    Vertex* parent = get_parent(val);
    if (current)
    {
        if(!current->get_left() && !current->get_right())
        {
            if (parent->get_left() == current)
            {
                parent->set_left(NULL);
            }
            else
            {
                parent->set_right(NULL);
            }
            current = NULL;
            delete current;
        }
        else if (!current->get_left() != !current->get_right()) // équivalent de Xor (on prend le négatif, pour avoir des booléens)
        {
            if (parent->get_value() < current->get_value())
            {
                if (current->get_right())
                {
                    parent->set_right(current->get_right());
                }
                else
                {
                    parent->set_right(current->get_left());
                }
            }
            else
            {
                if (current->get_right())
                {
                    parent->set_left(current->get_right());
                }
                else
                {
                    parent->set_left(current->get_left());
                }
            }
        }
        else
        {
            Vertex* successor = get_successor(current);
            if (parent->get_left() == current)
            {
                remove(successor->get_value());
                parent->set_left(successor);
            }
            else
            {
                remove(successor->get_value());
                parent->set_right(successor);
            }
        }
    }
    else
    {
        cout << "La valeur n'est pas dans l'arbre" << endl;
    }
}

void BTree::print(Vertex* vertex)
{
    if (vertex)
    {
        print(vertex->get_left());
        cout << vertex->get_value() << ", ";
        print(vertex->get_right());
    }
}
