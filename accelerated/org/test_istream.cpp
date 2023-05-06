// g++ test_istream.cpp -o test_istream && echo "1.4 2 e" | ./test_istream

#include <iostream>

using namespace std;

int main()
{
    double x;
    while (std::cin >> x)
        std::cout << x << std::endl;

    cout << "cin is in error state: " << cin.bad() << endl;
    cout << "cin is in fail state: " << cin.fail() << endl;
    cout << "cin is in eof state: " << cin.eof() << endl;
    cout << "cin is in good state: " << cin.good() << endl;

    cout << "clearing cin" << endl;
    cin.clear();

    cout << "cin is in error state: " << cin.bad() << endl;
    cout << "cin is in fail state: " << cin.fail() << endl;
    cout << "cin is in eof state: " << cin.eof() << endl;
    cout << "cin is in good state: " << cin.good() << endl;

    cout << "cin.peek() = " << cin.peek() << endl;
    char c;
    cin >> c;
    cout << c << endl;

    return 0;
}