// g++ -std=c++17 -I/path/to/json/include -I/path/to/cxxopts/include reorder_json.cpp -o reorder_json
// ./reorder_json --filename settings.json

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>
#include <cxxopts.hpp>

using json = nlohmann::json;

int main(int argc, char *argv[])
{
    // Define command-line options
    cxxopts::Options options("reorder_json", "Sort a JSON file by key");
    options.add_options()("f,filename", "Name of the JSON file to sort", cxxopts::value<std::string>())("h,help", "Print help message");

    // Parse command-line options
    auto result = options.parse(argc, argv);

    // Print help message if requested
    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        return 0;
    }

    // Get filename argument
    std::string filename;
    if (result.count("filename"))
    {
        filename = result["filename"].as<std::string>();
    }
    else
    {
        std::cerr << "Error: filename argument is required." << std::endl;
        return 1;
    }

    // Load the JSON file into a JSON object
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << "." << std::endl;
        return 1;
    }
    json data;
    file >> data;

    // Sort the JSON object by key
    std::vector<std::string> keys;
    for (auto &[key, value] : data.items())
    {
        keys.push_back(key);
    }
    std::sort(keys.begin(), keys.end());
    json sorted_data;
    for (auto &key : keys)
    {
        sorted_data[key] = data[key];
    }

    // Write the sorted JSON object to a new file
    std::string new_filename = "sorted_" + filename;
    std::ofstream new_file(new_filename);
    new_file << std::setw(4) << sorted_data << std::endl;

    std::cout << "Successfully sorted " << filename << " and saved as " << new_filename << "." << std::endl;

    return 0;
}