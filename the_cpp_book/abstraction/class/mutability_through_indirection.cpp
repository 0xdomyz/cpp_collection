// Compile and run: g++ mutability_through_indirection.cpp -o mutability_through_indirection && ./mutability_through_indirection

#include <iostream>
#include <string>

using namespace std;

struct cache
{
    bool valid;
    string rep;
};

class Date
{
public:
    // ...
    Date(int dd, int mm, int yy) : d{dd}, m{mm}, y{yy}, c{new cache{false, ""}} {};
    string string_rep() const; // string representation
private:
    int d, m, y;                      // representation
    cache *c;                         // initialize in constr uctor
    void compute_cache_value() const; // fill what cache refers to
    // ...
};

string Date::string_rep() const
{
    if (!c->valid)
    {
        compute_cache_value();
        c->valid = true;
    }
    return c->rep;
}

void Date::compute_cache_value() const
{
    c->rep = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
}

int main(void)
{
    Date d{1, 2, 1991};
    const Date cd{3, 4, 1991};
    cout << d.string_rep() << endl;
    cout << cd.string_rep() << endl;
    return 0;
}