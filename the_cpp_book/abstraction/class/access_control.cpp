// Compile and run: g++ access_control.cpp -o access_control && ./access_control

class Date
{
    int d, m, y;

public:
    void init(int dd, int mm, int yy)
    {
        d = dd;
        m = mm;
        y = yy;
    };
    void add_year(int n);  // add n years
    void add_month(int n); // add n months
    void add_day(int n);   // add n days
};

void Date::add_year(int n)
{
    y += n;
}

void timewarp(Date &d)
{
    // d.y -= 200; // error : Date::y is private
}

// dx.m = 3;             // error : m is private

int main(void)
{
    Date dx;
    dx.init(12, 12, 2000);
    dx.add_year(1);
    // dx.add_month(1); // error : add_month is private
    // dx.add_day(1);   // error : add_day is private
    return 0;
}