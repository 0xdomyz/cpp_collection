// g++ test_max.cpp -o test_max && ./test_max

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    {
        int maxlen{0};
        const string s = "hello world";
        // max(s.size(), maxlen);
    }

    {
        typedef string::size_type str_sz;

        str_sz maxlen{0};
        const string s = "hello world";

        auto max_len = max(s.size(), maxlen);

        cout << "max_len: " << max_len << endl;
    }
}
