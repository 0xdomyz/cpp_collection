// g++ -o accept accept.cpp -std=c++11 && ./accept

#include <iostream>
using namespace std;

bool accept3()
{
    int tries = 1;
    while (tries < 4)
    {
        cout << "Do you want to proceed (y or n)?\n"; // write question
        char answer = 0;
        cin >> answer; // read answer
        switch (answer)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "Sorry, I don't understand that.\n";
            ++tries; // increment
        }
    }
    cout << "I'll take that for a no.\n";
    return false;
}

int main()
{
    bool res = accept3();
    if (res)
        cout << "OK, let's go!\n";
    else
        cout << "OK, let's stop!\n";
}