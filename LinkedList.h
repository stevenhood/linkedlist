#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    void print();

private:
    int m_size;
    Node *m_head, *m_tail;
    Node* newNode(int value, Node *next);
};
