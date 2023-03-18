// Compile and run: g++ regexp.cpp -o regexp -std=c++11 && ./regexp
// XX12345-4567

#include <regex>
#include <iostream>

using namespace std;

int main(void)
{
    std::string pat_str = R"(\w{2}\s*\d{5}(-\d{4})?)";
    // ZIP code pattern: XXddddd-dddd and variants
    std::regex pat(pat_str);
    std::cout << "pattern: " << pat_str << '\n';

    int lineno = 0;
    for (string line; getline(cin, line);)
    { // read into line buffer
        ++lineno;
        smatch matches;                       // matched strings go here
        if (regex_search(line, matches, pat)) // search for pat in line
            cout << lineno << ": " << matches[0] << '\n';
        // if empty, break
        if (matches.empty())
            break;
    }
}