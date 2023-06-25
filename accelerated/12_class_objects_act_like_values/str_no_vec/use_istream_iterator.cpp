// g++ use_istream_iterator.cpp -o use_istream_iterator && echo "hello world" | ./use_istream_iterator

#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main(void)
{
    istream_iterator<string> is_iter(cin);
    istream_iterator<string> eof;
    string s;

    while (is_iter != eof)
    {
        s = *is_iter;
        cout << s << endl;
        ++is_iter;
    }
    return 0;
}