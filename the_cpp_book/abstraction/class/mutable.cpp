// Compile and run: g++ mutable.cpp -o mutable && ./mutable

#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    // ...
    Date(int dd, int mm, int yy) : d{dd}, m{mm}, y{yy}, cache_valid{false} {};
    string string_rep() const; // string representation
private:
    int d, m, y; // representation
    mutable bool cache_valid;
    mutable string cache;
    void compute_cache_value() const; // fill (mutable) cache
    // ...
};

string Date::string_rep() const
{
    if (!cache_valid)
    {
        compute_cache_value();
        cache_valid = true;
    }
    return cache;
}

void Date::compute_cache_value() const
{
    cache = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
}

void f(Date d, const Date cd)
{
    string s1 = d.string_rep();
    string s2 = cd.string_rep(); // OK!
    // ...
    cout << s1 << endl;
    cout << s2 << endl;
}

int main(void)
{
    Date d{1, 2, 1991};
    const Date cd{3, 4, 1991};
    f(d, cd);
    f(cd, d); // OK!
    return 0;
}