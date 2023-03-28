// Compile and run: g++ destructors_and_resources.cpp -o destructors_and_resources && ./destructors_and_resources

class Vector
{
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}; // constructor: acquire memory
    ~Vector() { delete[] elem; }                   // destructor: release memory
    // ...
private:
    double *elem; // elem points to an array of sz doubles
    int sz;       // sz is non-negative
};

Vector *f(int s)
{
    Vector v1(s);
    // ...
    return new Vector(s + s);
}
void g(int ss)
{
    Vector *p = f(ss);
    // ...
    delete p;
}

int main(void)
{
    f(10);
    g(10);
}