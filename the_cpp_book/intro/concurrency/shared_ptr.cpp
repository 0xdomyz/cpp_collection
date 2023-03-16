// Compile and run: g++ shared_ptr.cpp -o shared_ptr && ./shared_ptr

#include <iostream>
#include <memory>
#include <fstream>
#include <string>

using namespace std;

class No_file
{
};

void f(shared_ptr<fstream>)
{
    cout << "f()" << endl;
};
void g(shared_ptr<fstream>)
{
    cout << "g()" << endl;
};
void user(const string &name, ios_base::openmode mode)
{
    shared_ptr<fstream> fp{new fstream(name, mode)};
    if (!*fp)
        throw No_file{}; // make sure the file was properly opened
    f(fp);
    g(fp);
    // ...
}

int main(void)
{
    try
    {
        user("shared_ptr.cpp", ios_base::in);
    }
    catch (No_file)
    {
        cerr << "No file" << endl;
    }
    return 0;
}