#include <iostream>

class LinkedList;

class Node
{
    friend class LinkedList;

public:
    Node();
    Node(int value, Node *next);
    ~Node();
    int getValue() const { return m_value; }
    void setValue(int n) { m_value = n; }
    Node* getNext() const { return m_next; }
    void setNext(Node *node) { m_next = node; }

private:
    int m_value;
    Node *m_next;
};

Node::Node()
    : m_value(0) , m_next(NULL)
{
}

Node::Node(int value, Node *next)
    : m_value(value), m_next(next)
{
}

// Node::~Node()
// {
// }
