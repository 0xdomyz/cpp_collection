#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    char x = 'A';
    string charName = "abcdefghijklmn";
    int nbr;
    nbr = 5;
    double nbr2 = 2.3;

    cout << "Hello " << charName << "!" << endl;
    cout << charName.find("def",0) << charName.length() << charName.substr(0,3) << endl;
    cout << charName[0] << endl;

    cout << "Number is " << nbr << endl;
    cout << nbr / 3 << endl;
    cout << pow(2, nbr) << endl;

    return 0;
}


