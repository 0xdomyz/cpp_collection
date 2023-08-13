// link: https://www.youtube.com/watch?v=kti-KOaJ-74&list=PL0C5825724605DB2A&index=13&ab_channel=Creel

#include "iostream"

using namespace std;

int difficulty = 10;
char input = ' ';
int lowerBound = 0;
int upperBound = difficulty + 1;
int myGuess = 0;
int lastGuess = -1;

bool MainMenu()
{
    cout << "Welcome to Guess Number!" << endl;
    while (true)
    {
        cout << "1. Play" << endl;
        cout << "2. Exit" << endl;
        cout << "> ";
        cin >> input;

        if (input == '1')
        {
            return true;
        }
        else if (input == '2')
        {
            return false;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
}

void ShowStory()
{
    input = ' ';

    cout << "Once upon a time ..." << endl;
}

int main() {}