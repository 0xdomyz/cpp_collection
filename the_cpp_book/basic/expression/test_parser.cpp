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
    ~Token_stream() { delete[] buffer; };
    Token get()
    {
        if (index < size)
            ct = buffer[index++];
        else
            ct = Token{Kind::end};
        cout << "Token_stream get: " << ct << '\n';
        return ct;
    }; // read and return next token
    Token &current()
    {
        return ct;
    }; // most recently read token
    // cout by cout buffer in a loop
    friend ostream &operator<<(ostream &os, const Token_stream &ts)
    {
        os << "Token_stream{" << endl;
        for (int i = 0; i < ts.size; i++)
        {
            os << ts.buffer[i] << '\n';
        }
        os << "}" << endl;
        return os;
    }

private:
    int size;
    int index{0};
    Token *buffer;
    Token ct{Kind::end}; // current token
};

Token_stream ts{6, new Token[6]{
                       Token{Kind::name, "x", 0},
                       Token{Kind::assign},
                       Token{Kind::number, "", 2},
                       Token{Kind::print},
                       Token{Kind::name, "x", 0},
                       Token{Kind::end}}};

double error(const string &s);

// symbol table
map<string, double> table;

double term(bool get) // multiply and divide
{
    cout << "term called prim with get: " << get << '\n';
    double left = prim(get);
    for (;;)
    {
        cout << "term switch on :" << ts.current() << '\n';
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
            cout << "term return: " << left << '\n';
            return left;
        }
    }
}

double prim(bool get) // handle primar ies
{
    if (get)
        ts.get(); // read next token

    cout << "prim switch on:" << ts.current() << '\n';
    double result;
    switch (ts.current().kind)
    {
    case Kind::number: // floating-point constant
    {
        double v = ts.current().number_value;
        ts.get();
        result = v;
        break;
    }
    case Kind::name:
    {
        string s = ts.current().string_value;
        double &v = table[s]; // find the corresponding
        if (ts.get().kind == Kind::assign)
        {
            cout << "prim assign call expr with true with curren token: " << ts.current() << '\n';
            v = expr(true); // ’=’ seen: assignment
            cout << "prim assign call expr done, assigned: " << v << " to: " << s << '\n';
        }
        result = v;
        break;
    }
    case Kind::minus: // unar y minus
        cout << "prim minus call prim with true with curren token: " << ts.current() << '\n';
        result = -prim(true);
        break;
    case Kind::lp:
    {
        cout << "prim lp call expr with true with curren token: " << ts.current() << '\n';
        auto e = expr(true);
        if (ts.current().kind != Kind::rp)
            return error("')' expected");
        ts.get(); // eat ’)’
        result = e;
        break;
    }
    default:
        return error("primary expected");
    }
    cout << "prim return: " << result << '\n';
    return result;
}

double expr(bool get) // add and subtract
{
    cout << "expr called term with get: " << get << '\n';
    double left = term(get);
    for (;;)
    { // ‘‘forever’’
        cout << "expr switch on: " << ts.current() << '\n';
        switch (ts.current().kind)
        {
        case Kind::plus:
            left += term(true);
            break;
        case Kind::minus:
            left -= term(true);
            break;
        default:
            cout << "expr return: " << left << '\n';
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

void calculate()
{
    cout << "calculate:" << ts << '\n';
    cout << endl;

    for (;;)
    {
        ts.get();
        cout << "calculate check end or print:" << ts.current() << '\n';
        if (ts.current().kind == Kind::end)
            break;
        if (ts.current().kind == Kind::print)
            continue;
        cout << "calculate called expr with current being:" << ts.current() << '\n';
        cout << expr(false) << '\n';
    }
}

int main(void)
{
    calculate();

    // ts = Token_stream{9, new Token[9]{
    //                          Token{Kind::name, "x", 0},
    //                          Token{Kind::assign},
    //                          Token{Kind::number, "", 2},
    //                          Token{Kind::print},
    //                          Token{Kind::name, "x", 0},
    //                          Token{Kind::plus},
    //                          Token{Kind::number, "", 3},
    //                          Token{Kind::print},
    //                          Token{Kind::end}}};
    // calculate();

    // ts = Token_stream{
    //     13, new Token[13]{
    //             Token{Kind::number, "", 16},
    //             Token{Kind::plus, "", 0},
    //             Token{Kind::lp, "", 0},
    //             Token{Kind::number, "", 3.2},
    //             Token{Kind::minus, "", 0},
    //             Token{Kind::number, "", 2},
    //             Token{Kind::rp, "", 0},
    //             Token{Kind::mul, "", 0},
    //             Token{Kind::number, "", 0.4},
    //             Token{Kind::end, "", 0},
    //         }};
    // calculate();
}
