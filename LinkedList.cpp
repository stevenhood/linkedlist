#include <cstdio>
#include "LinkedList.h"

LinkedList::LinkedList()
    : m_size(0)
    , m_head(NULL)
    , m_tail(NULL)
{
}

LinkedList::~LinkedList()
{
    Node *current = m_head;
    while (current != NULL) {
        delete current;
        current = current->getNext();
    }
}

void LinkedList::add(int value)
{
    printf("added %d, size: %d\n", value, m_size);
    if (m_head == NULL) {
        m_head = new Node(value, NULL);
        m_tail = m_head;
    } else {
        Node *temp = m_tail;
        m_tail = new Node(value, NULL);
        temp->setNext(m_tail);
    }
    m_size++;
}

void LinkedList::print()
{
    int count = 0;
    Node *current = m_head;
    while (current != NULL) {
        printf("Node %d: value = %d\n", count++, current->getValue());
        current = current->getNext();
    }
}
