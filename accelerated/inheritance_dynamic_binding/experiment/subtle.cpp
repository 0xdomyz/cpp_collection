// g++ subtle.cpp -o subtle && ./subtle
// derived class's function hides base class's function if they have the same name

#include <iostream>

using namespace std;

class Core
{
public:
    void regrade(double d)
    {
        final = d;
        cout << "Core::regrade(double d)" << endl;
    }

protected:
    double final;

private:
};

class Grad : public Core
{
public:
    void regrade(double d1, double d2)
    {
        final = d1;
        thesis = d2;
        cout << "Grad::regrade(double d1, double d2)" << endl;
    }

private:
    double thesis;
};

int main(void)
{
    Core c;
    Core *cp = &c;

    cout << "cp->regrade(100)" << endl;
    cp->regrade(100);

    Grad g;
    cout << "g.regrade(100, 100)" << endl;
    g.regrade(100, 100);

    cp = &g;
    cout << "cp->regrade(100)" << endl;
    cp->regrade(100);

    Grad *gp = &g;
    cout << "gp->regrade(100, 100)" << endl;
    gp->regrade(100, 100);

    return 0;
}
