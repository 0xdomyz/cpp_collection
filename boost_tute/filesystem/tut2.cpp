// g++ -I /usr/local/boost_1_82_0 -o tut2 tut2.cpp /usr/local/lib/libboost_filesystem.a
// ./tut2 tut2.cpp
// ./tut2 tut2asdf.cpp
// ./tut2 /usr/local/lib/libboost_filesystem.so
// ./tut2 .

#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Usage: tut2 path\n";
        return 1;
    }

    path p(argv[1]); // avoid repeated path construction below

    if (exists(p)) // does path p actually exist?
    {
        if (is_regular_file(p)) // is path p a regular file?
            cout << p << " size is " << file_size(p) << '\n';

        else if (is_directory(p)) // is path p a directory?
            cout << p << " is a directory\n";

        else
            cout << p << " exists, but is not a regular file or directory\n";
    }
    else
        cout << p << " does not exist\n";

    return 0;
}