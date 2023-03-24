// Compile and run: g++ member_functions.cpp -o member_functions && ./member_functions

#include <iostream>

using namespace std;

struct Date
{
    int d, m, y;
    void init(int dd, int mm, int yy); // initialize
    void add_year(int n) { y += n; };  // add n years
    void add_month(int n)
    {
        m += n;
        if (m > 12)
        {
            m -= 12;
            y++;
        }
    }; // add n months
    void add_day(int n)
    {
        d += n;
        if (m == 1 | m == 3 | m == 5 | m == 7 | m == 8 | m == 10 | m == 12)
        {
            if (d > 31)
            {
                d -= 31;
                m++;
            }
        }
        else if (m == 4 | m == 6 | m == 9 | m == 11)
        {
            if (d > 30)
            {
                d -= 30;
                m++;
            }
        }
        else if (m == 2)
        {
            if (d > 28)
            {
                d -= 28;
                m++;
            }
        }

    }; // add n days
};

Date my_birthday;
void f()
{
    Date today;
    today.init(16, 10, 1996);
    my_birthday.init(30, 12, 1950);
    Date tomorrow = today;
    tomorrow.add_day(1);
    // ...
}

void Date::init(int dd, int mm, int yy)
{
    d = dd;
    m = mm;
    y = yy;
}

int main(void)
{
    Date today;
    today.init(16, 10, 1996);
    my_birthday.init(30, 12, 1950);
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << "Today is " << today.d << "." << today.m << "." << today.y << endl;
    cout << "My birthday is " << my_birthday.d << "." << my_birthday.m << "." << my_birthday.y << endl;
    cout << "Tomorrow is " << tomorrow.d << "." << tomorrow.m << "." << tomorrow.y << endl;
    f();
    return 0;
}