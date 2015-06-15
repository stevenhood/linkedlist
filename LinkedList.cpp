#include <cstdio>
#include "LinkedList.h"

LinkedList::LinkedList()
    : m_iSize(0)
    , m_pHead(NULL)
    , m_pTail(NULL)
{
}

LinkedList::~LinkedList()
{
    clear();
}

// Append the specified element to the end of this list.
void LinkedList::add(int iValue)
{
    printf("added %d, size: %d\n", iValue, m_iSize);
    if (m_pHead == NULL) {
        m_pHead = new Node(iValue, NULL);
        m_pTail = m_pHead;
    } else {
        Node *temp = m_pTail;
        m_pTail = new Node(iValue, NULL);
        temp->setNext(m_pTail);
    }
    m_iSize++;
}

// Return the element at the specified position in this list. -1 if out
// of bounds.
int LinkedList::get(int iIndex)
{
    int iCount = 0;
    Node *pCurrent = m_pHead;

    while (pCurrent != NULL) {
        if (iCount == iIndex)
            return pCurrent->getValue();
        pCurrent = pCurrent->getNext();
        iCount++;
    }

    printf("LinkedList::get: index out of bounds (%d)\n", iIndex);
    return -1;
}

// Returns the first element in this list. -1 if empty.
int LinkedList::getHead() const
{
    if (m_pHead)
        return m_pHead->getValue();
    return -1;
}

// Returns the last element in this list. -1 if empty.
int LinkedList::getTail() const
{
    if (m_pTail)
        return m_pTail->getValue();
    return -1;
}

// Remove all elements from this list.
void LinkedList::clear()
{
    Node *pCurrent = m_pHead;

    while (pCurrent != NULL) {
        // printf("deleting object at %p\n", pCurrent);
        delete pCurrent;
        pCurrent = pCurrent->getNext();
        m_iSize--;
    }

    m_pHead = NULL;
    m_pTail = NULL;
}

// Print all elements in this list.
void LinkedList::print()
{
    printf("Size: %d\n", m_iSize);
    int iCount = 0;
    Node *pCurrent = m_pHead;
    while (pCurrent != NULL) {
        printf("Node %d: value = %d\n", iCount++, pCurrent->getValue());
        pCurrent = pCurrent->getNext();
    }
}
