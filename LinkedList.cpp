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

// Return the element at the specified position in the list.
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

// Remove all elements from the list.
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

// Print all elements in the list.
void LinkedList::print()
{
    int iCount = 0;
    Node *pCurrent = m_pHead;
    while (pCurrent != NULL) {
        printf("Node %d: value = %d\n", iCount++, pCurrent->getValue());
        pCurrent = pCurrent->getNext();
    }
}
