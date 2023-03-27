// Compile and run: g++ concrete_classes.cpp -o concrete_classes && ./concrete_classes

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Chrono
{
    enum class Month
    {
        jan = 1,
        feb = 2,
        mar = 3,
        apr = 4,
        may = 5,
        jun = 6,
        jul = 7,
        aug = 8,
        sep = 9,
        oct = 10,
        nov = 11,
        dec = 12
    };

    class Date
    {
    public: // public interface:
        class Bad_date
        {
        };                                                      // exception class
        explicit Date(int dd = {}, Month mm = {}, int yy = {}); // {} means ‘‘pick a default’

        // nonmodifying functions for examining the Date:
        int day() const { return d; };
        Month month() const { return m; };
        int year() const { return y; };
        string string_rep() const
        {
            return to_string(this->y) + "/" +
                   to_string(static_cast<int>(this->m)) + "/" + to_string(this->d);
        }; // string representation
        void char_rep(char s[], int max) const
        {
            snprintf(s, max, "%d/%d/%d", d, static_cast<int>(m), y);
        }; // C-style string representation

        // (modifying) functions for changing the Date:
        Date &add_year(int);  // add n years
        Date &add_month(int); // add n months
        Date &add_day(int);   // add n days

    private:
        bool is_valid(); // check if this Date represents a date
        int d, y;        // representation
        Month m;
    };

    bool is_date(int d, Month m, int y); // true for valid date
    bool is_leapyear(int y);             // true if y is a leap year

    const Date &default_date(); // the default date

    bool operator==(const Date &, const Date &);
    bool operator!=(Date, Date);                               // inequality
    bool operator<(Date, Date);                                // less than
    bool operator>(Date, Date);                                // greater than
    Date &operator++(Date &d) { return d.add_day(1); }         // increase Date by one day
    Date &operator--(Date &d) { return d.add_day(-1); }        // decrease Date by one day
    Date &operator+=(Date &d, int n) { return d.add_day(n); }  // add n days
    Date &operator-=(Date &d, int n) { return d.add_day(-n); } // subtract n days
    Date operator+(Date d, int n) { return d += n; }           // add n days
    Date operator-(Date d, int n) { return d += n; }           // subtract n days
    ostream &operator<<(ostream &, Date);                      // output d
    istream &operator>>(istream &, Date &);                    // read into d

    Date::Date(int dd, Month mm, int yy)
        : d{dd}, m{mm}, y{yy}
    {
        if (y == 0)
            y = default_date().year();
        if (m == Month{})
            m = default_date().month();
        if (d == 0)
            d = default_date().day();
        if (!is_valid())
            throw Bad_date();
    };

    bool Date::is_valid()
    {
        return is_date(d, m, y);
    };

    Date &Date::add_year(int n)
    {
        y += n;
        return *this;
    }; // add n years

    Date &Date::add_month(int n)
    {
        if (n == 0)
            return *this;
        if (n > 0)
        {
            int delta_y = n / 12;                  // number of whole years
            int mm = static_cast<int>(m) + n % 12; // number of months ahead
            if (12 < mm)
            { // note: dec is represented by 12
                ++delta_y;
                mm -= 12;
            }
            // ... handle the cases where the month mm doesn’t have day d ...
            y += delta_y;
            m = static_cast<Month>(mm);
            return *this;
        }
        // ... handle negative n ...
        return *this;
    }

    Date &Date::add_day(int n)
    {
        if (m == Month::feb && d == 29 && !is_leapyear(y))
        {                   // beware of leap years!
            m = Month::mar; // use March 1 instead of February 29
            d = 1;
            return add_day(n - 1);
        }
        else if (n == 0)
            return *this;
        else if (n > 0)
        {
            int delta_y = n / 365; // number of whole years
            int delta_d = n % 365; // number of days ahead
            if (365 < delta_d)
            { // note: dec is represented by 12
                ++delta_y;
                delta_d -= 365;
            }
            // ... handle the cases where the month mm doesn’t have day d ...
            y += delta_y;
            d += delta_d;
            return *this;
        }

        return *this;
    }; // add n days

    bool operator==(const Date &a, const Date &b)
    {
        return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
    };
    bool operator!=(Date a, Date b)
    {
        return !(a == b);
    };
    bool operator<(Date a, Date b)
    {
        return a.year() < b.year() || (a.year() == b.year() && (a.month() < b.month() || (a.month() == b.month() && a.day() < b.day())));
    }; // less than
    bool operator>(Date a, Date b)
    {
        return b < a;
    }; // greater than

    ostream &operator<<(ostream &os, Date d)
    {
        return os << '(' << d.day() << ',' << static_cast<int>(d.month()) << ',' << d.year() << ')';
    };

    istream &operator>>(istream &is, Date &dd)
    {
        int d, m, y;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> d >> ch2 >> m >> ch3 >> y >> ch4;
        if (!is)
            return is;
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
        {                                // oops: format error
            is.clear(ios_base::failbit); // set the fail bit
            return is;
        }
        dd = Date(d, Month(m), y); // update dd
        return is;
    };

    Date next_weekday(Date d);
    Date next_saturday(Date d);

}; // Chrono

bool Chrono::is_date(int d, Month m, int y)
{
    int ndays;
    switch (m)
    {
    case Month::feb:
        ndays = 28 + is_leapyear(y);
        break;
    case Month::apr:
    case Month::jun:
    case Month::sep:
    case Month::nov:
        ndays = 30;
        break;
    case Month::jan:
    case Month::mar:
    case Month::may:
    case Month::jul:
    case Month::aug:
    case Month::oct:
    case Month::dec:
        ndays = 31;
        break;
    default:
        return false;
    }
    return 1 <= d && d <= ndays;
}

bool Chrono::is_leapyear(int y)
{
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

const Chrono::Date &Chrono::default_date()
{
    static Date d{1, Month::jan, 1970};
    return d;
}

void f(Chrono::Date &d)
{
    using namespace Chrono;
    Date lvb_day{16, Month::dec, d.year()};
    if (d.day() == 29 && d.month() == Month::feb)
    {
        d = lvb_day;
    }
    d.add_day(1);
    cout << "day before:" << d + 1 << '\n';
    Date dd; // initialized to the default date
    cin >> dd;
    if (dd == d)
        cout << "Hurray!\n";
}

// void fill(vector<Date> &aa)
// {
//     while (cin)
//     {
//         Date d;
//         try
//         {
//             cin >> d;
//         }
//         catch (Date::Bad_date)
//         {
//             // ... my error handling ...
//             continue;
//         }
//         aa.push_back(d); // see §4.4.2
//     }
// }

int main(void)
{
    Chrono::Date d{10, Chrono::Month::mar, 2019};
    f(d);
    return 0;
}