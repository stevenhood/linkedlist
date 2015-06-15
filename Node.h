class Node
{
public:
    Node();
    Node(int iValue, Node *pNext);
    ~Node();
    int getValue() const { return m_iValue; }
    void setValue(int n) { m_iValue = n; }
    Node* getNext() const { return m_pNext; }
    void setNext(Node *pNode) { m_pNext = pNode; }

private:
    int m_iValue;
    Node *m_pNext;
};
