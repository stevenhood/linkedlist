#include "Node.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void Add(int iValue);
    void Add(int iIndex, int iValue);
    void AddHead(int iValue);
    void AddTail(int iValue);
    int Get(int iIndex);
    int GetHead() const;
    int GetTail() const;
    void Clear();
    void Print();
    int Size() const { return m_iSize; }

private:
    int m_iSize;
    Node *m_pHead, *m_pTail;

    bool CheckIndex(int iIndex);
    Node* GetNode(int iIndex);
};
