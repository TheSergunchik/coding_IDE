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
    guessResponse.setCorrectResponse(A.checkCorrect(secretCode));
    guessResponse.setIncorrectResponse(A.checkIncorrect(secretCode));
    return guessResponse;
}

bool mastermind::isSolved(const response &A){

}

void mastermind::playGame()
{
    // initializes a random code
    code secretCode = code(codeLength, digitRange);

    printSecretCode();

    // iteratively gets a guess from the user and prints the response until either the codemaker or the codebreaker has won.

}