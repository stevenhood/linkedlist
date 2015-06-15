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
}

void LinkedList::add(int value)
{
    printf("size: %d\n", m_size);
    if (m_head == NULL) {
        m_head = new Node(value, NULL);
        m_tail = m_head;
    } else {
        Node *temp = m_tail;
        m_tail = new Node(value, temp);
        temp->setNext(m_tail);
    }
    m_size++;
}

void LinkedList::print()
{
    Node *current = m_head;
    int count = 0;
    while (current != NULL) {
        std::printf("Node %d: value = %d\n", count, current->m_value);
        current = current->m_next;
    }
}
