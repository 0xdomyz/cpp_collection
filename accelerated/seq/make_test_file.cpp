// g++ make_test_file.cpp -o make_test_file && ./make_test_file 1000 test_file.csv

// write csv with below formated data, n rows
// aaa 57 98 45.5 67.8 90.2

// test file: ./make_test_file 1000 test_file.csv && ./grading < test_file.csv
// ./make_test_file 1000 test_1000.csv
// ./make_test_file 10000 test_10000.csv
// ./make_test_file 20000 test_20000.csv
// ./make_test_file 50000 test_50000.csv
// ./make_test_file 100000 test_100000.csv
// ./make_test_file 500000 test_500000.csv

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<double> generate_scores_vector(int n)
{
    vector<double> v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(rand() % 100 + 1); // rand gives 0 to RAND_MAX, mod 100 to get 0 to 99
    }
    return v;
}

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <number of rows> <output file name>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    string output_file_name = argv[2];

    ofstream output_file(output_file_name);
    if (!output_file)
    {
        cout << "Error: cannot open output file " << output_file_name << endl;
        return 1;
    }

    // seed random number generator
    // srand(time(NULL));
    srand(0);

    for (int i = 0; i < n; ++i)
    {
        int number_of_scores = rand() % 8 + 3; // rand gives 0 to RAND_MAX, so we add 3 to get 3 to 10
        vector<double> v = generate_scores_vector(number_of_scores);

        string payload = "";
        // random 5 alpha character string
        for (int i = 0; i < 5; ++i)
        {
            payload += (char)(rand() % 26 + 97); // rand gives 0 to RAND_MAX, so we add 97 to get 97 to 122
        }

        for (auto iter = v.begin(); iter != v.end(); ++iter)
        {
            // double to string but keep only 1 decimal place
            string score = to_string(*iter);
            payload += " " + score.substr(0, score.find(".") + 2);
        }

        output_file << payload << endl;
    }

    output_file.close();

    return 0;
}