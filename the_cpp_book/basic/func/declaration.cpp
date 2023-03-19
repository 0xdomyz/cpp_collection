// g++ declaration.cpp -o declaration && ./declaration

struct Elem
{ // a linked list element
    int val;
    Elem *next;
};

Elem *next_elem();   // no argument; return an Elem*
void exit(int);      // int argument; return nothing
double sqrt(double); // double argument; return a doubl

double sqrt(double x) // x is a parameter
{
    return x * x;
}

double s2 = sqrt(2); // call sqrt() with the argument double{2}
// double s3 = sqrt("three"); // error : sqr t() requires an argument of type double

class Info
{
    int i;
    double d;
};

class String
{
public:
    char *p;
    int sz;
    int space;
    char &operator[](int); // subscripting: return reference to char
};

double f(int i, const Info &);                  // type: double(int,const Info&)
char &String::operator[](int x) { return *p; }; // type: char& String::(int)

int main(void) {}