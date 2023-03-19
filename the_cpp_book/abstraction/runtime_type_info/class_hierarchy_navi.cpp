// g++ class_hierarchy_navi.cpp -o class_hierarchy_navi && ./class_hierarchy_navi

#include <iostream>

using namespace std;

class BBwindow
{
public:
    virtual void handle_event() = 0;
};

class Ival_box : public BBwindow
{
protected:
    int val;
    int low, high;
    bool changed{false}; // changed by user using set_value()
public:
    Ival_box(int v, int l, int h) : val{v}, low{l}, high{h} {}
    int get_value() const { return val; }
    void set_value(int v)
    {
        if (low <= v && v <= high)
        {
            val = v;
            changed = true;
        }
    }
    bool was_changed() const { return changed; }
    void reset_change() { changed = false; }
    void handle_event() { cout << "Ival_box::handle_event()" << endl; }
};

void my_event_handler(BBwindow *pw)
{
    if (auto pb = dynamic_cast<Ival_box *>(pw))
    { // does pw point to an Ival_box?
        // ...
        int x = pb->get_value(); // use the Ival_box
        cout << "x = " << x << endl;
        // ...
    }
    else
    {
        // ... oops! cope with unexpected event ...
    }
}

int main(void)
{
    Ival_box ib{0, 0, 100};
    my_event_handler(&ib);
    return 0;
}