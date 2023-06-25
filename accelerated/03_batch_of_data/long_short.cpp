// g++ long_short.cpp -o long_short && ./long_short

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s;
    string longest, shortest;

    cout << "Enter words, enter 'quit' to quit" << endl;
    while (cin >> s && s != "quit")
    {
        if (longest.empty() || s.size() > longest.size())
        {
            longest = s;
        }
        if (shortest.empty() || s.size() < shortest.size())
        {
            shortest = s;
        }
    }

    cout << "longest: " << longest << endl;
    cout << "shortest: " << shortest << endl;

    return 0;
}