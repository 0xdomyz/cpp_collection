/* Shows how to use both command line and config file. */

// g++ -I /usr/local/boost_1_82_0 -o multiple_sources multiple_sources.cpp /usr/local/lib/libboost_program_options.a

// ./multiple_sources --help
// ./multiple_sources -c multiple_sources.cfg
// ./multiple_sources --optimization=4 -I foo a.cpp b.cpp
// ./multiple_sources --optimization=4 -I foo -c multiple_sources.cfg a.cpp b.cpp

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

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
        int opt;
        string config_file;

        // multiple sources

        // allowed only on command line
        po::options_description generic("Generic options");
        generic.add_options()("version,v", "print version string");
        generic.add_options()("help", "produce help message");
        generic.add_options()("config,c", po::value<string>(&config_file)->default_value("multiple_sources.cfg"),
                              "name of a file of a configuration.");

        // allowed both on command line and in config file
        po::options_description config("Configuration");
        config.add_options()("optimization", po::value<int>(&opt)->default_value(10),
                             "optimization level");
        config.add_options()("include-path,I",
                             po::value<vector<string>>()->composing(),
                             //  values will be accumulated
                             "include path");

        // Hidden options, will be allowed both on command line and
        // in config file, but will not be shown to the user.
        po::options_description hidden("Hidden options");
        hidden.add_options()("input-file", po::value<vector<string>>(), "input file");

        // use add to further group the mutually exclusive options above
        po::options_description cmdline_options; // for parsing command line
        cmdline_options.add(generic).add(config).add(hidden);

        po::options_description config_file_options; // for parsing config file
        config_file_options.add(config).add(hidden);

        po::options_description visible("Allowed options"); // for displaying
        visible.add(generic).add(config);

        // parse
        po::positional_options_description p;
        p.add("input-file", -1);

        po::variables_map vm;
        store(po::command_line_parser(ac, av).options(cmdline_options).positional(p).run(), vm);
        notify(vm);

        // process
        ifstream ifs(config_file.c_str());
        if (!ifs)
        {
            cout << "can not open config file: " << config_file << "\n";
            return 0;
        }
        else
        {
            // parse the config file
            // the values stored first is prefered
            // for composing option, the values are accumulated
            store(parse_config_file(ifs, config_file_options), vm);
            notify(vm);
        }

        if (vm.count("help"))
        {
            cout << visible << "\n";
            return 0;
        }

        if (vm.count("version"))
        {
            cout << "Multiple sources example, version 1.0\n";
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

        cout << "Optimization level is " << opt << "\n";
    }
    catch (exception &e)
    {
        cout << e.what() << "\n";
        return 1;
    }
    return 0;
}
