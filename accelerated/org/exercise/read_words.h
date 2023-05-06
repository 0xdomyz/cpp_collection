
#include <iostream>
#include <string>
#include <vector>

// read in words from an input stream, storing them in a vector
// stop when we hit the word "end" or the end of the input
std::istream &read_words(std::istream &in, std::vector<std::string> &words);

void print_words(std::vector<std::string> &words);
