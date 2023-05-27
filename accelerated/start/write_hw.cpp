// g++ write_hw.cpp -o write_hw && ./write_hw > hw.cpp && g++ hw.cpp -o hw && ./hw
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;
    v.push_back("// g++ hw.cpp -o hw && ./hw");
    v.push_back("// a small C++ program");
    v.push_back("#include <iostream>");
    v.push_back("int main()");
    v.push_back("{");
    v.push_back("    std::cout << \"Hello, world!\" << std::endl;");
    v.push_back("    return 0;");
    v.push_back("}");

    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << endl;

    return 0;
}