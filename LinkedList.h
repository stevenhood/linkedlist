#include "Node.h"

class LinkedList
{
public:
    LinkedList(void);
    ~LinkedList(void);
    void Add(int iValue);
    void Add(int iIndex, int iValue);
    void AddHead(int iValue);
    void AddTail(int iValue);
    int Get(int iIndex) const;
    int GetHead(void) const;
    int GetTail(void) const;
    void Clear(void);
    void Print(void) const;
    int Size() const { return m_iSize; }

private:
    int m_iSize;
    Node *m_pHead, *m_pTail;

    bool CheckIndex(int iIndex) const;
    Node* GetNode(int iIndex) const;
};
