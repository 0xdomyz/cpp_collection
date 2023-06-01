// g++ -I /usr/local/boost_1_82_0 -o intro intro.cpp /usr/local/lib/libboost_regex.a && ./intro

#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace std;

bool validate_card_format(const std::string &s)
{
    static const boost::regex e("(\\d{4}[- ]){3}\\d{4}");
    return regex_match(s, e);
}

int main()
{
    {
        string card1 = "1234 5678 1234 5678";
        string card2 = "1234 5678 1234 567a";

        cout << "card1: " << card1 << " is "
             << (validate_card_format(card1) ? "valid" : "invalid") << endl;
        cout << "card2: " << card2 << " is "
             << (validate_card_format(card2) ? "valid" : "invalid") << endl;
    }
}