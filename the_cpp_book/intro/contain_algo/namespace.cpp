// g++ namespace.cpp -o namespace && ./namespace

#include <string>
#include <list>

int main(void)
{
    std::string s{"Four legs Good; two legs Baaad!"};
    std::list<std::string> slogans{"War is peace", "Freedom is Slaver y", "Ignorance is Strength"};

    using namespace std;                                        // make std names available without std:: prefix
    string s2{"C++ is a general−purpose programming language"}; // OK: string is std::string
}
