// g++ echo.cpp -o echo && ./echo hello world && ./echo && ./echo 1 2 3

#include <iostream>

using namespace std;

int main(int number_of_arguments, char **arguments)
{
    // if there are arguments, write them
    if (number_of_arguments > 1)
    {
        int i;                                        // declare i outside the for because we need it after the loop finishes
        for (i = 1; i < number_of_arguments - 1; ++i) // write all but the last entry and a space
            cout << arguments[i] << " ";              // arguments[i] is a char*

        cout << arguments[i] << endl; // write the last entry but not a space
    }
    return 0;
}
