#include "classes/liste.h"
#include "classes/stack.h"
#include "classes/queue.h"
#include "classes/btree.h"

using namespace std;

int main(void)
{
    // Test liste
    /*Liste<int>* liste = new Liste<int>();

    liste->insert_first(1);
    liste->insert_last(3);
    liste->insert(5, 1);
    cout << liste->count() << endl;
    cout << liste->search(3) << endl;
    liste->print();
    liste->update(1, 10);
    liste->remove(0);
    liste->print();*/
    //-----------------------------------
    //Test stack
    Stack<int>* pile = new Stack<int>();

    cout << pile->is_empty() << endl;
    pile->push(9);
    pile->push(5);
    pile->push(2);
    pile->push(8);
    pile->push(7);
    cout << pile->count() << endl;
    pile->print();
    cout << pile->pop() << endl;
    cout << pile->peek() << endl;
    cout << pile->is_empty() << endl;
    cout << pile->count() << endl;
    pile->print();

    cout << "QUEUE" << endl;

    //-----------------------------------
    //Test queue

    Queue<int>* file = new Queue<int>();
    cout << file->is_empty() << endl;
    file->queue_old(9);
    file->queue(5);
    file->queue_old(2);
    file->queue(8);
    file->queue_old(7);
    cout << file->count() << endl;
    file->print();
    cout << file->dequeue() << endl;
    cout << file->peek() << endl;
    cout << file->is_empty() << endl;
    cout << file->count() << endl;
    file->print(); 

    //-----------------------------------
    //Test arbre binaire

    /*BTree* tree = new BTree();
    tree->insert(9);
    tree->insert(5);
    tree->insert(10);
    tree->insert(8);
    tree->insert(7);
    tree->print(tree->get_root());
    cout << endl;
    cout << tree->search(2) << endl;
    cout << tree->search(10) << endl;
    cout << tree->min() << endl;
    cout << tree->max() << endl;
    tree->remove(5);
    tree->print(tree->get_root());
    cout << endl;*/
    return 0;
}








