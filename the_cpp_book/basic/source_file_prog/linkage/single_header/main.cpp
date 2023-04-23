#include "dc.h"
#include <sstream>
#include <iostream> // redundant: in dc.h

using namespace std;

void Driver::calculate()
{
    for (;;)
    {
        ts.get();
        if (ts.current().kind == Kind::end)
            break;
        if (ts.current().kind == Kind::print)
            continue;
        cout << expr(false) << '\n';
    }
}

// complie all .cpp files in the current directory and run example
// g++ error.cpp lexer.cpp main.cpp parser.cpp table.cpp -o dc
// g++ *.cpp -o dc && ./dc "rate=1.1934;150/rate+3;19.75/(1-rate);217/-rate"

int main(int argc, char *argv[])
{

    switch (argc)
    {
    case 1: // read from standard input
        break;
    case 2: // read from argument string
        Lexer::ts.set_input(new istringstream{argv[1]});
        break;
    default:
        Error::error("too many arguments");
        return 1;
    }
    Table::table["pi"] = 3.1415926535897932385; // inser t predefined names
    Table::table["e"] = 2.7182818284590452354;
    Driver::calculate();
    return Error::no_of_errors;
}