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

void mastermind::getSecretCode(const int input) {

}

code mastermind::humanGuess() {

}

response mastermind::getResponse(const code &A){

}

bool mastermind::isSolved(const response &A){

}

void mastermind::playGame()
{
    // initializes a random code
    code secret = code(codeLength, digitRange);

    // prints it to the screen
    cout << endl << "SECRET CODE:  ";
    secret.printVector();

    // iteratively gets a guess from the user and prints the response until either the codemaker or the codebreaker has won.

}