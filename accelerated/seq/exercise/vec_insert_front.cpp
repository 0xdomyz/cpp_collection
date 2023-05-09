// g++ vec_insert_front.cpp -o vec_insert_front && ./vec_insert_front

#include <iostream>
#include <vector>

// << overload for vector
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[ ";
    for (auto i : v)
    {
        os << i << ' ';
    }
    os << ']';
    return os;
}

int main()
{
    std::vector<int> v = {1, 2, 3};

    // iterate over vector and insert elements to front, use indexing not iterators
    for (auto i = 0; i < v.size(); ++i)
    {
        v.insert(v.begin(), v[i] + 1);
        i++;
    }

    // print out vector
    std::cout << v << std::endl;

    return 0;
}