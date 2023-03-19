// g++ declaration.cpp -o declaration && ./declaration

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void error(const char *p)
{
    cout << p << endl;
}

void f(vector<string> &v, int i, const char *p)
{
    if (p == nullptr)
        return;
    if (i < 0 || v.size() <= i)
        error("bad index");
    string s = v[i];
    if (s == p)
    {
        // ...
    }
    // ...
}

void use()
{
    string s1;
    s1 = "The best is the enemy of the good.";
    // ...
}

string s2{"Voltaire"};

void input()
{
    int max = 100;
    int buf[max];
    int count = 0;

    cout << "Enter some integers (negative to quit):" << endl;
    for (int i; cin >> i;)
    {
        cout << i << endl;
        if (i < 0)
            error("unexpected negative value");
        if (count == max)
            error("buffer overflow");
        buf[count++] = i;
    }
    cout << "You entered " << count << " integers." << endl;

    // ...
    for (int i = 0; i < count; ++i)
        cout << buf[i] << endl;
}

int main()
{
    vector<string> v{"The", "best", "is", "the", "enemy", "of", "the", "good."};
    f(v, 0, "The");

    use();

    cout << s2 << endl;

    input();

    return 0;
}