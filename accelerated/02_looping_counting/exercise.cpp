// g++ exercise.cpp -o exercise && ./exercise

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    const int size = 5;

    // print a sqaure
    for (int i = 0; i < size; i++)
    {
        cout << string(size, '*') << endl;
    }
    cout << endl;

    // print square with empty center
    for (int i = 0; i < size; i++)
    {
        if (i == 0 || i == size - 1)
        {
            cout << string(size, '*') << endl;
        }
        else
        {
            cout << "*" << string(size - 2, ' ') << "*" << endl;
        }
    }
    cout << endl;

    // print rectangle
    const int length = 10;
    const int width = 5;

    for (int i = 0; i < width; i++)
    {
        cout << string(length, '*') << endl;
    }
    cout << endl;

    // rectangle with empty center
    for (int i = 0; i < width; i++)
    {
        if (i == 0 || i == width - 1)
        {
            cout << string(length, '*') << endl;
        }
        else
        {
            cout << "*" << string(length - 2, ' ') << "*" << endl;
        }
    }
    cout << endl;

    // triangle
    const int height = 5;

    for (int i = 0; i < height; i++)
    {
        cout << string(i + 1, '*') << endl;
    }
    cout << endl;

    // equal waist triangle
    const int height2 = 4;
    const int width2 = height2 * 2 - 1;
    const int mid = height2;

    for (int r = 0; r < height2; ++r)
    {
        for (int c = 0; c < width2; ++c)
        {
            // write star if mid - 1 - r cols written, up to mid + r -1 cols written
            if (c >= mid - 1 - r && c <= mid + r - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    cout << endl;

    // 1 to 10
    int i = 0;
    while (i < 10)
    {
        i += 1;
        std::cout << i << std::endl;
    }

    cout << endl;

    // 10 to -5
    for (int i = 10; i > -6; i--)
    {
        cout << i << endl;
    }
    cout << endl;

    // 9 factorial
    int result = 1;
    for (int i = 1; i < 10; i++)
    {
        result *= i;
    }

    cout << result << endl;

    // ask for 2 numbers, tell which one is bigger
    int num1, num2;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter another number: ";
    cin >> num2;

    if (num1 > num2)
    {
        cout << num1 << " is bigger than " << num2 << endl;
    }
    else if (num1 < num2)
    {
        cout << num2 << " is bigger than " << num1 << endl;
    }
    else
    {
        cout << num1 << " is equal to " << num2 << endl;
    }
}