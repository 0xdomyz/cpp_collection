// g++ string_literal.cpp -o string_literal && ./string_literal

#include <iostream>
#include <string>

using namespace std;

// Example implementation of standard-library function
size_t strlen(const char *p)
{
    size_t size = 0;
    while (*p++ != '\0')
        ++size;
    return size;
}

int main()
{
    const char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << "hello: " << hello << endl;
    cout << "strlen(hello): " << strlen(hello) << endl;

    string s(hello);
    cout << "s: " << s << endl;

    string s2("Hello");
    cout << "s2: " << s2 << endl;

    string s3(hello, hello + strlen(hello));
    cout << "s3: " << s3 << endl;

    return 0;
}
