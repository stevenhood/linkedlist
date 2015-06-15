#include <cstdio>
#include "LinkedList.h"

LinkedList::LinkedList(void)
    : m_iSize(0)
    , m_pHead(NULL)
    , m_pTail(NULL)
{
}

LinkedList::~LinkedList(void)
{
    Clear();
}

// Append the specified element to the end of this list.
void LinkedList::Add(int iValue)
{
    // printf("added %d, list size: %d\n", iValue, m_iSize);
    if (m_pHead == NULL) {
        m_pHead = new Node(iValue, NULL);
        m_pTail = m_pHead;

    } else {
        Node *pOldTail = m_pTail;
        m_pTail = new Node(iValue, NULL);
        pOldTail->SetNext(m_pTail);
    }
    m_iSize++;
}

// Insert an element at the specified position in this list.
void LinkedList::Add(int iIndex, int iValue)
{
    if (!CheckIndex(iIndex))
        return;

    if (iIndex == 0) {
        AddHead(iValue);

    } else if (iIndex == m_iSize) {
        AddTail(iValue);

    } else {
        Node *pBefore = GetNode(iIndex - 1);
        Node *pAtIndex = GetNode(iIndex);
        Node *pNew = new Node(iValue, pAtIndex);
        pBefore->SetNext(pNew);
        m_iSize++;
    }
}

// [Private] Returns false if the specified index is out of bounds.
// Otherwise, returns true.
bool LinkedList::CheckIndex(int iIndex) const
{
    if (m_iSize == 0)
        return false;
    return (0 <= iIndex && iIndex < m_iSize);
}

// Insert the specified element at the beginning of this list.
void LinkedList::AddHead(int iValue)
{
    if (m_pHead == NULL) {
        Add(iValue);
    } else {
        Node *pOldHead = m_pHead;
        m_pHead = new Node(iValue, pOldHead);
        m_iSize++;
    }
}

// Append the specified element to the end of this list.
// Equivalent to Add(int)
void LinkedList::AddTail(int iValue)
{
    Add(iValue);
}

// Return the element at the specified position in this list. -1 if out
// of bounds.
int LinkedList::Get(int iIndex) const
{
    Node *pNode = GetNode(iIndex);
    if (pNode == NULL) {
        printf("LinkedList::get: index out of bounds (%d)\n", iIndex);
        return -1;
    }
    return pNode->GetValue();
}

// [Private] Return a pointer to the node at the specified index in the list.
Node* LinkedList::GetNode(int iIndex) const
{
    int iCount = 0;
    Node *pCurrent = m_pHead;

    while (pCurrent != NULL) {
        if (iCount == iIndex)
            return pCurrent;
        pCurrent = pCurrent->GetNext();
        iCount++;
    }

    return NULL;
}

// Returns the first element in this list. -1 if empty.
int LinkedList::GetHead(void) const
{
    if (m_pHead)
        return m_pHead->GetValue();
    return -1;
}

// Returns the last element in this list. -1 if empty.
int LinkedList::GetTail(void) const
{
    if (m_pTail)
        return m_pTail->GetValue();
    return -1;
}

// Remove all elements from this list.
void LinkedList::Clear(void)
{
    Node *pCurrent = m_pHead;

    while (pCurrent != NULL) {
        // printf("deleting object at %p\n", pCurrent);
        delete pCurrent;
        pCurrent = pCurrent->GetNext();
        m_iSize--;
    }

    m_pHead = NULL;
    m_pTail = NULL;
}

// Print all elements in this list.
void LinkedList::Print(void) const
{
    if (m_iSize < 1) {
        printf("List is empty\n");
        return;
    }

    int iCount = 0;
    Node *pCurrent = m_pHead;
    while (pCurrent != NULL) {
        printf("Node %d (%p): value = %d, next = %p\n", iCount++, pCurrent,
                pCurrent->GetValue(), pCurrent->GetNext());
        pCurrent = pCurrent->GetNext();
    }
}
