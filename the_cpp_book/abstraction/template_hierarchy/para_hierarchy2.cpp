// g++ para_hierarchy2.cpp -o para_hierarchy2 -std=c++11 && ./para_hierarchy2

class X
{
    // ...
};
class Cx
{ // interface expressed in terms of types in scope
    X mem;

public:
    virtual X &f();
    virtual int g();
    virtual void h(X &);
    X &get_mem() { return mem; };
};

X &Cx::f()
{
    return mem;
}

int Cx::g()
{
    return 0;
}

void Cx::h(X &)
{
}

class DA : public Cx
{ // derived class
public:
    X &f() { return Cx::get_mem(); };
    int g() { return 0; };
    void h(X &){};
};

class DB : public Cx
{          // derived class
    DB *p; // representation can be more extensive than what the base provides
public:
    X &f() { return Cx::get_mem(); };
    int g() { return 0; };
    void h(X &){};
    void k(int){}; // added functionality
};

int main(void)
{
    Cx &cxa{*new DA}; // cxa is an interface to a DA
    Cx &cxb{*new DB}; // cxb is an interface to a DB
}