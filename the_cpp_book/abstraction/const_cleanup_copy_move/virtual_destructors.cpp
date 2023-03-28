// Compile and run: g++ virtual_destructors.cpp -o virtual_destructors && ./virtual_destructors

#include <iostream>
#include <string>

using namespace std;

class Shape
{
public:
    // ...
    virtual void draw() = 0;
    virtual ~Shape();
};
class Circle
{
public:
    // ...
    void draw();
    ~Circle(); // overr ides ~Shape()
    // ...
private:
    int radius;
    string name;
};

void user(Shape *p)
{
    p->draw(); // invoke the appropriate draw()
    // ...
    delete p; // invoke the appropriate destructor
};

int main()
{
    Shape *p = new Circle;
    user(p);
}
