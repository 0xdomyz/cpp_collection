#include "parser.h"
#include "lexer.h"
#include "error.h"
#include "table.h"
#include <sstream>

namespace Driver
{
    using Lexer::Kind;
    using Lexer::ts;
    using Parser::expr;
    void calculate();
}

void Driver::calculate()
{
    for (;;)
    {
        ts.get();
        if (ts.current().kind == Kind::end)
            break;
        if (ts.current().kind == Kind::print)
            continue;
        std::cout << expr(false) << '\n';
    }
}

// complie all .cpp files in the current directory and run example
// g++ *.cpp -o dc && ./dc "rate=1.1934;150/rate+3;19.75/(1-rate);217/-rate"

int main(int argc, char *argv[])
{

    switch (argc)
    {
    case 1: // read from standard input
        break;
    case 2: // read from argument string
        Lexer::ts.set_input(new std::istringstream{argv[1]});
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