// g++ assignment_initialization.cpp -o assignment_initialization && ./assignment_initialization

#include <iostream>
#include <string>
#include "split.h"
#include <vector>

using namespace std;

int main()
{
    {
        string url_ch = "~;/?:@=&$-_.+!*'(),"; // initialization
        string spaces(url_ch.size(), ' ');     // initialization
        string y;                              // initialization
        y = url_ch;                            // assignment
    }

    {
        vector<string> v;                // initialization
        string line = "Hello, world!";   // initialization
        v = split<vector<string>>(line); // on entry, initialization of split's parameter from line;
                                         // on exit, both initialization of the return value
                                         // and assignment to v
        for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
            cout << *it;
        cout << endl;
    }
}
