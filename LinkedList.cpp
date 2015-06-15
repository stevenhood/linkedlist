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
    // printf("added %d, list size: %d\n", iValue, m_iSize);
    if (m_pHead == NULL) {
        m_pHead = new Node(iValue, NULL);
        m_pTail = m_pHead;
    } else {
        Node *pOldTail = m_pTail;
        m_pTail = new Node(iValue, NULL);
        pOldTail->setNext(m_pTail);
    }
    m_iSize++;
}

// Insert an element at the specified position in this list.
void LinkedList::add(int iIndex, int iValue)
{
    if (!checkIndex(iIndex))
        return;

    if (iIndex == 0) {
        addHead(iValue);
    } else if (iIndex == m_iSize) {
        addTail(iValue);
    } else {
        Node *pBefore = getNode(iIndex - 1);
        Node *pAtIndex = getNode(iIndex);
        Node *pNew = new Node(iValue, pAtIndex);
        pBefore->setNext(pNew);
        m_iSize++;
    }
}

bool LinkedList::checkIndex(int iIndex)
{
    if (m_iSize == 0)
        return false;
    return (0 <= iIndex && iIndex < m_iSize);
}

void LinkedList::addHead(int iValue)
{
    if (m_pHead == NULL) {
        add(iValue);
    } else {
        Node *pOldHead = m_pHead;
        m_pHead = new Node(iValue, pOldHead);
        m_iSize++;
    }
}

void LinkedList::addTail(int iValue)
{
    if (m_pTail == NULL) {
        add(iValue);
    } else {
        Node *pOldTail = m_pTail;
        m_pTail = new Node(iValue, NULL);
        pOldTail->setNext(m_pTail);
        m_iSize++;
    }
}

// Return the element at the specified position in this list. -1 if out
// of bounds.
int LinkedList::get(int iIndex)
{
    Node *pNode = getNode(iIndex);
    if (pNode == NULL) {
        printf("LinkedList::get: index out of bounds (%d)\n", iIndex);
        return -1;
    }
    return pNode->getValue();
}

// Private
Node* LinkedList::getNode(int iIndex)
{
    int iCount = 0;
    Node *pCurrent = m_pHead;

    while (pCurrent != NULL) {
        if (iCount == iIndex)
            return pCurrent;
        pCurrent = pCurrent->getNext();
        iCount++;
    }

    return NULL;
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
