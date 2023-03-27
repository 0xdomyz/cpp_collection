// Compile and run: g++ self_reference.cpp -o self_reference && ./self_reference

#include <iostream>
#include <string>

using namespace std;

class Date
{
    // ...
public:
    Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {};
    Date &add_year(int n); // add n years
    Date &add_month(int n)
    {
        if (m == 12)
        {
            this->m = 1;
            this->y++;
        }
        else
        {
            this->m++;
        }
        return *this;
    }; // add n months
    Date &add_day(int n)
    {
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
        else if (m == 2 && leapyear(y))
        {
            if (d > 29)
            {
                d -= 29;
                m++;
            }
        }
        else if (m == 2 && !leapyear(y))
        {
            if (d > 28)
            {
                d -= 28;
                m++;
            }
        }
        d += n;
        return *this;
    }; // add n days
    string string_rep() const
    {
        return to_string(this->y) + "/" + to_string(this->m) + "/" + to_string(this->d);
    }; // return string representation
private:
    int y, m, d; // year, month, day
    bool leapyear(int y)
    {
        return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
    }; // true if y is a leap year
};

Date &Date::add_year(int n)
{
    if (this->d == 29 && this->m == 2 && !leapyear(this->y + n))
    {
        this->d = 1;
        this->m = 3;
    }
    this->y += n;
    return *this;
}

void f(void)
{
    // ...
    Date d3{2000, 1, 1};
    d3.add_day(1).add_month(1).add_year(1);
    cout << d3.string_rep() << endl;

    Date d2{2000, 2, 29};
    d2.add_year(1);
    cout << d2.string_rep() << endl;
    d2.add_day(1);
    cout << d2.string_rep() << endl;
    d2.add_month(1);
    cout << d2.string_rep() << endl;
    // ...
}

int main(void)
{
    f();
}