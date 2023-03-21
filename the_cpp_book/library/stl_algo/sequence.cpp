// wip
// g++ sequence.cpp -o sequence && ./sequence

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename Cont>
void sort(Cont &c)
{
    // static_assert(Range<Cont>(), "sort(): Cont argument not a Range");
    // static_assert(Sortable<Iterator<Cont>>(), "sort(): Cont argument not Sortable");
    std::sort(begin(c), end(c));
}

template <typename Cont1, typename Cont2>
void copy(const Cont1 &source, Cont2 &target)
{
    // static_assert(Range<Cont1>(), "copy(): Cont1 argument not a Range");
    // static_assert(Range<Cont2>(), "copy(): Cont2 argument not a Range");
    if (target.size() < source.size())
        throw out_of_range{"copy target too small"};
    std::copy(source.begin(), source.end(), target.begin());
}

void user(vector<int> &v1, vector<int> &v2)
{
    copy(v1, v2); // overflows will be caught
    sort(v1);
}

void print_vector(const vector<int> &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

// template <typename Cont, typename Pred>
// vector<Value_type<Cont> *>
// find_all(Cont &c, Pred p)
// {
//     // static_assert(Range<Cont>(), "find_all(): Cont argument not a Range");
//     // static_assert(Predicate<Pred>(), "find_all(): Pred argument not a Predicate");
//     vector<Value_type<Cont> *> res;
//     for (auto &x : c)
//         if (p(x))
//             res.push_back(&x);
//     return res;
// }

int main(void)
{
    vector<int> v1{1, 12, 38, 4, 5};
    vector<int> v2(5);
    user(v1, v2);

    cout << "v1: ";
    print_vector(v1);
    cout << "v2: ";
    print_vector(v2);

    return 0;
}