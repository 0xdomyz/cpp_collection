// Compile and run: g++ physical_logical_constness.cpp -o physical_logical_constness && ./physical_logical_constness

#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    Date(int dd, int mm, int yy) : d{dd}, m{mm}, y{yy}, cache_valid{false} {};
    const string string_rep() const
    {
        if (!cache_valid)
        {
            // compute_cache_value();
        }
        return cache;
    }; // string representation
private:
    int d, m, y; // representation
    bool cache_valid;
    string cache;
    void compute_cache_value()
    {
        cache = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
        cache_valid = true;
    }; // fill cache
    // ...
};
