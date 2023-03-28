// Compile and run: g++ default_constructors.cpp -o default_constructors && ./default_constructors

class String
{
public:
    String(const char *p = ""){

    }; // default constructor : empty string
    // ...
};
String s1;   // OK
String s2{}; // OK

void f()
{
    int a0;              // uninitialized
    int a1();            // function declaration (intended?)
    int a{};             // a becomes 0
    double d{};          // d becomes 0.0
    char *p{};           // p becomes nullptr
    int *p1 = new int;   // uninitialized int
    int *p2 = new int{}; // the int is initialized to 0
}

template <class T>
struct Handle
{
    T *p;
    Handle(T *pp = new T{}) : p{pp} {}
    // ...
};
Handle<int> px; // will generate int{

int glob{9};
struct X
{
    const int a1{7}; // OK
    // const int a2;    // error : requires a user-defined constructor
    const int &r{9}; // OK
    int &r1{glob};   // OK
    // int &r2;         // error : requires a user-defined constructor
};
// X x; // error : no default constructor for X

int main(void)
{
    return 0;
}