class Node
{
public:
    int getValue() const { return value; }
    void setValue(int n) { value = n; }
    Node* getNext() const { return next; }
    void setNext(Node *node) { next = node; }

private:
    int value;
    Node *next;
};
