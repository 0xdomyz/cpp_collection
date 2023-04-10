// g++ interface.cpp -o interface && ./interface

#include <iostream>

using namespace std;

class Ival_box
{
public:
    virtual int get_value() = 0;
    virtual void set_value(int i) = 0;
    virtual void reset_value(int i) = 0;
    virtual void prompt() = 0;
    virtual bool was_changed() const = 0;
    virtual ~Ival_box() {}
};

class BBwidget
{
public:
    virtual void draw(){};
    virtual void mouse1hit(int x, int y){};
    virtual void mouse2hit(int x, int y){};
    virtual void mouse3hit(int x, int y){};
    virtual void keyhit(char c){};
    virtual ~BBwidget() {}
};

class Ival_slider : public Ival_box,
                    protected BBwidget
{
public:
    Ival_slider(int, int);
    ~Ival_slider() override;
    int get_value() override;
    void set_value(int i) override;
    // ...
protected:
    // ... functions overr iding BBwidget virtual functions
    // e.g., BBwidget::draw(), BBwidget::mouse1hit() ...
    void draw() override { BBwidget::draw(); };
    void mouse1hit(int x, int y) override { BBwidget::mouse1hit(0, 1); };

private:
    // ... data needed for slider ...
    int low, high;
};

int main(void) {}