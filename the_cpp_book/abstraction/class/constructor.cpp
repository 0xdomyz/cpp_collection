// Compile and run: g++ constructor.cpp -o constructor && ./constructor

class Date
{
    int d, m, y;

public:
    Date(int dd, int mm, int yy)
    {
        d = dd;
        m = mm;
        y = yy;
    }; // constructor
    // ...
};

void f(void)
{
    Date today = Date(23, 6, 1983);
    Date xmas(25, 12, 1990); // abbreviated for m
    // Date my_birthday;       // error : initializer missing
    // Date release1_0(10, 12); // error : third argument missing

    Date today2 = Date{23, 6, 1983};
    Date xmas2{25, 12, 1990}; // abbreviated for m
    // Date release1_0{10, 12}; // error : third argument missing
}

class Date2
{
    int d, m, y;

public:
    // ...
    Date2(int, int, int)
    {
        d = 1;
        m = 1;
        y = 1;
    }; // day, month, year
    Date2(int, int)
    {
        d = 1;
        m = 1;
        y = 1;
    }; // day, month, today’s year
    Date2(int)
    {
        d = 1;
        m = 1;
        y = 1;
    }; // day, today’s month and year
    Date2()
    {
        d = 1;
        m = 1;
        y = 1;
    }; // default Date: today
    Date2(const char *)
    {
        d = 1;
        m = 1;
        y = 1;
    }; // date in string representation
};

void g(void)
{
    Date2 today{4}; // 4, today.m, today.y
    Date2 july4{"July 4, 1983"};
    Date2 guy{5, 11}; // 5, November, today.y
    Date2 now;        // default initialized as today
    Date2 start{};    // default initialized as today
}

class Date3
{
    int d, m, y;

public:
    Date3(int dd = 0, int mm = 0, int yy = 0);
    // ...
};

Date3 today{23, 6, 1983};

Date3::Date3(int dd, int mm, int yy)
{
    d = dd ? dd : today.d;
    m = mm ? mm : today.m;
    y = yy ? yy : today.y;
    // check that the Date is valid
}

void h(void)
{
    Date3 today{23, 6, 1983};
    Date3 tomorrow{today};
    Date3 my_birthday; // default initialization
}

int main(void)
{
    f();
    g();
    h();
}