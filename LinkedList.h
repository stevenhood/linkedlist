#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(int value);

private:
    int m_size;
    Node *m_head, *m_tail;
    Node* newNode(int value, Node *next);
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

void LinkedList::add(int value)
{
    if (m_head == NULL) {
        m_head = new Node(value, NULL);
        m_tail = m_head;
    } else {
        Node *temp = m_tail;
        m_tail = new Node(value, temp);
        temp->setNext(m_tail);
    }
}
