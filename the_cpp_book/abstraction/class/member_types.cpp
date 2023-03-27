// Compile and run: g++ member_types.cpp -o member_types && ./member_types

template <typename T>
class Tree
{
    using value_type = T; // member alias
    enum Policy
    {
        rb,
        splay,
        treeps
    }; // member enum
    class Node
    { // member class
        Node *right;
        Node *left;
        value_type value;

    public:
        void f(Tree<T> *);
    };
    Node *top;

public:
    void g(const Node *);
    // ...
};

template <typename T>
void Tree<T>::Node::f(Tree<T> *p)
{
    // top = right;                // error : no object of type Tree specified
    p->top = right;             // OK
    value_type v = left->value; // OK: value_type is not associated with an object
};

template <typename T>
void Tree<T>::g(const Tree<T>::Node *p)
{
    // value_type val = right->value;  // error : no object of type Tree::Node
    // value_type v = p->right->value; // error : Node::r ight is private
    p->f(this); // OK
};

int main(void)
{
    return 0;
}