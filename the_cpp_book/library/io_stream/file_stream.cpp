// g++ file_stream.cpp -o file_stream && ./file_stream
#include <fstream>
#include <iostream>

using namespace std;

void error(const string &s)
{
    throw runtime_error(s);
}

int main()
{
    ofstream out("file_stream.txt");
    if (!out)
        error("couldn't open 'target' for writing");
    out << "Hello, world!" << endl;
    out << "This is a test." << endl;
    out.close();

    ifstream in;
    in.open("file_stream.txt", ios_base::in);
    if (!in)
        error("couldn't open 'source' for reading");
    char c;
    while (in.get(c))
        cout << c;
    in.close();

    // write a comma separated list of doubles to a file
    ofstream out2("file_stream2.txt");
    if (!out2)
        error("couldn't open 'target' for writing");
    double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    for (int i = 0; i < 5; ++i)
        out2 << d[i] << (i < 4 ? "," : "");
    out2.close();

    // read a comma separated list of doubles from a file
    ifstream in2;
    in2.open("file_stream2.txt", ios_base::in);
    if (!in2)
        error("couldn't open 'source' for reading");
    double d2[5];
    char ch;
    for (int i = 0; i < 5; ++i)
    {
        in2 >> d2[i];
        in2.get(ch);
    }
    in2.close();

    for (int i = 0; i < 5; ++i)
        cout << d2[i] << (i < 4 ? "," : "");
    cout << endl;

    return 0;
}