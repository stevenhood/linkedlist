class Node
{
public:
    Node(void);
    Node(int iValue, Node *pNext);
    ~Node(void);
    int GetValue() const { return m_iValue; }
    void SetValue(int n) { m_iValue = n; }
    Node* GetNext() const { return m_pNext; }
    void SetNext(Node *pNode) { m_pNext = pNode; }

private:
    int m_iValue;
    Node *m_pNext;
};
