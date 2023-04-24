#include <map>
#include <string>
#include <iostream>

using std::istream;
using std::map;
using std::string;

namespace Lexer
{
}
namespace Parser
{
    double expr(bool);

    double prim(bool get);
    double term(bool get);
    double expr(bool);

    using namespace Lexer;
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
        Token_stream(istream &s) : ip{&s}, owns{false}, ct{Kind::end} {}
        Token_stream(istream *p) : ip{p}, owns{true}, ct{Kind::end} {}
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
        Token ct{Kind::end}; // current_token
    };
    extern Token_stream ts;
}

namespace Table
{
    extern map<string, double> table;
}
namespace Error
{
    extern int no_of_errors;
    double error(const string &s);
}
namespace Driver
{
    using Lexer::Kind;
    using Lexer::ts;
    using Parser::expr;
    void calculate();
}