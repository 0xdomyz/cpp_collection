// Compile and run: g++ explicit_constructor.cpp -o explicit_constructor && ./explicit_constructor

// source of confusion
class Date
{
    int d, m, y;

public:
    Date(int dd = 1, int mm = 2, int yy = 1991){};
    // ...
};

void my_fct(Date d){};
void f()
{
    Date d{15}; // plausible: x becomes {15,today.m,today.y}
    // ...
    my_fct(15); // obscure
    d = 15;     // obscure
    // ...
}

// explicit constructor
class Date2
{
    int d, m, y;

public:
    explicit Date2(int dd = 0, int mm = 0, int yy = 0){};
    // ...
};
void my_fct2(Date2 d){};

Date2 d1{15};         // OK: considered explicit
Date2 d2 = Date2{15}; // OK: explicit
// Date2 d3 = {15};      // error : = initialization does not do implicit conversions
// Date2 d4 = 15;        // error : = initialization does not do implicit conversions

void g()
{
    // my_fct2(15);        // error : argument passing does not do implicit conversions
    // my_fct2({15});      // error : argument passing does not do implicit conversions
    my_fct2(Date2{15}); // OK: explicit
    // ...
}

// outside class defn no repeat
class Date3
{
    int d, m, y;

public:
    explicit Date3(int dd);
    // ...
};
Date3::Date3(int dd)
{ /* ... */
} // OK
// explicit Date3::Date3(int dd) { /* ... */ } // erro

// constructor with zero or multiple arguments
struct X
{
    explicit X(){};
    explicit X(int, int){};
};
// X x1 = {};     // error : implicit
// X x2 = {1, 2}; // error : implicit
X x3{};     // OK: explicit
X x4{1, 2}; // OK: explicit
int f2(X) { return 1; };
// int i1 = f({});      // error : implicit
// int i2 = f({1, 2});  // error : implicit
int i3 = f2(X{});     // OK: explicit
int i4 = f2(X{1, 2}); // OK: explicit

int main(void) { return 0; }