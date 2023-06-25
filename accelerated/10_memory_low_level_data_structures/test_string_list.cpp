// g++ test_string_list.cpp -o test_string_list && ./test_string_list

#include <iostream>
#include <string>
#include "string_list.h"
#include "split.h"

using namespace std;

int main(void)
{

    // list
    {
        String_list v{vector<string>{"aaa", "bbb", "ccc"}};

        cout << "string_list: " << v << endl;

        cout << "assign a new value to the first element: " << endl;
        auto it = v.begin();
        *it = "zzz";
        cout << *it << endl;

        cout << "increment the iterator: " << endl;
        it++;
        cout << *it << endl;

        cout << "decrement the iterator: " << endl;
        it--;
        cout << *it << endl;

        cout << "string_list: " << v << endl;

        cout << "check if the iterator is equal to the end iterator: " << endl;
        bool check{it == v.end()};
        cout << check << endl;

        cout << "iterate through the list: " << endl;
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "iterate through the list in reverse: " << endl;
        for (auto it = v.rbegin(); it != v.rend(); --it)
        {
            cout << *it << " ";
        }
        cout << endl;

        cout << "push back a new element: " << endl;
        v.push_back("ddd");
        cout << "string_list: " << v << endl;
    }

    // split
    {
        string s = "this is not a test 2";
        String_list v;
        split(s, back_inserter(v));
        cout << v << endl;
    }
    return 0;
}
