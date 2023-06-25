// g++ test_vec.cpp -o test_vec && ./test_vec

#include <iostream>
#include <string>
#include "vec.h"

using namespace std;

int main(void)
{
    // construct a Vec
    Vec<string> vs;     // empty Vec
    Vec<double> v(100); // Vec with 100 elements

    // push elements onto the Vec
    vs.push_back("hello");
    vs.push_back("world");
    vs.push_back("!");
    vs.push_back("1");

    // obtain the names of the types used by the Vec
    // use size and the index operator to look at each element in the Vec
    Vec<string>::size_type i = 0;
    for (i = 0; i != vs.size(); ++i)
        cout << vs[i] << " ";
    cout << endl;

    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;

    // obtain the names of the types used by the Vec
    // return iterators positioned on the first and one past the last element
    Vec<string>::const_iterator b, e;
    b = vs.begin();
    e = vs.end();
    cout << *b << endl;
    cout << *(--e) << endl;

    {
        // erase
        Vec<string> vs;
        vs.push_back("hello");
        vs.push_back("world");
        vs.push_back("!");
        vs.push_back("1");

        cout << "before erase: " << endl;
        cout << vs << endl;

        cout << "erase the third element: " << endl;
        auto it = vs.begin();
        ++it;
        ++it;
        vs.erase(it);
        cout << vs << endl;

        cout << "erase the first element: " << endl;
        it = vs.begin();
        vs.erase(it);
        cout << vs << endl;

        cout << "erase the last element: " << endl;
        it = vs.end();
        vs.erase(--it);
        cout << vs << endl;

        cout << "erase the only element: " << endl;
        it = vs.begin();
        vs.erase(it);
        cout << vs << endl;
    }

    {
        cout << "test clear: " << endl;
        Vec<string> vs;
        vs.push_back("hello");
        vs.push_back("world");
        vs.push_back("!");

        cout << "before clear: " << endl;
        cout << vs << endl;

        vs.clear();

        cout << "after clear: " << endl;
        cout << vs << endl;
    }
}
