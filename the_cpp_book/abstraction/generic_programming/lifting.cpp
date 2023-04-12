// g++ lifting.cpp -o lifting -std=c++11 && ./lifting

#include <iostream>
#include <iterator>

using namespace std;

double add_all(double *array, int n)
// one concrete algorithm on array of doubles
{
    double s{0};
    for (int i = 0; i < n; ++i)
        s = s + array[i];
    return s;
}

struct Node
{
    Node *next;
    int data;
};

int sum_elements(Node *first, Node *last)
// another concrete algorithm on list of ints
{
    int s = 0;
    while (first != last)
    {
        s += first->data;
        first = first->next;
    }
    return s;
}

// concrete STL-like code:
template <typename Iter, typename Val>
Val sum(Iter first, Iter last)
{
    Val s = 0;
    while (first != last)
    {
        s = s + *first;
        ++first;
    }
    return s;
}

int main(void)
{
    double ad[] = {1, 2, 3, 4};
    double s = add_all(ad, 4);
    cout << s << endl;

    Node *first = new Node{nullptr, 1};
    Node *second = new Node{nullptr, 2};
    first->next = second;
    Node *last = new Node{nullptr, 3};
    second->next = last;
    int s2 = sum_elements(first, last);
    cout << s2 << endl;

    double s3 = sum<double *, double>(ad, ad + 4);
    cout << s3 << endl;
}