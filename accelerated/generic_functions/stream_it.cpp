// g++ stream_it.cpp -o stream_it && echo "1 2 3 aaa " | ./stream_it

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v;
    // read ints from the standard input and append them to v
    copy(istream_iterator<int>(cin), istream_iterator<int>(),
         back_inserter(v));

    // write the elements of v each separated from the other by a space
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    // write outputs
    cout << endl;

    return 0;
}
