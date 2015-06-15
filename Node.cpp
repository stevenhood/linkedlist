#include <iostream>
#include "Node.h"

Node::Node()
    : m_value(0) , m_next(NULL)
{
}

Node::Node(int value, Node *next)
    : m_value(value), m_next(next)
{
}

Node::~Node()
{
}
