// g++ lower_upper.cpp -o lower_upper && echo "asdf 3fads Adsf AFEEW dsfFee" | ./lower_upper

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool has_upper(const string &s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (isupper(*it))
        {
            return true;
        }
    }
    return false;
}

bool starts_with_upper(const string &s)
{
    if (s.size() > 0 && isupper(s[0]))
    {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, const vector<string> &v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        os << *it << endl;
    }
    return os;
}

int main(void)
{

    // read in vector of strings
    string s;
    vector<string> strings;
    while (cin >> s)
    {
        strings.push_back(s);
    }

    // for each string, find out if it begins with uppper or lower case letter
    // if upper, add to vector of upper case strings
    // if lower, add to vector of lower case strings
    vector<string> upper;
    vector<string> lower;
    for (auto it = strings.begin(); it != strings.end(); ++it)
    {
        if (starts_with_upper(*it))
        {
            upper.push_back(*it);
        }
        else
        {
            lower.push_back(*it);
        }
    }

    // write out lower
    cout << "lower:" << endl;
    cout << lower << endl;

    // write out upper
    cout << "upper:" << endl;
    cout << upper << endl;
}