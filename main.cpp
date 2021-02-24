/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains code class and all necessary functions (checkCorrect, checkIncorrect).
 * Implements code class to run a game of Mastermind.
 */

#include <iostream>
#include "code.h"
#include "mastermind.h"
using namespace std;

int main()
{
    int codeLength = 0, digitRange = 0, attempts = 1;
    bool solutionFound = false;

    cout << "Enter code length:";
    cin >> codeLength;

    while (!cin || codeLength <= 0)
    // If user inputs a non-integer or integer less than 0, clears input and asks again.
    {
        cin.clear();
        cin.ignore();
        cout << "Enter code length:";
        cin >> codeLength;
    }

    do
    // If user inputs a non-integer or integer less than 0, clears input and asks again.
    {
        cin.clear();
        cin.ignore();
        cout << "Enter digit range (including 0):";
        cin >> digitRange;
    }while (!cin || digitRange <= 0);

    //create new mastermind object
    mastermind M = mastermind(codeLength, digitRange);
    
    //runs game
    M.playGame();

    return 0;
} // End of main.
