// g++ test_custom_algos.cpp -o test_custom_algos && ./test_custom_algos

#include <iostream>
#include <vector>
#include "custom_algos.h"
#include <cassert>

using namespace std;
// make a alias for our custom algorithms' namespace
namespace ca = custom_algos;

int main()
{
    {
        // custom_equal(b, e, d)
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2{1, 2, 3, 4, 5};
        vector<int> v3{1, 2, 3, 4, 5, 6};
        vector<int> v4{1, 2, 3, 4, 6};

        // cout << "equal(b, e, d): " << endl;
        // cout << "should be 1: " << ca::equal(v.begin(), v.end(), v2.begin()) << endl;
        // cout << "should be 1: " << ca::equal(v.begin(), v.end(), v3.begin()) << endl;
        // cout << "should be 0: " << ca::equal(v.begin(), v.end(), v4.begin()) << endl;

        // via assert
        assert(ca::equal(v.begin(), v.end(), v2.begin()));
        assert(ca::equal(v.begin(), v.end(), v3.begin()));
        assert(!ca::equal(v.begin(), v.end(), v4.begin()));
    }

    // custom_search(b, e, b2, e2)
    // custom_find(b, e, t)
    // custom_find_if(b, e, p)
    // custom_copy(b, e, d)
    // custom_remove_copy(b, e, d, t)
    // custom_remove_copy_if(b, e, d, p)
    // custom_remove(b, e, t)
    // custom_transform(b, e, d, f)
    // custom_partition(b, e, p)
    // custom_accumulate(b, e, t)
}
