// g++ pointers.cpp -o pointers && ./pointers

void f(void)
{
    char c = 'a';
    char *p = &c; // p holds the address of c; & is the address-of operator
}

void g(void)
{
    char c = 'a';
    char *p = &c; // p holds the address of c; & is the address-of operator
    char c2 = *p; // c2 == ’a’; * is the dereference operato
}

int func2(char *p)
{
    return 0;
} // function definition not allowed in another function

void h(void)
{
    int *pi;     // pointer to int
    char **ppc;  // pointer to pointer to char
    int *ap[15]; // array of 15 pointers to ints

    int func(char *); // function taking a char* argument; returns an int

    // define the function

    int (*fp)(char *) = &func2; // pointer to function taking a char* argument; returns an int

    int *f(char *); // function taking a char* argument; returns a pointer to int
}

int main(void)
{
    f();
    g();
    h();
    return 0;
}
