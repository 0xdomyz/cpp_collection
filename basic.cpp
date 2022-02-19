#include <iostream>
#include <cmath>

using namespace std;

int func(int var1){
    if (var1 >= 1){
        var1++;
    };
    return var1;
};

int main()
{

    char x = 'A';
    string charName = "abcdefghijklmn";
    int nbr;
    nbr = 5;
    double nbr2 = 2.3;
    int var1, var2;
    int var[] = {1,2,3};

    if(var2 >= var1 && true){
        var2 = 3;
    }else if (var2 ==  3){
        var1 = 1;
    };
    string s1;

    var[2];

    cout << "input:";
    cin >> s1;

    cout << "Hello " << charName << "!" << endl;
    cout << charName.find("def",0) << charName.length() << charName.substr(0,3) << endl;
    cout << charName[0] << endl;

    cout << "Number is " << nbr << endl;
    cout << nbr / 3 << endl;
    cout << pow(2, nbr) << endl;

    return 0;
}


