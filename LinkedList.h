#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(int iValue);
    int get(int iIndex);
    int getHead() const;
    int getTail() const;
    void clear();
    void print();
    int size() const { return m_iSize; }

private:
    int m_iSize;
    Node *m_pHead, *m_pTail;

    Node* newNode(int iValue, Node *pNext);
};
