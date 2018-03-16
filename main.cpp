#include "classes/liste.h"
#include "classes/stack.h"
#include "classes/queue.h"

using namespace std;

int main(void)
{
    // Test liste
    /*Liste* liste = new Liste();

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

    /*Stack* pile = new Stack();

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
    pile->print();*/

    //-----------------------------------
    //Test queue

    Queue* file = new Queue();
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

    return 0;
}








