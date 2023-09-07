// g++ -I /usr/local/boost_1_82_0 -o tut1 tut1.cpp /usr/local/lib/libboost_filesystem.a

// size are the same
// ./tut1 /usr/local/boost_1_82_0/README.md
// ls -l /usr/local/boost_1_82_0/README.md

// throws exception
// ./tut1 /usr/local/boost_1_82_0/READMEdasfasd.md
// ./tut1 /usr/local/boost_1_82_0

#include <iostream>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: tut1 path\n";
        return 1;
    }
    std::cout << argv[1] << " " << file_size(argv[1]) << '\n';
    return 0;
}