#include <iostream>
#include "Node.h"

Node::Node(void)
    : m_iValue(0) , m_pNext(NULL)
{
}

Node::Node(int iValue, Node *pNext)
    : m_iValue(iValue), m_pNext(pNext)
{
}

Node::~Node(void)
{
}
