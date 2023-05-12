// g++ algos.cpp -o algos && ./algos

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <list>

using namespace std;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        os << *i;
        if (i != v.end() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const list<T> &v)
{
    os << "[";
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        os << *i;
        if (i != v.end() && next(i) != v.end())
            os << ", ";
    }
    os << "]";
    return os;
}

int main()
{

    // front_inserter
    {
        vector<int> v{1, 2, 3, 4, 5};
        list<int> v2;
        copy(v.begin(), v.end(), front_inserter(v2));
        cout << "front_inserter:" << endl;
        cout << "copy(v.begin(), v.end(), front_inserter(v2));" << endl;
        cout << v << endl;
        cout << v2 << endl;
        cout << endl;
    }

    // back_inserter
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2;
        copy(v.begin(), v.end(), back_inserter(v2));
        cout << "back_inserter:" << endl;
        cout << "copy(v.begin(), v.end(), back_inserter(v2));" << endl;
        cout << v << endl;
        cout << v2 << endl;
        cout << endl;
    }

    // inserter
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2;
        copy(v.begin(), v.end(), inserter(v2, v2.begin()));
        cout << "inserter:" << endl;
        cout << "copy(v.begin(), v.end(), inserter(v2, v2.begin()));" << endl;
        cout << v << endl;
        cout << v2 << endl;
        cout << endl;
    }

    // accumulate
    {
        vector<int> v{1, 2, 3, 4, 5};
        cout << "accumulate:" << endl;
        cout << v << endl;
        cout << "accumulate(v.begin(), v.end(), 0);" << endl;
        cout << accumulate(v.begin(), v.end(), 0) << endl;
        cout << endl;
    }

    // accumulate 3 elements only
    {
        vector<int> v{1, 2, 3, 4, 5};
        cout << "accumulate:" << endl;
        cout << v << endl;
        cout << "accumulate(v.begin(), v.begin() + 3, 0);" << endl;
        cout << accumulate(v.begin(), v.begin() + 3, 0) << endl;
        cout << endl;
    }

    // accumulate 3 elements only on a list
    // by first obtain the 3rd iterator on a list
    {
        list<int> v{1, 2, 3, 4, 5};
        cout << "accumulate:" << endl;
        cout << v << endl;
        cout << "accumulate(v.begin(), next(v.begin(), 3), 0);" << endl;
        cout << accumulate(v.begin(), next(v.begin(), 3), 0) << endl;
        cout << endl;
    }

    // find
    {
        vector<int> v{1, 2, 3, 4, 5};
        cout << "find:" << endl;
        cout << v << endl;
        cout << "*find(v.begin(), v.end(), 3);" << endl;
        cout << *find(v.begin(), v.end(), 3) << endl;
        cout << endl;
    }

    // find_if
    {
        vector<int> v{1, 2, 3, 4, 5};
        cout << "find_if:" << endl;
        cout << v << endl;
        cout << "*find_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; });" << endl;
        cout << *find_if(v.begin(), v.end(), [](int i)
                         { return i % 2 == 0; })
             << endl;
        cout << endl;
    }

    // search
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2{3, 4};
        cout << "search:" << endl;
        cout << v << endl;
        cout << v2 << endl;
        cout << "*search(v.begin(), v.end(), v2.begin(), v2.end());" << endl;
        cout << *search(v.begin(), v.end(), v2.begin(), v2.end()) << endl;
        cout << endl;
    }

    // copy
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2;
        cout << "copy:" << endl;
        cout << v << endl;
        cout << "copy(v.begin(), v.end(), back_inserter(v2));" << endl;
        copy(v.begin(), v.end(), back_inserter(v2));
        cout << v2 << endl;
        cout << endl;
    }

    // remove_copy
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2;
        cout << "remove_copy:" << endl;
        cout << v << endl;
        cout << "remove_copy(v.begin(), v.end(), back_inserter(v2), 3);" << endl;
        remove_copy(v.begin(), v.end(), back_inserter(v2), 3);
        cout << v2 << endl;
        cout << endl;
    }

    // remove_copy_if
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2;
        cout << "remove_copy_if:" << endl;
        cout << v << endl;
        cout << "remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](int i) { return i % 2 == 0; });" << endl;
        remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](int i)
                       { return i % 2 == 0; });
        cout << v2 << endl;
        cout << endl;
    }

    // remove_if
    {
        vector<int> v{1, 2, 3, 4, 5};
        cout << "remove_if:" << endl;
        cout << v << endl;
        cout << "remove_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; });" << endl;
        auto iter = remove_if(v.begin(), v.end(), [](int i)
                              { return i % 2 == 0; });
        cout << v << endl;
        cout << *iter << endl;
        cout << endl;
    }

    // transform
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2;
        cout << "transform:" << endl;
        cout << v << endl;
        cout << "transform(v.begin(), v.end(), back_inserter(v2), [](int i) { return i * 2; });" << endl;
        transform(v.begin(), v.end(), back_inserter(v2), [](int i)
                  { return i * 2; });
        cout << v2 << endl;
        cout << endl;
    }

    // partition
    {
        vector<int> v{1, 2, 3, 4, 5};
        cout << "partition:" << endl;
        cout << v << endl;
        cout << "partition(v.begin(), v.end(), [](int i) { return i % 2 == 0; });" << endl;
        auto iter = partition(v.begin(), v.end(), [](int i)
                              { return i % 2 == 0; });
        cout << v << endl;
        cout << *iter << endl;
        cout << endl;
    }

    // stable_partition
    {
        vector<int> v{1, 2, 3, 4, 5};
        cout << "stable_partition:" << endl;
        cout << v << endl;
        cout << "stable_partition(v.begin(), v.end(), [](int i) { return i % 2 == 0; });" << endl;
        auto iter = stable_partition(v.begin(), v.end(), [](int i)
                                     { return i % 2 == 0; });
        cout << v << endl;
        cout << *iter << endl;
        cout << endl;
    }

    // equal
    {
        vector<int> v{1, 2, 3, 4, 5};
        vector<int> v2{5, 4, 3, 2, 1};
        cout << "equal:" << endl;
        cout << v << endl;
        cout << v2 << endl;
        cout << "equal(v.begin(), v.end(), v2.rbegin());" << endl;
        cout << equal(v.begin(), v.end(), v2.rbegin()) << endl;
        cout << endl;
    }
}