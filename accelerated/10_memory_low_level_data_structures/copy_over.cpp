// g++ copy_over.cpp -o copy_over && ./copy_over input.csv

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string apend_word_to_stem(string filename, string word)
{
    auto pos = filename.find_last_of(".");
    string stem = filename.substr(0, pos);
    string extension = filename.substr(pos);
    return stem.append(word).append(extension);
}

int main(int argc, char **argv)
{
    ifstream infile(argv[1]);

    string outfilename = argv[1];
    outfilename = apend_word_to_stem(outfilename, "_copy");

    ofstream outfile(outfilename);
    string s;
    while (getline(infile, s))
        outfile << s << endl;
    return 0;
}
