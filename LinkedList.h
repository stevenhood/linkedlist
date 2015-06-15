#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(int n);

private:
    int size;
    Node *head, *tail;
};

LinkedList::LinkedList()
    : size(0)
{
}

// LinkedList::~LinkedList()
// {
// }

void LinkedList::add(int n)
{

}
