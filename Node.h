class Node
{
public:
    Node();
    Node(int value, Node *next);
    ~Node();
    int getValue() const { return m_value; }
    void setValue(int n) { m_value = n; }
    Node* getNext() const { return m_next; }
    void setNext(Node *node) { m_next = node; }

private:
    int m_value;
    Node *m_next;
};
