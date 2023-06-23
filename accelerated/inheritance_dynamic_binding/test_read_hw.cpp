// g++ test_read_hw.cpp student_info.cpp -o test_read_hw && ./test_read_hw < test_read_hw.csv

#include <iostream>
#include "student_info.h"
#include <vector>
#include <string>

using namespace std;

istream &read_hw2(istream &in, vector<double> &hw)
{
    if (in)
    {
        // get rid of previous contents
        hw.clear();
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

// print vector double
ostream &operator<<(ostream &out, const vector<double> &v)
{
    for (vector<double>::size_type i = 0; i < v.size(); ++i)
    {
        out << v[i] << " ";
    }
    return out;
}

int main(void)
{

    {
        Student_info record;

        record.read(cin);
        cout << record.name() << endl;
        cout << record.grade() << endl;

        record.read(cin);
        cout << record.name() << endl;
        cout << record.grade() << endl;
    }

    {
        // test read_hw
        vector<double> hw;
        string name;

        cin >> name;
        read_hw2(cin, hw);
        cout << name << ": " << hw << endl;

        cin >> name;
        read_hw2(cin, hw);
        cout << name << ": " << hw << endl;

        // records in same line
        cin >> name;
        read_hw2(cin, hw);
        cout << name << ": " << hw << endl;

        // print out wharever in cin
        cout << "print out wharever in cin" << endl;
        char c;
        while (cin >> c)
        {
            cout << c;
        }
        cout << endl;

        // does istream.clear consume the item that the stream is on? No

        // cin >> name;
        // read_hw2(cin, hw);
        // cout << name << ": " << hw << endl;
    }
}