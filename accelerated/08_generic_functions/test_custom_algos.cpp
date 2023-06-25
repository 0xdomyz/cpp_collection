// g++ test_custom_algos.cpp -o test_custom_algos && ./test_custom_algos

#include <iostream>
#include <vector>
#include "custom_algos.h"
#include <cassert>
#include <iterator>

using namespace std;
// make a alias for our custom algorithms' namespace
namespace ca = custom_algos;

ostream &operator<<(ostream &os, const vector<int> &v)
{
    os << "[";
    auto it = v.begin();
    if (it != v.end())
    {
        os << *it;
        ++it;
    }
    while (it != v.end())
    {
        os << ", " << *it;
        ++it;
    }
    os << "]";
    return os;
}

int main()
{
    {
        // equal(b, e, d)
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2{1, 2, 3, 4, 5};
        vector<int> v3{1, 2, 3, 4, 5, 6};
        vector<int> v4{1, 2, 3, 4, 6};
        vector<int> v5{1};

        assert(!ca::equal(v.begin(), v.end(), v4.begin()));

        // d can be longer than [b, e)
        assert(ca::equal(v.begin(), v.end(), v2.begin()));
        assert(ca::equal(v.begin(), v.end(), v3.begin()));
        assert(ca::equal(v5.begin(), v5.end(), v.begin()));
        assert(!ca::equal(v.begin(), v.end(), v5.begin()));
    }

    // search(b, e, b2, e2)
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2{3, 4};
        vector<int> v3{3, 5};

        assert(ca::search(v.begin(), v.end(), v2.begin(), v2.end()) == v.begin() + 2);
        assert(ca::search(v.begin(), v.end(), v3.begin(), v3.end()) == v.end());
    }

    // find(b, e, t)
    {
        vector<int> v{1, 2, 3, 4, 5};
        assert(ca::find(v.begin(), v.end(), 3) == v.begin() + 2);
        assert(ca::find(v.begin(), v.end(), 6) == v.end());
    }

    // find_if(b, e, p)
    {
        vector<int> v{1, 2, 3, 4, 5};
        assert(ca::find_if(v.begin(), v.end(), [](int i)
                           { return i == 3; }) == v.begin() + 2);
        assert(ca::find_if(v.begin(), v.end(), [](int i)
                           { return i == 6; }) == v.end());
    }

    // copy(b, e, d)
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2(5);
        vector<int> v3;

        ca::copy(v.begin(), v.end(), v2.begin());
        assert(ca::equal(v.begin(), v.end(), v2.begin()));

        ca::copy(v.begin(), v.end(), back_inserter(v3));
        assert(ca::equal(v.begin(), v.end(), v3.begin()));
    }

    // remove_copy(b, e, d, t)
    {
        vector<int> v{1, 2, 3, 4, 5, 3};
        vector<int> v3;

        ca::remove_copy(v.begin(), v.end(), back_inserter(v3), 3);
        vector<int> expected{1, 2, 4, 5};
        assert(ca::equal(v3.begin(), v3.end(), expected.begin()));

        v3.clear();
        ca::remove_copy(v.begin(), v.end(), back_inserter(v3), 6);
        assert(ca::equal(v3.begin(), v3.end(), v.begin()));
    }

    // remove_copy_if(b, e, d, p)
    {
        vector<int> v{1, 2, 3, 4, 5, 3};
        vector<int> v3;

        ca::remove_copy_if(v.begin(), v.end(), back_inserter(v3), [](int i)
                           { return i == 3; });
        vector<int> expected{1, 2, 4, 5};
        assert(ca::equal(v3.begin(), v3.end(), expected.begin()));

        v3.clear();
        ca::remove_copy_if(v.begin(), v.end(), back_inserter(v3), [](int i)
                           { return i == 6; });
        assert(ca::equal(v3.begin(), v3.end(), v.begin()));
    }

    // remove(b, e, t)
    {
        vector<int> v{1, 2, 3, 4, 5, 3};
        vector<int> expected{1, 2, 4, 5};
        vector<int> expected_full{1, 2, 4, 5, 5, 3};

        auto it = ca::remove(v.begin(), v.end(), 3);
        assert(ca::equal(v.begin(), it, expected.begin()));
        assert(ca::equal(v.begin(), v.end(), expected_full.begin()));
    }

    // transform(b, e, d, f)
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2(5);
        vector<int> v3;

        ca::transform(v.begin(), v.end(), v2.begin(), [](int i)
                      { return i * 2; });
        vector<int> expected{2, 4, 6, 8, 10};
        assert(ca::equal(v2.begin(), v2.end(), expected.begin()));

        ca::transform(v.begin(), v.end(), back_inserter(v3), [](int i)
                      { return i * 2; });
        assert(ca::equal(v3.begin(), v3.end(), expected.begin()));
    }

    // partition(b, e, p)
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> expected{1, 3, 5, 4, 2};

        ca::partition(v.begin(), v.end(), [](int i)
                      { return i % 2 == 1; });
        assert(ca::equal(v.begin(), v.end(), expected.begin()));
    }

    // accumulate(b, e, t)
    {
        vector<int> v{1, 2, 3, 4, 5};

        assert(ca::accumulate(v.begin(), v.end(), 0) == 15);
        assert(ca::accumulate(v.begin(), v.end(), 1, [](int a, int b)
                              { return a * b; }) == 120);
    }
}
