#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(int iValue);
    int get(int iIndex);
    void clear();
    void print();

private:
    int m_iSize;
    Node *m_pHead, *m_pTail;

    Node* newNode(int iValue, Node *pNext);
};
