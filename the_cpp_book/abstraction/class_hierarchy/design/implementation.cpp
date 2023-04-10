// compile and run: g++ -o implementation implementation.cpp && ./implementation

#include <iostream>
#include <memory>

using namespace std;

class Ival_box
{
protected:
    int val;
    int low, high;
    bool changed{false}; // changed by user using set_value()
public:
    Ival_box(int ll, int hh) : val{ll}, low{ll}, high{hh} {}
    virtual int get_value()
    {
        changed = false;
        return val;
    } // for application
    virtual void set_value(int i)
    {
        changed = true;
        val = i;
    } // for user
    virtual void reset_value(int i)
    {
        changed = false;
        val = i;
    } // for application
    virtual void prompt() {}
    virtual bool was_changed() const { return changed; }
    virtual ~Ival_box(){};
};

class Ival_slider : public Ival_box
{
private:
    // ... graphics stuff to define what the slider looks like, etc. ...
    int high, low; // range of values
public:
    Ival_slider(int a, int b) : Ival_box{a, b}, high{b}, low{a} {};
    int get_value() { return 1; };
    void set_value(int){};
    void prompt() { cout << "Enter a value between " << low << " and " << high << ": "; };
    bool was_changed() const { return true; };
};

class Ival_dial : public Ival_box
{
private:
    // ... graphics stuff to define what the dial looks like, etc. ...
    int high, low; // range of values
public:
    Ival_dial(int ll, int hh) : Ival_box{ll, hh}, high{hh}, low{ll} {};
    int get_value() { return 1; };
    void set_value(int){};
    void prompt() { cout << "Enter a value between " << low << " and " << high << ": "; };
    bool was_changed() const { return true; };
};
class Flashing_ival_slider : public Ival_slider
{ /* ... */
};
class Popup_ival_slider : public Ival_slider
{ /* ... */
};

void interact(Ival_box *pb)
{
    pb->prompt(); // aler t user
    // ...
    int i = pb->get_value();
    if (pb->was_changed())
    {
        // ... new value; do something ...
    }
    else
    {
        // ... do something else ...
    }
};

void some_fct()
{
    unique_ptr<Ival_box> p1{new Ival_slider{0, 5}}; // Ival_slider derived from Ival_box
    interact(p1.get());
    unique_ptr<Ival_box> p2{new Ival_dial{1, 12}};
    interact(p2.get());
};

int main(void)
{
    some_fct();
    return 0;
}
