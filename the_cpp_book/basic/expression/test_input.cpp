// g++ test_input.cpp -o test_input && ./test_input

#include <iostream> // I/O
#include <string>   // strings
#include <map>      // map
#include <cctype>   // isalpha(), etc.
#include <sstream>

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

class Token_stream
{
public:
    Token_stream(istream &s) : ip{&s}, owns{false} {}
    Token_stream(istream *p) : ip{p}, owns{true} {}
    ~Token_stream() { close(); }
    Token get();      // read and return next token
    Token &current(); // most recently read token
    void set_input(istream &s)
    {
        close();
        ip = &s;
        owns = false;
    }
    void set_input(istream *p)
    {
        close();
        ip = p;
        owns = true;
    }

private:
    void close()
    {
        if (owns)
            delete ip;
    }
    istream *ip;         // pointer to an input stream
    bool owns;           // does the Token_stream own the istream?
    Token ct{Kind::end}; // current token
};

Token_stream ts{cin}; // use input from cin

// input func

bool isnumber(char ch)
{
    return ch >= '0' && ch <= '9';
}

double error(const string &s);

Token Token_stream::get()
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
        error("bad number token");
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
        error("bad alpha token");
        return ct = {Kind::print};
    }
}

Token &Token_stream::current()
{
    return ct;
}

// error handling
int no_of_errors;
double error(const string &s)
{
    no_of_errors++;
    cerr << "error: " << s << '\n';
    return 1;
}

// driver

void calculate()
{
    for (;;)
    {
        ts.get();
        cout << ts.current() << '\n';
        if (ts.current().kind == Kind::end)
            break;
        if (ts.current().kind == Kind::print)
            continue;
    }
}

void test_string(string s)
{
    cout << "test_string: " << s << '\n';
    ts.set_input(new istringstream{s});
    calculate();
    cout << endl;
}

int main(void)
{
    test_string("1.2+21.5;-3.0+4.00");
    test_string("pi=3.14; r = 2; area = pi * r * r");
    test_string("16+(3.2-2)*0.4");
    test_string("6+3.2-2*0.4");
    test_string("6+-3.2*-0.5");
}
