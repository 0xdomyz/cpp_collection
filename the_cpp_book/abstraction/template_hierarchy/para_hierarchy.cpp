// g++ para_hierarchy.cpp -o para_hierarchy -std=c++11 && ./para_hierarchy

template <typename X>
class Ct
{ // interface expressed in terms of the parameter
    X mem;

public:
    X f();
    int g();
    void h(X);
};

class A
{
    // ...
};

class B
{
    // ...
};

template <>
class Ct<A>
{           // specialization (for A)
    A *mem; // the representation can differ from that of the primar y template
public:
    A f();
    int g();
    void h(A);
    void k(int); // added functionality
};

int main(void)
{
    Ct<A> cta; // specialization for A
    Ct<B> ctb; // specialization for B
}