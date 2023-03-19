// g++ logical.cpp -o logical && ./logical

#include <iostream>

using namespace std;

bool whitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

int main(void)
{
    // string to char*
    // char s[] = "hello world";
    // char *p = s;

    const char *p = "hello world";

    while (p && !whitespace(*p))
    {
        cout << p << endl;
        ++p;
    }
}