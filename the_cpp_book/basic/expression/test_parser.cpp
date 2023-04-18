// g++ test_parser.cpp -o test_parser && ./test_parser

#include <iostream> // I/O
#include <string>   // strings
#include <map>      // map
#include <cctype>   // isalpha(), etc.
#include <initializer_list>

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

// parser

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

// cout for Kind
ostream &operator<<(ostream &os, const Kind &k)
{
    switch (k)
    {
    case Kind::name:
        return os << "Kind::name";
    case Kind::number:
        return os << "Kind::number";
    case Kind::end:
        return os << "Kind::end";
    case Kind::plus:
        return os << "Kind::plus";
    case Kind::minus:
        return os << "Kind::minus";
    case Kind::mul:
        return os << "Kind::mul";
    case Kind::div:
        return os << "Kind::div";
    case Kind::print:
        return os << "Kind::print";
    case Kind::assign:
        return os << "Kind::assign";
    case Kind::lp:
        return os << "Kind::lp";
    case Kind::rp:
        return os << "Kind::rp";
    default:
        return os << "Kind::unknown";
    }
}

struct Token
{
    Kind kind;
    string string_value{""};
    double number_value{0};
    // cout as debug shape: Token{Kind::name, "x", 0} etc
    friend ostream &operator<<(ostream &os, const Token &t)
    {
        return os << "Token{" << t.kind
                  << ", " << t.string_value << ", " << t.number_value << "}";
    }
};

double term(bool);
double expr(bool);
double prim(bool);

class Token_stream
{
public:
    Token_stream(int size, Token *buffer)
        : size{size}, buffer{buffer} {};
    // list constructor
    Token_stream(initializer_list<Token> lst)
        : size{static_cast<int>(lst.size())},
          buffer{new Token[size]}
    {
        copy(lst.begin(), lst.end(), buffer);
    };
    ~Token_stream() { delete[] buffer; };
    Token get()
    {
        if (index < size)
            return buffer[index++];
        return Token{Kind::end};
    };                               // read and return next token
    Token &current() { return ct; }; // most recently read token

private:
    int size;
    int index{0};
    Token *buffer;
    Token ct{Kind::end}; // current token
};

Token_stream ts{Token{Kind::name, "pi", 3.14159},
                Token{Kind::print},
                Token{Kind::end}};

double error(const string &s);

// symbol table
map<string, double> table;

double term(bool get) // multiply and divide
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
            return error("divide by 0");
        default:
            return left;
        }
    }
}

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
        return error("primary expected");
    }
}

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

// input func

bool isnumber(char ch)
{
    return ch >= '0' && ch <= '9';
}

// error handling
int no_of_errors;
double error(const string &s)
{
    no_of_errors++;
    cerr << "error: " << s << '\n';
    return 1;
}

int main(void)
{
}
