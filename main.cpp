#include "classes/liste.h"

using namespace std;

int main(void)
{
    Liste* liste = new Liste();

    liste->insert_first(1);
    liste->insert_last(3);
    liste->insert(5, 1);
    cout << liste->count() << endl;
    cout << liste->search(3) << endl;
    liste->print();
    liste->update(1, 10);
    liste->remove(0);
    liste->print();

    return 0;
}
