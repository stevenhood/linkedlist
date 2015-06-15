#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(int n);

private:
    int m_size;
    Node *m_head, *m_tail;
};

LinkedList::LinkedList()
    : m_size(0)
    , m_head(NULL)
    , m_tail(NULL)
{
}

// LinkedList::~LinkedList()
// {
// }

void LinkedList::add(int n)
{

}
