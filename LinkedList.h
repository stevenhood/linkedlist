#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(int iValue);
    void add(int iIndex, int iValue);
    void addHead(int iValue);
    void addTail(int iValue);
    int get(int iIndex);
    int getHead() const;
    int getTail() const;
    void clear();
    void print();
    int size() const { return m_iSize; }

private:
    int m_iSize;
    Node *m_pHead, *m_pTail;

    bool checkIndex(int iIndex);
    Node* getNode(int iIndex);
};
