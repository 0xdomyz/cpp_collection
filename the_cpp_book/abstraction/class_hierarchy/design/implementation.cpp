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
    int slider_pos; // position of slider
public:
    Ival_slider(int a, int b) : Ival_box{a, b}, slider_pos{10} {};
    int get_value()
    {
        return Ival_box::get_value();
    }
    void set_value(int i) { Ival_box::set_value(i); };
    void prompt() override
    {
        cout << "Enter a value between " << low << " and " << high << ": ";
        // get value from user
        int value;
        std::cin >> value;
        set_value(value);
        cout << "Value set to " << value << endl;
    };
    bool was_changed() const { return Ival_box::was_changed(); };
};

// use Ival_box as a base class for all kinds of Ival objects
void interact(Ival_box *pb)
{
    pb->prompt(); // aler t user
    // ...
    bool changed = pb->was_changed();
    cout << "Changed: " << changed << endl;

    int i = pb->get_value();
    if (pb->was_changed())
    {
        // ... new value; do something ...
        cout << "New value: " << i << endl;
    }
    else
    {
        // ... do something else ...
        cout << "No change" << endl;
    }
};

// use Ival_box as a base class for all kinds of Ival objects
void some_fct()
{
    unique_ptr<Ival_box> p1{new Ival_slider{0, 5}}; // Ival_slider derived from Ival_box
    interact(p1.get());
};

int main(void)
{
    some_fct();
    return 0;
}
