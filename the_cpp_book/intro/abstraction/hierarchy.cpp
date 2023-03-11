// g++ -std=c++11 -o hierarchy hierarchy.cpp && ./hierarchy smiley
// circle { 1 2 3 }
// 1

#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
};

class Shape
{
public:
    virtual Point center() const = 0; // pure virtual
    virtual void move(Point to) = 0;
    virtual void draw() const = 0; // draw on current "Canvas"
    virtual void rotate(int angle) = 0;
    virtual ~Shape() {} // destructor
    // ...
};

void rotate_all(vector<Shape *> &v, int angle) // rotate v’s elements by angle degrees
{
    for (auto p : v)
        p->rotate(angle);
}

class Circle : public Shape
{
public:
    Circle(Point p, int rr)
    {
        x = p;
        r = rr;
    }; // constructor
    Point center() const { return x; }
    void move(Point to) { x = to; }
    void draw() const
    {
        cout << "Circle::draw() const" << endl;
    };
    void rotate(int) {} // nice simple algorithm
private:
    Point x; // center
    int r;   // radius
};

class Smiley : public Circle
{ // use the circle as the base for a face
public:
    Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} {}
    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes)
            delete p;
    }
    void move(Point to)
    {
        Circle::move(to);
        for (auto p : eyes)
            p->move(to);
        mouth->move(to);
    };
    void draw() const;
    void rotate(int)
    {
        cout << "Smiley::rotate(int)" << endl;
    };
    void add_eye(Shape *s) { eyes.push_back(s); }
    void set_mouth(Shape *s)
    {
        delete mouth;
        mouth = s;
    };
    virtual void wink(int i)
    {
        cout << "Smiley::wink(int)" << endl;
    }; // wink eye number i
    // ...
private:
    vector<Shape *> eyes; // usually two eyes
    Shape *mouth;
};

void Smiley::draw() const // const because we don’t change the Smiley object
{
    Circle::draw(); // draw the face
    for (auto p : eyes)
        p->draw(); // draw the eyes
    mouth->draw(); // draw the mouth
}

class Triangle : public Shape
{
    Point x1, x2, x3;

public:
    Triangle(Point p1, Point p2, Point p3)
    {
        x1 = p1;
        x2 = p2;
        x3 = p3;
    };
    Point center() const
    {
        return Point{(x1.x + x2.x + x3.x) / 3, (x1.y + x2.y + x3.y) / 3};
    }
    void move(Point to) { x1 = to; };
    void draw() const { cout << "Triangle::draw() const" << endl; };
    void rotate(int) { cout << "Triangle::rotate(int)" << endl; };
    // ...
};

enum class Kind
{
    circle,
    triangle,
    smiley
};
Shape *read_shape(istream &is) // read shape descriptions from input stream is
{
    // read input stream and determine kind of shape
    // stream has the form: kind {kind data}
    // where kind is one of circle, triangle, or smiley
    // and kind data is a list of values of the appropriate type
    // for example: circle {Point{123,321} 42}
    // or: triangle {Point{0,0} Point{100,0} Point{50,100}}
    // or: smiley {Point{0,0} 42 circle {Point{10,10} 5} circle {Point{20,20} 5} triangle {Point{0,0} Point{10,0} Point{5,10}}}

    string word;
    Kind k;
    Point p;
    int r;

    is >> word;
    if (word == "circle")
        k = Kind::circle;
    else if (word == "triangle")
        k = Kind::triangle;
    else if (word == "smiley")
        k = Kind::smiley;
    else
        return nullptr;

    switch (k)
    {
    case Kind::circle:
        // read circle data {Point,int} into p and r
        is >> word; // read "{"
        if (word != "{")
            throw runtime_error("bad shape start");
        is >> p.x >> p.y >> r;
        is >> word; // read "}"
        if (word != "}")
            throw runtime_error("bad shape end");

        return new Circle{p, r};
    case Kind::triangle:
        // read triangle data {Point,Point,Point} into p1, p2, and p3
        is >> word; // read "{"
        if (word != "{")
            throw runtime_error("bad shape start");
        Point p1, p2, p3;
        is >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        is >> word; // read "}"
        if (word != "}")
            throw runtime_error("bad shape end");

        return new Triangle{p1, p2, p3};
    case Kind::smiley:
        // read smiley data {Point,int,Shape,Shape,Shape} into p, r, e1 ,e2, and m
        is >> word; // read "{"
        if (word != "{")
            throw runtime_error("bad shape start");
        Shape *e1, *e2, *m;
        is >> p.x >> p.y >> r;
        e1 = read_shape(is);
        e2 = read_shape(is);
        m = read_shape(is);
        is >> word; // read "}"
        if (word != "}")
            throw runtime_error("bad shape end");

        Smiley *ps = new Smiley{p, r};
        ps->add_eye(e1);
        ps->add_eye(e2);
        ps->set_mouth(m);
        return ps;
    }

    return nullptr;
}

void draw_all(vector<Shape *> &v)
{
    for (auto p : v)
        p->draw();
}

void user()
{
    std::vector<Shape *> v;
    // read shapes from cin and store pointers in v
    // terminate input if returns nullptr
    for (Shape *p; (p = read_shape(cin));)
        v.push_back(p);

    draw_all(v);       // call draw() for each element
    rotate_all(v, 45); // call rotate(45) for each element
    for (auto p : v)
        delete p; // remember to delete elements
}

int main()
{
    user();
}
