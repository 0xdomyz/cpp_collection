// g++ test_std_str.cpp -o test_std_str && echo "asdf" | ./test_std_str

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "hello";
    cout << s << endl;

    string t;
    getline(cin, t);
    cout << t << endl;
}
