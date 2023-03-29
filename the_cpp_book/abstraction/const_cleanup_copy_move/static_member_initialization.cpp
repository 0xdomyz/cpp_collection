// Compile and run: g++ static_member_initialization.cpp -o static_member_initialization && ./static_member_initialization

class Node
{
    // ...
    static int node_count; // declaration
};
int Node::node_count = 0; // definition

class Curious
{
public:
    static const int c1 = 7; // OK
    // static int c2 = 11;            // error : not const
    const int c3 = 13; // OK, but not static (§17.4.4)
    // static const int c4 = sqrt(9); // error : in-class initializer not constant
    // static const float c5 = 7.0;   // error : in-class not integral (use constexpr rather than const)
    // ...
};

const int Curious::c1;       // don’t repeat initializer here
const int *p = &Curious::c1; // OK: Curious::c1 has been defined

template <class T, int N>
class Fixed
{ // fixed-size array
public:
    static constexpr int max = N;
    // ...
private:
    T a[max];
};

class X
{
    enum
    {
        c1 = 7,
        c2 = 11,
        c3 = 13,
        c4 = 17
    };
    // ...
};

int main(void)
{
    return 0;
}