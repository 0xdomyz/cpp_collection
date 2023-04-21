#include <iostream> // I/O
#include <string>   // strings
#include <map>      // map
#include <cctype>   // isalpha(), etc.

using namespace std;

// grammar
/*
program:
    end // end is end-of-input
    expr_list end

expr_list:
    expression print // print is newline or semicolon
    expression print expr_list

expression:
    expression + term
    expression - term
    term

term:
    term / primary
    term * primary
    primary

primary:
    number // number is a floating-point literal
    name // name is an identifier
    name = expression
    - primar y
    ( expression )
*/

// namespaces

namespace Lexer
{
}

namespace Parser
{
    using namespace Lexer;

    double expr(bool);
    double prim(bool get);
    double term(bool get);
    double expr(bool);
}

namespace Lexer
{
    enum class Kind : char
    {
        name,
        number,
        end,
        plus = '+',
        minus = '-',
        mul = '*',
        div = '/',
        print = ';',
        assign = '=',
        lp = '(',
        rp = ')'
    };
    struct Token
    {
        Kind kind;
        string string_value;
        double number_value;
    };
    bool isnumber(char ch);
    class Token_stream
    {
    public:
        Token_stream(istream &s) : ip{&s}, owns{false} {}
        Token_stream(istream *p) : ip{p}, owns{true} {}
        ~Token_stream() { close(); }
        Token get();      // read and return next token
        Token &current(); // most recently read token
        void set_input(istream &s);
        void set_input(istream *p);

    private:
        void close();
        istream *ip;         // pointer to an input stream
        bool owns;           // does the Token_stream own the istream?
        Token ct{Kind::end}; // current token
    };
    Token_stream ts{cin}; // use input from cin
}

namespace Table
{
    map<string, double> table;
}

namespace Driver
{
    using Lexer::Kind;
    using Lexer::ts;
    using Parser::expr;
    void calculate();
}

namespace Error
{
    int no_of_errors;
    double error(const string &s);
}

// implementations - Lexer

void Lexer::Token_stream::set_input(istream &s)
{
    close();
    ip = &s;
    owns = false;
};

void Lexer::Token_stream::set_input(istream *p)
{
    close();
    ip = p;
    owns = true;
};

void Lexer::Token_stream::close()
{
    if (owns)
        delete ip;
}

// implementations - Parser

double Parser::expr(bool get) // add and subtract
{
    double left = term(get);
    for (;;)
    { // ‘‘forever’’
        switch (ts.current().kind)
        {
        case Kind::plus:
            left += term(true);
            break;
        case Kind::minus:
            left -= term(true);
            break;
        default:
            return left;
        }
    }
}

double Parser::term(bool get) // multiply and divide
{
    double left = prim(get);
    for (;;)
    {
        switch (ts.current().kind)
        {
        case Kind::mul:
            left *= prim(true);
            break;
        case Kind::div:
            if (auto d = prim(true))
            {
                left /= d;
                break;
            }
            return Error::error("divide by 0");
        default:
            return left;
        }
    }
}

double Parser::prim(bool get) // handle primar ies
{
    if (get)
        ts.get(); // read next token
    switch (ts.current().kind)
    {
    case Kind::number: // floating-point constant
    {
        double v = ts.current().number_value;
        ts.get();
        return v;
    }
    case Kind::name:
    {
        double &v = Table::table[ts.current().string_value]; // find the corresponding
        if (ts.get().kind == Kind::assign)
            v = expr(true); // ’=’ seen: assignment
        return v;
    }
    case Kind::minus: // unar y minus
        return -prim(true);
    case Kind::lp:
    {
        auto e = expr(true);
        if (ts.current().kind != Kind::rp)
            return Error::error("')' expected");
        ts.get(); // eat ’)’
        return e;
    }
    default:
        return Error::error("primary expected");
    }
}

// implementations - Lexer

bool Lexer::isnumber(char ch)
{
    return ch >= '0' && ch <= '9';
}

Lexer::Token Lexer::Token_stream::get()
{
    char ch;
    do
    { // skip whitespace except ’\n’
        if (!ip->get(ch))
            return ct = {Kind::end};
    } while (ch != '\n' && isspace(ch));
    switch (ch)
    {
    case 0:
        return ct = {Kind::end}; // assign and return
    case ';':
    case '\n':
        return ct = {Kind::print}; // end of expression; print
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
        return ct = {static_cast<Kind>(ch)};
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
        if (isnumber(ch))
        {
            string string_value{ch};
            while (ip->get(ch) && (isnumber(ch) || ch == '.'))
                string_value += ch; // append ch to end of string_value
            ip->putback(ch);
            ct.kind = Kind::number;
            ct.number_value = stod(string_value); // convert string to double
            return ct;
        }
        Error::error("bad number token");
        return ct = {Kind::print};
    default: // NAME, NAME=, or error
        if (isalpha(ch))
        {
            string string_value{ch};
            while (ip->get(ch) && isalnum(ch))
                string_value += ch; // append ch to end of string_value
            ip->putback(ch);
            ct = {Kind::name};
            ct.string_value = string_value;
            return ct;
        }
        Error::error("bad alpha token");
        return ct = {Kind::print};
    }
}

Lexer::Token &Lexer::Token_stream::current()
{
    return ct;
}

// error handling
double Error::error(const string &s)
{
    no_of_errors++;
    cerr << "error: " << s << '\n';
    return 1;
}

// driver

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

// interactive driver
// g++ dc.cpp -o dc && ./dc

// int main()
// {
//     table["pi"] = 3.1415926535897932385; // inser t predefined names
//     table["e"] = 2.7182818284590452354;
//     calculate();
//     return no_of_errors;
// }

// cmd driver
// g++ dc.cpp -o dc && ./dc "rate=1.1934;150/rate+3;19.75/(1-rate);217/-rate"

#include <sstream>

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

// vector<string> arguments(int argc, char∗ argv[])
// {
//     vector<string> res;
//     for (int i = 0; i != argc; ++i)
//         res.push_back(argv[i]);
//     return res;
// }
