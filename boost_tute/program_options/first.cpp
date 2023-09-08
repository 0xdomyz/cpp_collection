// g++ -I /usr/local/boost_1_82_0 -o first first.cpp /usr/local/lib/libboost_program_options.a

// ./first --help
// ./first --compression 4.2

// ./first
// ./first asdfdas

/* The simplest usage of the library.
 */

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <iostream>
#include <iterator>
using namespace std;

int main(int ac, char *av[])
{
    try
    {

        po::options_description desc("Allowed options");

        // add options
        desc.add_options()("help", "produce help message");
        // name, value, description
        desc.add_options()("compression", po::value<double>(), "set compression level");
        // po::value is a factory that produces a value_semantic object

        // parse command line, store options
        po::variables_map vm;
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);

        // variables_map is like map, except for using as type
        if (vm.count("help"))
        {
            cout << desc << "\n";
            return 0;
        }

        if (vm.count("compression"))
        {
            cout << "Compression level was set to "
                 << vm["compression"].as<double>() << ".\n";
        }
        else
        {
            cout << "Compression level was not set.\n";
        }
    }
    catch (exception &e) // std::exception
    {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        cerr << "Exception of unknown type!\n";
    }

    return 0;
}
