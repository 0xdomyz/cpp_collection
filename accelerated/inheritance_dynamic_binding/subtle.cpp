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
    cp->regrade(100);

    Grad g;
    // g.regrade(100);
    g.regrade(100, 100);

    cp = &g;
    cp->regrade(100);
    // cp->regrade(100, 100);

    Grad *gp = &g;
    // gp->regrade(100);

    return 0;
}
