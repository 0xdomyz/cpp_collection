// Compile and run: g++ member_access.cpp -o member_access && ./member_access

struct X
{
    void f();
    int m;
};

void user(X x, X *px)
{
    // m = 1;     // error : there is no m in scope
    x.m = 1; // OK
    // x->m = 1;  // error : x is not a pointer
    px->m = 1; // OK
    // px.m = 1;  // error : px is a pointer
};

void X::f()
{
    m = 1; // OK: ‘‘this->m = 1;’’ (§16.2.10)
}

struct X2
{
    int f() { return m; } // fine: return this X’s m
    int m;
};

struct S
{
    int m;
    int f();
    static int sm;
};
int S::f() { return m; } // X’s f
int S::sm{7};            // X’s static member sm (§16.2.12)

int main(void)
{
}