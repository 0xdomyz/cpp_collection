// g++ -I /usr/local/boost_1_82_0 example.cpp -o example && echo 1 2 3 | ./example

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " ");

    std::cout << std::endl;
    return 0;
}