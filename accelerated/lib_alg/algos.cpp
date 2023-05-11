#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::vector<int> v2;
    std::remove_copy_if(v.begin(), v.end(), std::back_inserter(v2), [](int i)
                        { return i % 2 == 0; });
    for (const auto &i : v2)
    {
        std::cout << i << ' ';
    }
}