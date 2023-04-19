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
    Token_stream(){};
    Token_stream(int size, Token *buffer)
        : size{size}, buffer{buffer} {};
    // copy constructor
    Token_stream(const Token_stream &ts)
    {
        size = ts.size;
        buffer = new Token[size];
        index = ts.index;
        for (int i = 0; i < size; i++)
        {
            buffer[i] = ts.buffer[i];
        }
    }
    // copy assignment
    Token_stream &operator=(const Token_stream &ts)
    {
        if (this != &ts)
        {
            delete[] buffer;
            size = ts.size;
            buffer = new Token[size];
            index = ts.index;
            for (int i = 0; i < size; i++)
            {
                buffer[i] = ts.buffer[i];
            }
        }
        return *this;
    }
    ~Token_stream() { delete[] buffer; };
    Token get()
    {
        if (index < size)
            ct = buffer[index++];
        else
            ct = Token{Kind::end};
        cout << "Token_stream get and update current: " << ct << '\n';
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
    int size{0};
    int index{0};
    Token *buffer;
    Token ct{Kind::end}; // current token
};

Token_stream ts;

double error(const string &s);

// symbol table
map<string, double> table;

int term_count = 0;

double term(bool get) // multiply and divide
{
    int local_count = term_count;
    term_count++;
    string func_sig = "term(" + to_string(get) + ") " + to_string(local_count);

    cout << func_sig << '\n';

    double left = prim(get);
    int i = 0;
    for (;;)
    {
        cout << func_sig << " iteration " << i << '\n';
        i++;
        switch (ts.current().kind)
        {
        case Kind::mul:
            cout << func_sig << " case mul" << '\n';
            left *= prim(true);
            break;
        case Kind::div:
            cout << func_sig << " case div" << '\n';
            if (auto d = prim(true))
            {
                left /= d;
                break;
            }
            return error("divide by 0");
        default:
            cout << func_sig << " case not mul or div, return left: " << left << '\n';
            return left;
        }
    }
}

int prim_count = 0;

double prim(bool get) // handle primar ies
{
    int local_count = prim_count;
    prim_count++;
    string func_sig = "prim(" + to_string(get) + ") " + to_string(local_count);

    cout << func_sig << '\n';

    if (get)
        ts.get(); // read next token

    double result;
    switch (ts.current().kind)
    {
    case Kind::number: // floating-point constant
    {
        cout << func_sig << " case number" << '\n';
        double v = ts.current().number_value;
        ts.get();
        result = v;
        break;
    }
    case Kind::name:
    {
        cout << func_sig << " case name" << '\n';
        string s = ts.current().string_value;
        double &v = table[s]; // find the corresponding
        if (ts.get().kind == Kind::assign)
        {
            cout << func_sig << " case name assign" << '\n';
            v = expr(true); // ’=’ seen: assignment
            cout << func_sig << " case name assign assigned: " << s << " = " << v << '\n';
        }
        result = v;
        break;
    }
    case Kind::minus: // unar y minus
        cout << func_sig << " case minus" << '\n';
        result = -prim(true);
        break;
    case Kind::lp:
    {
        cout << func_sig << " case lp" << '\n';
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
    cout << func_sig << " return: " << result << '\n';
    return result;
}

int expr_count = 0;

double expr(bool get) // add and subtract
{
    int local_count = expr_count;
    expr_count++;
    string func_sig = "expr(" + to_string(get) + ") " + to_string(local_count);

    cout << func_sig << '\n';

    double left = term(get);
    int i = 0;
    for (;;)
    { // ‘‘forever’’
        cout << func_sig << " iteration " << i << '\n';
        i++;
        switch (ts.current().kind)
        {
        case Kind::plus:
            cout << func_sig << " case plus" << '\n';
            left += term(true);
            break;
        case Kind::minus:
            cout << func_sig << " case minus" << '\n';
            left -= term(true);
            break;
        default:
            cout << func_sig << " case not plus or minus, return: " << left << '\n';
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

int calculate_count = 0;

void calculate()
{
    int local_count = calculate_count;
    calculate_count++;
    string func_sig = "calculate " + to_string(local_count);

    cout << func_sig << ts << '\n';

    int i = 0;
    for (;;)
    {
        cout << func_sig << " iteration " << i << '\n';
        i++;

        ts.get();
        cout << func_sig << " check end or print:" << ts.current() << '\n';
        if (ts.current().kind == Kind::end)
            break;
        if (ts.current().kind == Kind::print)
            continue;
        cout << func_sig << " called expr" << '\n';
        cout << expr(false) << '\n';
    }

    cout << endl;
}

int main(void)
{
    ts = Token_stream{6, new Token[6]{
                             Token{Kind::name, "x", 0},
                             Token{Kind::assign},
                             Token{Kind::number, "", 2},
                             Token{Kind::print},
                             Token{Kind::name, "x", 0},
                             Token{Kind::end}}};

    calculate();

    ts = Token_stream{9, new Token[9]{
                             Token{Kind::name, "x", 0},
                             Token{Kind::assign},
                             Token{Kind::number, "", 2},
                             Token{Kind::print},
                             Token{Kind::name, "x", 0},
                             Token{Kind::plus},
                             Token{Kind::number, "", 3},
                             Token{Kind::print},
                             Token{Kind::end}}};
    calculate();

    ts = Token_stream{
        11, new Token[11]{
                Token{Kind::number, "", 16},
                Token{Kind::plus, "", 0},
                Token{Kind::lp, "", 0},
                Token{Kind::number, "", 3.2},
                Token{Kind::minus, "", 0},
                Token{Kind::number, "", 2},
                Token{Kind::rp, "", 0},
                Token{Kind::mul, "", 0},
                Token{Kind::number, "", 0.4},
                Token{Kind::print},
                Token{Kind::end, "", 0},
            }};
    calculate();
}
