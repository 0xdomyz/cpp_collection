#include "dc.h"
#include <cctype>
#include <iostream> // redundant: in dc.h

Lexer::Token_stream Lexer::ts{std::cin};

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
