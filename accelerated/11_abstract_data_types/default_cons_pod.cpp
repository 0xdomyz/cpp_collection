// g++ default_cons_pod.cpp -o default_cons_pod && ./default_cons_pod

#include <iostream>
#include <string>

using namespace std;

struct X
{
    int a;
    string b;
};

struct Y
{
    int a;
    string b;
    Y() : a(0), b("") {}
};

int main()
{
    cout << "Default constructor for POD" << endl;
    X x;
    cout << x.a << endl;
    cout << x.b << endl;

    cout << "Default constructor as defined" << endl;
    Y y;
    cout << y.a << endl;
    cout << y.b << endl;
}
