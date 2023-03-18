// Compile and run: g++ random.cpp -o random && ./random

#include <random>
#include <iostream>
#include <functional>

using namespace std;

class Rand_int
{
public:
    Rand_int(int low, int high) : dist{low, high} {}
    int operator()() { return dist(re); } // draw an int
private:
    default_random_engine re;
    uniform_int_distribution<> dist;
};

int main(void)
{
    using my_engine = default_random_engine;            // type of engine
    using my_distribution = uniform_int_distribution<>; // type of distribution
    my_engine re{};                                     // the default engine
    my_distribution one_to_six{1, 6};                   // distribution that maps to the ints 1..6
    auto die = bind(one_to_six, re);                    // make a generator

    cout << "Using bind" << '\n';
    int x = die(); // roll the die: x becomes a value in [1:6]
    cout << x << '\n';

    cout << "Using bind and a loop" << '\n';
    for (int i = 0; i < 10; ++i)
    {
        cout << die() << '\n'; // roll the die
    }

    cout << "Using default_random_engine and uniform_int_distribution directly" << '\n';
    for (int i = 0; i < 10; ++i)
    {
        auto die2 = bind(uniform_int_distribution<>{1, 6}, default_random_engine{});
        cout << die2() << '\n'; // roll the die
    }

    cout << "Using a class" << '\n';
    Rand_int rnd{1, 10}; // make a random number generator for [1:10]
    int y = rnd();       // x is a number in [1:10]
    cout << y << '\n';

    cout << "Using a class and a loop" << '\n';
    Rand_int rnd2{0, 4};      // make a unifor m random number generator
    vector<int> histogram(5); // make a vector of size 5
    for (int i = 0; i != 10; ++i)
        ++histogram[rnd2()]; // fill histogram with the frequencies of numbers [0:4]
    for (int i = 0; i != histogram.size(); ++i)
    { // write out a bar graph
        cout << i << '\t';
        for (int j = 0; j != histogram[i]; ++j)
            cout << '*';
        cout << endl;
    }
}