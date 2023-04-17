// g++ test_input.cpp -o test_input && ./test_input

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

struct Token
{
    Kind kind;
    string string_value;
    double number_value;
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

int main(void)
{
}
