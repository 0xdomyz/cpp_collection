// Compile and run: g++ stream_iterators.cpp -o stream_iterators && ./stream_iterators
// stream_iterators_input.txt
// stream_iterators_output.txt

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;

int f()
{
    string from, to;
    cin >> from >> to;                     // get source and target file names
    ifstream is{from};                     // input stream for file "from"
    istream_iterator<string> ii{is};       // input iterator for stream
    istream_iterator<string> eos{};        // input sentinel
    ofstream os{to};                       // output stream for file "to"
    ostream_iterator<string> oo{os, "\n"}; // output iterator for stream
    vector<string> b{ii, eos};             // b is a vector initialized from input [ii:eos)
    sort(b.begin(), b.end());              // sor t the buffer
    unique_copy(b.begin(), b.end(), oo);   // copy buffer to output, discard replicated values
    return !is.eof() || !os;               // return error state (§2.2.1, §38.3)
}

int f2()
{
    string from, to;
    cin >> from >> to;                                                       // get source and target file names
    ifstream is{from};                                                       // input stream for file "from"
    ofstream os{to};                                                         // output stream for file "to"
    set<string> b{istream_iterator<string>{is}, istream_iterator<string>{}}; // read input
    copy(b.begin(), b.end(), ostream_iterator<string>{os, "\n"});            // copy to output
    return !is.eof() || !os;                                                 // return error state (§2.2.1, §38.3)
}

int main()
{
    ostream_iterator<string> oo{cout}; // write str ings to cout

    *oo = "Hello, "; // meaning cout<<"Hello, "
    ++oo;
    *oo = "world!\n"; // meaning cout<<"wor ld!\n"

    f() ? cout << "error" : cout << "ok";
    cout << endl;
    f2() ? cout << "error" : cout << "ok";
    cout << endl;

    return 0;
}