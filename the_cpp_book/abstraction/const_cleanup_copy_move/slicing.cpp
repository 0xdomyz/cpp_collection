// Compile and run: g++ slicing.cpp -o slicing && ./slicing

struct Base
{
    int b;
    Base(const Base &){};
    Base(){};
    // ...
};
struct Derived : Base
{
    int d;
    Derived(const Derived &){};
    Derived(){};
    // ...
};
void naive(Base *p)
{
    Base b2 = *p; // may slice: invokes Base::Base(const Base&)
    // ...
}
void user()
{
    Derived d;
    naive(&d);
    Base bb = d; // slices: invokes Base::Base(const Base&), not Derived::Der ived(const Derived&)
    // ...
}

int main()
{
    user();
    return 0;
}