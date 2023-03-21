// g++ classification.cpp -o classification && ./classification

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    char ch{'a'};
    if (islower(ch))
    {
        cout << "The character is a lowercase letter" << endl;
    } // a low ercase character
    if (isupper(ch))
    {
        cout << "The character is an uppercase letter" << endl;
    } // an uppercase character

    if (isalpha(ch))
    {
        cout << "The character is a letter" << endl;
    } // a letter

    // example of assign, move, and copy
    string s1{"Hello"};
    string s2{s1};
    string s3;

    s3 = s1;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    // assign
    s1.assign("Hello");

    // move
    s2 = move(s1);
    cout << "s1: " << s1 << endl;

    // copy
    s3 = s2;

    return 0;
}