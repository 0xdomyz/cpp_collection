// Compile and run: g++ resource_invariants.cpp -o resource_invariants && ./resource_invariants

template <class T>
class Handle
{
    T *p;

public:
    Handle(T *pp) : p{pp} {}
    T &operator*() { return *p; }
    ~Handle() { delete p; }
    // Handle(const T& a) :p{new T{*a.p}} { } // clone
};

void f1()
{
    Handle<int> h{new int{99}};
    // ...
}

void f2()
{
    // Handle<int> h; // error : no default constructor
    // ...
}

void f3()
{
    Handle<int> h1{new int{7}};
    Handle<int> h2{h1}; // error : no copy constr uctor
    // ...
}

int main(void) {}