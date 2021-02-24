/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains code class and all necessary functions (checkCorrect, checkIncorrect).
 * Implements code class to run a game of Mastermind.
 */

#include <iostream>
#include <vector>
#include <time.h>
#include "code.h"
#include "mastermind.h"
using namespace std;

//test

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

    // If both code length and range are successfully established, creates two code class objects. One is the
    // secret code, another is the guess code.
    code secret = code(codeLength, digitRange);
    code guess = code(codeLength, digitRange);

    do{ //Starts the 10 attempts.
        cout << endl << "-- Attempt #" << attempts << " --" << endl << endl;

        // Resets the guess vector to get rid of automatically assigned random code. Then prompts user to enter elements
        // to populate the vector.
        guess.resetVector();
        guess.enterElements();

        // Prints both secret and guess code for grading purposes.
        cout << endl << "SECRET CODE:  ";
        secret.printVector();
        cout << "GUESS CODE:   ";
        guess.printVector();
        cout << "-------------------" << endl;
        cout << "Correct Digits:   " << secret.checkCorrect(guess) << endl;
        cout << "Misplaced Digits: " << secret.checkIncorrect(guess) << endl;

        //Checks to see if all the digits are in all the correct spots. If so, the code is successfully guessed!
        if(secret.checkCorrect(guess) == codeLength)
        {
            solutionFound = true;
        }

        attempts++;
    } while (((attempts <= 10) && (!solutionFound)));

    cout << endl << "-- GAME FINISHED --" << endl;

    // Provides two options: one where the game maker wins and one where the game breaker wins, depending if the
    // game breaker guessed the code in 10 attempts or less.
    if(solutionFound)
    {
        cout << "The code breaker wins!" << endl << "The code was: ";
        secret.printVector();
    } else
    {
        cout << "The code maker wins!" << endl << "The code was: ";
        secret.printVector();
    }
    
    //create new mastermind object
    mastermind M = mastermind(codeLength, digitRange);
    
    //runs game
    M.playGame();

    return 0;
} // End of main.
