// Compile and run: g++ iterator_traits.cpp -std=c++11 -o iterator_traits && ./iterator_traits

#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>
#include <algorithm>
#include <string>
#include <type_traits>

using namespace std;

template <typename C>
using Iterator_type = typename C::iterator; // C’s iterator type

template <typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category; // Iter’s categor

template <typename Ran>                                        // for random-access iterators
void sort_helper(Ran beg, Ran end, random_access_iterator_tag) // we can subscript into [beg:end)
{
    cout << "random_access_iterator_tag" << endl;
    sort(beg, end); // just sort it, does it modify the original vector? yes
}

template <typename For>                                  // for forward iterators
void sort_helper(For beg, For end, forward_iterator_tag) // we can traverse [beg:end)
{
    cout << "forward_iterator_tag" << endl;
    // vector<decltype(*beg)> v{beg, end}; // initialize a vector from [beg:end)
    // this gives &int, does decltype(*beg) return a reference? depends
    vector<typename iterator_traits<For>::value_type> v{beg, end}; // initialize a vector from [beg:end)
    // value_type is the type of the elements in the iterator
    std::sort(v.begin(), v.end());
    copy(v.begin(), v.end(), beg); // copy the elements back
}

template <typename C>
void sort(C &c)
{
    using Iter = Iterator_type<C>;
    sort_helper(c.begin(), c.end(), Iterator_category<Iter>{});
}

void test(vector<string> &v, forward_list<int> &lst)
{
    sort(v); // sor t the vector
    // sort_helper(v.begin(), v.end(), Iterator_category<vector<string>::iterator>{});
    sort(lst); // sor t the singly-linked list
    // sort_helper(lst.begin(), lst.end(), Iterator_category<forward_list<int>::iterator>{});
}

void determine_type(vector<string> &v, forward_list<int> &lst)
{

    cout << "vector<string> v: " << is_same<vector<string>::iterator, Iterator_type<vector<string>>>::value << endl;
    cout << "forward_list<int> lst: " << is_same<forward_list<int>::iterator, Iterator_type<forward_list<int>>>::value << endl;
}

void determine_category(vector<string> &v, forward_list<int> &lst)
{

    cout << "vector<string> v: " << is_same<random_access_iterator_tag, Iterator_category<vector<string>::iterator>>::value << endl;
    cout << "forward_list<int> lst: " << is_same<forward_iterator_tag, Iterator_category<forward_list<int>::iterator>>::value << endl;
}

void determin_if_able_to_call_begin_end(vector<string> &v, forward_list<int> &lst)
{

    cout << "vector<string> v: " << is_same<vector<string>::iterator, decltype(v.begin())>::value << endl;
    cout << "forward_list<int> lst: " << is_same<forward_list<int>::iterator, decltype(lst.begin())>::value << endl;
}

void print_vector_or_list(vector<string> &v, forward_list<int> &lst)
{
    cout << "vector<string> v: " << endl;
    for (auto &s : v)
        cout << s << " ";
    cout << endl;

    cout << "forward_list<int> lst: " << endl;
    for (auto &i : lst)
        cout << i << " ";
    cout << endl;
}

int main(void)
{

    vector<string> v{"zzz", "bbb", "cde", "aaaa"};

    forward_list<int> lst{3, 2, 1, 7};
    // list stored on contiguous memory? no

    // determine_type(v, lst);
    // determine_category(v, lst);
    // determin_if_able_to_call_begin_end(v, lst);

    cout << "before sort" << endl;
    print_vector_or_list(v, lst);

    test(v, lst);

    cout << "after sort" << endl;
    print_vector_or_list(v, lst);

    return 0;
}