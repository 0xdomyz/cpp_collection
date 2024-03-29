// Compile and run: g++ static_members.cpp -o static_members && ./static_members

class Date
{
    int d, m, y;
    static Date default_date;

public:
    Date(int dd = 0, int mm = 0, int yy = 0);
    // ...
    static void set_default(int dd, int mm, int yy); // set default_date to Date(dd,mm,yy)
};

Date::Date(int dd, int mm, int yy)
{
    d = dd ? dd : default_date.d;
    m = mm ? mm : default_date.m;
    y = yy ? yy : default_date.y;
    // ... check that the Date is valid ...
}

void Date::set_default(int d, int m, int y) // definition of Date::set_default
{
    default_date = {d, m, y}; // assign new value to default_date
}

void f()
{
    Date::set_default(4, 5, 1945); // call Date’s static member set_default()
}

void f(Date){};
void g()
{
    f(Date{});
}

// {} is equivalent to Date{}:
void f1(Date){};
void f2(Date){};
void f2(int){};
void g2()
{
    f1({});     // OK: equivalent to f1(Date{})
                // f2({}) :             // error : ambiguous: f2(int) or f2(Date)?
    f2(Date{}); // OK
}

Date Date::default_date{16, 12, 1770}; // definition of Date::default_date
int main(void)
{
    f();
    Date copy_of_default_date = Date{};
    g();

    g2();
    return 0;
}