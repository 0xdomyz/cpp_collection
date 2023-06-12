// g++ test_pictures.cpp pictures.cpp -o test_pictures && ./test_pictures

#include "pictures.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vs;
    vs.push_back("Hello");
    vs.push_back("World");
    vs.push_back("!");

    // conversion from vector<string> to Picture
    Picture p = vs;
    cout << "p:" << endl;
    cout << p << endl;
    cout << endl;

    // frame
    Picture framed = frame(vs);
    cout << "framed:" << endl;
    cout << framed << endl;
    cout << endl;

    // hcat
    // argument symmentry of nonmember functions
    Picture h_cated = hcat(frame(p), p);
    cout << "h_cated:" << endl;
    cout << h_cated << endl;
    cout << endl;

    Picture h_cated2 = hcat(p, frame(p));
    cout << "h_cated2:" << endl;
    cout << h_cated2 << endl;
    cout << endl;

    // vcat
    Picture v_cated = vcat(p, h_cated);
    cout << "v_cated:" << endl;
    cout << v_cated << endl;
    cout << endl;

    // then frame it
    Picture framed_v_cated = frame(v_cated);
    cout << "framed_v_cated:" << endl;
    cout << framed_v_cated << endl;
    cout << endl;

    return 0;
}