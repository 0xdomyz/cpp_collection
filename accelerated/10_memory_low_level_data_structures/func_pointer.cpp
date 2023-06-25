// g++ func_pointer.cpp -o func_pointer && ./func_pointer

#include <iostream>
#include <vector>

using namespace std;

template <class In, class Pred>
In find_if(In begin, In end, Pred f)
{
    // while (begin != end && !f(*begin))
    while (begin != end && !(*f)(*begin))
        ++begin;
    return begin;
}

bool is_negative(int n)
{
    return n < 0;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(-2);

    {
        vector<int>::iterator i = find_if(v.begin(), v.end(), is_negative);
        cout << *i << endl;
    }
    {

        vector<int>::iterator i = find_if(v.begin(), v.end(), &is_negative);
        cout << *i << endl;
    }
}
