// g++ test_frame.cpp -o test_frame && ./test_frame

#include "frame.h"

using namespace std;

int main(void)
{
    vector<string> v;
    cout << width(v) << endl;
    auto f = frame(v);
    cout << f << endl;
    return 0;
}