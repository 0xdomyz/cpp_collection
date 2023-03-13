// g++ strings.cpp -o strings && ./strings

#include <string>
#include <iostream>

using namespace std;

string compose(const string &name, const string &domain)
{
    return name + '@' + domain;
}

void m2(string &s1, string &s2)
{
    s1 = s1 + '\n'; // append newline
    s2 += '\n';     // append newline
}

string name = "Niels Stroustrup";
void m3()
{
    string s = name.substr(6, 10);  // s = "Stroustr up"
    name.replace(0, 5, "nicholas"); // name becomes "nicholas Stroustrup"
    name[0] = toupper(name[0]);     // name becomes "Nicholas Stroustrup"
}

string incantation = "abracadabra";
void respond(const string &answer)
{
    if (answer == incantation)
    {
        // perform magic
        cout << "You said the magic word!\n";
    }
    else if (answer == "yes")
    {
        // do something else
        cout << "You said yes.\n";
    }
    else
    {
        // do nothing
        cout << "You said something else.\n";
    }
}

int main(void)
{
    auto addr = compose("dmr", "bell−labs.com");

    string s1 = "Hello";
    string s2 = "World";
    m2(s1, s2);
    cout << s1 << s2 << endl;

    m3();
    cout << name << endl;

    respond("abracadabra");
}
