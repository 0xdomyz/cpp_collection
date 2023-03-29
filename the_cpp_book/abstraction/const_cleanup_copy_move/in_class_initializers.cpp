// Compile and run: g++ in_class_initializers.cpp -o in_class_initializers && ./in_class_initializers

#include <iostream>
#include <string>

using namespace std;

class HashFunction
{
public:
    HashFunction() : name{"MD5"} {}
    HashFunction(string name) : name{name} {}
    // ...
private:
    string name;
};

class D
{
public:
    D() : d{7} {}
    D(int d_val) : d{d_val} {}
    // ...
private:
    int d;
};

int g(D d)
{
    return 0;
}

class A
{
public:
    A() : a{7}, b{5}, algorithm{"MD5"}, state{"Constructor run"} {}
    A(int a_val) : a{a_val}, b{5}, algorithm{"MD5"}, state{"Constructor run"} {}
    A(D d) : a{7}, b{g(d)}, algorithm{"MD5"}, state{"Constructor run"} {}
    // ...
private:
    int a, b;
    HashFunction algorithm; // cr yptographic hash to be applied to all As
    string state;           // string indicating state in object life cycle
};

class A2
{
public:
    A2() : a{7}, b{5} {}
    A2(int a_val) : a{a_val}, b{5} {}
    A2(D d) : a{7}, b{g(d)} {}
    // ..
private:
    int a, b;
    HashFunction algorithm{"MD5"};   // cr yptographic hash to be applied to all As
    string state{"Constructor run"}; // string indicating state in object life cycle
};

class A3
{
public:
    A3() {}
    A3(int a_val) : a{a_val} {}
    A3(D d) : b{g(d)} {}
    // ...
private:
    int a{7};                        // the meaning of 7 for a is ...
    int b{5};                        // the meaning of 5 for b is ...
    HashFunction algorithm{"MD5"};   // Cr yptographic hash to be applied to all As
    string state{"Constructor run"}; // String indicating state in object lifecycle
};

int count = 0;
int count2 = 0;
int f(int i) { return i + count; }
struct S
{
    int m1{count2};   // that is, ::count2
    int m2{f(m1)};    // that is, this->m1+::count; that is, ::count2+::count
    S() { ++count2; } // very odd constructor
};
int main()
{
    S s1; // {0,0}
    ++count;
    S s2; // {1,2}
}