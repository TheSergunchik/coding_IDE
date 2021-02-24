/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 1, Part B
 * Contains code class and all necessary functions (checkCorrect, checkIncorrect).
 * Implements code class to run a game of Mastermind.
 */

#include "mastermind.h"

mastermind::mastermind(int n, int m) {
    codeLength = n;
    digitRange = m;
    code guess = code(codeLength, digitRange);

}

mastermind::mastermind()
// default values for = 5 and m= 10
{
    codeLength = 5;
    digitRange = 10;
    code guess = code(codeLength, digitRange);
}

void mastermind::printSecretCode() {
    // prints it to the screen
    cout << endl << "SECRET CODE:  ";
    secretCode.printVector();
}

code mastermind::humanGuess()
//Reads a guess from the keyboard and returns a code object that represents the guess
{
    code guess = code(codeLength, digitRange);
    guess.resetVector();
    guess.enterElements();
    return guess;
}

response mastermind::getResponse(const code &A)
//that is passed one code (a guess code), and returns a response
{
    response guessResponse = response();
    guessResponse.setCorrectResponse(secretCode.checkCorrect(A));
    guessResponse.setIncorrectResponse(secretCode.checkIncorrect(A));
    return guessResponse;
}

bool mastermind::isSolved(const response &A)
//passed a response and returns true if the response indicates the code is solved
{
    return (A.getCorrectResponse() == codeLength && A.getIncorrectResponse() == 0);
}

void mastermind::playGame()
{
    // initializes a random code
    secretCode = code(codeLength, digitRange);
    printSecretCode();

    // If both code length and range are successfully established, creates two code class objects. One is the
    // secret code, another is the guess code.
    code secret = code(codeLength, digitRange);
    code guess = code(codeLength, digitRange);

    int attempts = 1;
    bool endGame = false;

    do{ //Starts the 10 attempts.
        cout << endl << "-- Attempt #" << attempts << " --" << endl << endl;

        guess = humanGuess();

        // Prints both secret and guess code for grading purposes.
        cout << endl << "SECRET CODE:  ";
        secret.printVector();
        cout << "GUESS CODE:   ";
        guess.printVector();
        cout << "-------------------" << endl;
        cout << "Correct Digits:   " << getResponse(guess).getCorrectResponse() << endl;
        cout << "Misplaced Digits: " << getResponse(guess).getIncorrectResponse() << endl;

        //Checks to see if all the digits are in all the correct spots. If so, the code is successfully guessed!
        endGame = isSolved(getResponse(guess));

        attempts++;
    } while (((attempts <= 10) && (!endGame)));

    cout << endl << "-- GAME FINISHED --" << endl;

    // Provides two options: one where the game maker wins and one where the game breaker wins, depending if the
    // game breaker guessed the code in 10 attempts or less.
    if(endGame)
    {
        cout << "The code breaker wins!" << endl << "The code was: ";
        secret.printVector();
    } else
    {
        cout << "The code maker wins!" << endl << "The code was: ";
        secret.printVector();
    }


    // iteratively gets a guess from the user and prints the response until either the codemaker or the codebreaker has won.

}
