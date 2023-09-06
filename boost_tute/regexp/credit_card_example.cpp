// g++ -I /usr/local/boost_1_82_0 -o credit_card_example credit_card_example.cpp /usr/local/lib/libboost_regex.a && ./credit_card_example

#include <boost/regex.hpp>
#include <string>

bool validate_card_format(const std::string &s)
{
    // 4 groups of 4 digits separated by spaces or dashes.
    static const boost::regex e("(\\d{4}[- ]){3}\\d{4}");
    return boost::regex_match(s, e);
}

// 3 digits, followed by 3 groups of 4 digits, separated by spaces or dashes.
const boost::regex e("\\A(\\d{3,4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})\\z");
// capture groups
const std::string machine_format("\\1\\2\\3\\4");
const std::string human_format("\\1-\\2-\\3-\\4");

std::string machine_readable_card_number(const std::string &s)
{
    return boost::regex_replace(s, e, machine_format);
}

std::string human_readable_card_number(const std::string &s)
{
    return boost::regex_replace(s, e, human_format, boost::match_default | boost::format_sed);
    // format_sed allows unix sed-style replacement strings, for example:
    // return boost::regex_replace(s, e, "&", boost::match_default | boost::format_sed);
}

#include <iostream>
using namespace std;

int main()
{
    string s[4] = {
        "0000111122223333",
        "0000 1111 2222 3333",
        "0000-1111-2222-3333",
        "000-1111-2222-3333",
    };

    int i;

    for (i = 0; i < 4; ++i)
    {
        cout << "validate_card_format(\"" << s[i] << "\") returned " << validate_card_format(s[i]) << endl;
    }
    cout << endl;

    for (i = 0; i < 4; ++i)
    {
        cout << "machine_readable_card_number(\"" << s[i] << "\") returned " << machine_readable_card_number(s[i]) << endl;
    }
    cout << endl;

    for (i = 0; i < 4; ++i)
    {
        cout << "human_readable_card_number(\"" << s[i] << "\") returned " << human_readable_card_number(s[i]) << endl;
    }
    cout << endl;

    return 0;
}
