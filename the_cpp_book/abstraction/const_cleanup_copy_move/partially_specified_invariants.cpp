// Compile and run: g++ partially_specified_invariants.cpp -o partially_specified_invariants && ./partially_specified_invariants

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Tic_tac_toe
{
public:
    Tic_tac_toe() : pos(9) {} // always 9 positions
    Tic_tac_toe &operator=(const Tic_tac_toe &arg)
    {
        for (int i = 0; i < 9; ++i)
            pos.at(i) = arg.pos.at(i);
        return *this;
    }
    // ... other operations ...
    enum State
    {
        empty,
        nought,
        cross
    };

private:
    vector<State> pos;
};

class Tic_tac_toe2
{
public:
    Tic_tac_toe2() : pos(9) {} // always 9 positions
    Tic_tac_toe2(const Tic_tac_toe2 &) = default;
    Tic_tac_toe2 &operator=(const Tic_tac_toe2 &arg) = default;
    ~Tic_tac_toe2() = default;
    // ... other operations ...
    enum State
    {
        empty,
        nought,
        cross
    };

private:
    vector<State> pos;
};

class Tic_tac_toe3
{
public:
    // ... other operations ...
    enum State
    {
        empty,
        nought,
        cross
    };

private:
    vector<State> pos{vector<State>(9)}; // always 9 positions
};

int main(void)
{
    return 0;
}
