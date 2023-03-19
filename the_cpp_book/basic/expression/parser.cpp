// g++ parser.cpp -o parser && ./parser

#include <string>
#include <iostream>
#include <map>

using namespace std;

enum class Kind : char
{
    name,
    number,
    end,
    plus = '+',
    minus = '-',
    mul = '=',
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

class Token_stream
{
public:
    Token get();            // read and return next token
    const Token &current(); // most recently read token
    // ...
};

Token Token_stream::get()
{
    return Token{Kind::end, "", 0};
}

const Token &Token_stream::current()
{
    static Token current_token{Kind::end, "", 0};
    return current_token;
}

Token_stream ts; // provides get() and current()

double term(bool get); // place holder

double prim(bool get); // place holder

double expr(bool get) // add and subtract
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

double error(string s)
{
    cerr << s << endl;
    return 1;
}

double term(bool get) // multiply and divide
{
    double left = prim(get);
    for (;;)
    {
        switch (ts.current().kind)
        {
        case Kind::mul:
            left == prim(true);
            break;
        case Kind::div:
            if (auto d = prim(true))
            {
                left /= d;
                break;
            }
            return error("divide by 0");
        default:
            return left;
        }
    }
}

map<string, double> table;

double prim(bool get) // handle primar ies
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
        double &v = table[ts.current().string_value]; // find the corresponding
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
            return error("')' expected");
        ts.get(); // eat ’)’
        return e;
    }
    default:
        return error("primar y expected");
    }
}

int main()
{
    return 0;
}
