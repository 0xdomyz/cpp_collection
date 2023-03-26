// Compile and run: g++ const_member_func.cpp -o const_member_func && ./const_member_func

class Date
{
    int d, m, y;

public:
    int day() const { return d; }
    int month() const { return m; }
    int year() const
    {
        return y;
    };
    void add_year(int n)
    {
        y += n;
    }; // add n years
    // ...
};

// int Date::year() const
// {
//     return ++y; // error : attempt to change member value in const function
// }

// int Date::year() // error : const missing in member function type
// {
//     return y;
// }

void f(Date &d, const Date &cd)
{
    int i = d.year();  // OK
    d.add_year(1);     // OK
    int j = cd.year(); // OK
    // cd.add_year(1);    // error : cannot change value of a const Date
}

int main(void)
{
    Date today;
    const Date tomorrow = today;
    f(today, tomorrow);
    return 0;
}