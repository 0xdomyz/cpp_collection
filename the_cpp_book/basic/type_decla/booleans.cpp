// g++ booleans.cpp -o booleans && ./booleans

// 2 values
void f(int a, int b)
{
    bool b1{a == b};
    // ...
}

// common use
struct File
{
    // ...
};

bool is_open(File *);
bool greater(int a, int b) { return a > b; }

// prevent narrowing while use {} by being explicit
void f2(int i)
{
    bool b{i != 0};
    // ...
};

// pointer implicit conversion
void g(int *p)
{
    bool b = p;            // narrows to true or false
    bool b2{p != nullptr}; // explicit test against nullptr
    if (p)
    { // equivalent to p!=nullptr
      // ...
    }
}

int main(void)
{
    // conversion
    bool b1 = 7; // 7!=0, so b becomes true
    // bool b2{7};    // error : narrowing (§2.2.2, §10.5)

    int i1 = true; // i1 becomes 1
    int i2{true};  // i2 becomes 1

    // prevent narrowing while use {} by being explicit
    f2(0);
    f2(7);

    // conversion in arithmetic
    bool a = true;
    bool b = true;
    bool x = a + b;  // a+b is 2, so x becomes true
    bool y = a || b; // a||b is 1, so y becomes true ("||" means "or")
    bool z = a - b;  // a-b is 0, so z becomes false

    // pointer implicit conversion
    g(nullptr);
    g(&i1);

    return 0;
}
