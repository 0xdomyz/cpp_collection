// g++ -I /usr/local/boost_1_82_0 -o bin_example bin_example.cpp /usr/local/lib/libboost_regex.a && ./bin_example < email.txt
// g++ -I /usr/local/boost_1_82_0 -o bin_example bin_example.cpp -L/usr/local/lib/ -lboost_regex && ./bin_example < email.txt

#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    boost::regex pat("^Subject: (Re: |Aw: )*(.*)");

    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }
}