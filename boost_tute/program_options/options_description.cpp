// g++ -I /usr/local/boost_1_82_0 -o options_description options_description.cpp /usr/local/lib/libboost_program_options.a

// ./options_description --help
// ./options_description -v 2 -l 1002 -I a --input-file a
// ./options_description -v 2 -l 1002 -I a b c d

#include <boost/program_options.hpp>

using namespace boost;
namespace po = boost::program_options;

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

// A helper function to simplify the main part.
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
    return os;
}

int main(int ac, char *av[])
{
    try
    {
        po::options_description desc("Allowed options");

        desc.add_options()("help", "produce help message");

        // address of variable
        // default value
        int opt;
        desc.add_options()("optimization", po::value<int>(&opt)->default_value(10),
                           "optimization level");

        desc.add_options()("verbose,v", po::value<int>()->implicit_value(1),
                           "enable verbosity (optionally specify level)");
        int portnum;
        desc.add_options()("listen,l", po::value<int>(&portnum)->implicit_value(1001)->default_value(0, "no"),
                           "listen on a port.");

        // short hand
        // possible to specify option of vec multiple times
        desc.add_options()("include-path,I", po::value<vector<string>>(),
                           "include path");

        desc.add_options()("input-file", po::value<vector<string>>(), "input file");

        // positional arg translate into specified option
        po::positional_options_description p;
        p.add("input-file", -1);

        // use the parser to parse complex cases
        po::variables_map vm;
        po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(), vm);
        po::notify(vm);

        // processing
        if (vm.count("help"))
        {
            cout << "Usage: options_description [options]\n";
            cout << desc;
            return 0;
        }

        if (vm.count("include-path"))
        {
            cout << "Include paths are: "
                 << vm["include-path"].as<vector<string>>() << "\n";
        }

        if (vm.count("input-file"))
        {
            cout << "Input files are: "
                 << vm["input-file"].as<vector<string>>() << "\n";
        }

        if (vm.count("verbose"))
        {
            cout << "Verbosity enabled.  Level is " << vm["verbose"].as<int>()
                 << "\n";
        }

        cout << "Optimization level is " << opt << "\n";

        cout << "Listen port is " << portnum << "\n";
    }
    catch (std::exception &e)
    {
        cout << e.what() << "\n";
        return 1;
    }
    return 0;
}
